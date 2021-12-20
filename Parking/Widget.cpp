#include "Widget.h"
#include "ui_Widget.h"
#include "QRFID/IEEE14443/IEEE14443Control.h"
#include "QRFID/ChannelMan/RFIDChannelMan.h"
#include <QDebug>
#include <QTime>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    reChargeStatus = 0;
    // 创建RFID控制器
    rfidCtrller = new IEEE14443Control(this);
    // 关联RFID控制器的信号
    connect(rfidCtrller, SIGNAL(error(int,QString)), this, SLOT(onCardError(int,QString)));
    connect(rfidCtrller, SIGNAL(foundCard(QByteArray)), this, SLOT(onFoundCard(QByteArray)));
    connect(rfidCtrller, SIGNAL(walletCharged(int)),this,SLOT(onWalletCharged(int)));
    connect(rfidCtrller, SIGNAL(walletRecharged(int)),this,SLOT(onWalletReCharged(int)));
    connect(rfidCtrller, SIGNAL(dataReaded(int,QByteArray)),this,SLOT(onReadCard(int,QByteArray)));
    connect(rfidCtrller, SIGNAL(dataWritten(int)),this,SLOT(onWrittenCard(int)));

#ifndef _WIN32
    // 选择13.56M通道
    RFIDChannelMan::setChannel(RFIDChannelMan::ChannelIEEE14443);
    // 打开13.56M读写器
    rfidCtrller->start(RFIDChannelMan::getRfidPort());
#else
    rfidCtrller->start("COM1");
#endif
}

Widget::~Widget()
{
    delete rfidCtrller;
    delete ui;
}

//读卡失败，进行的操作
void Widget::onCardError(int cmdType, const QString &result)
{
    if(cmdType == IEEE14443Control::GetCardId){
        // 没有扫描到卡,继续扫描
        // ui->plainTextEdit->appendPlainText("Reading card Failed! Trying again...");
        rfidCtrller->getCardId();
    }
    else{
        ui->plainTextEdit->appendPlainText(result);
    }
}

//发现了卡，要执行的操作
void Widget::onFoundCard(const QByteArray &cardid)
{
    // 扫描到卡
    ui->plainTextEdit->appendPlainText("Card Found! The Card id:"+cardid.toHex());
    // ui->plainTextEdit->appendPlainText("Remained money:"+QString::number(rfidCtrller->getWallet()));
    // ui->lineEdit_remaining->setText(QString::number(rfidCtrller->getWallet()));
    rfidCtrller->readCard(2);
}

//读卡操作完成后要进行的操作
void Widget::onReadCard(int block, const QByteArray &data)
{
    statusBuf.resize(16);
    char *buf = statusBuf.data();
    int *mbuf = (int *)statusBuf.data();
    //下标0位置表示当前车辆状态，为0表示还没有进入停车场，为1表示已进入停车场
    //下标1位置表示进入停车场时的时间，出停车场后清零
    buf[0] = data.at(0);
    buf[1] = data.at(1);
    //卡中金额
    mbuf[1] = (int)data.at(4);
    rfidCtrller->setWallet((int)data.at(4));
    //是否要充值
    if(reChargeStatus)
    {
        reChargeStatus = 0;
        //更改本地的金额
        rfidCtrller->walletRecharge(ui->lineEdit->text().toInt(0,10));
        //更改卡中金额
        ui->plainTextEdit->appendPlainText("Before wallet money is:"+QString::number(mbuf[1]));
        mbuf[1] += ui->lineEdit->text().toInt(0,10);
        rfidCtrller->writeCard(2, statusBuf);
        ui->plainTextEdit->appendPlainText("Now wallet money is:"+QString::number(mbuf[1]));
        ui->lineEdit_remaining->setText(QString::number(rfidCtrller->getWallet()));
    }
    else //不需要充值
    {
        QDateTime d = QDateTime::currentDateTime();
        //车辆从外进入停车场时，记录当前时间
        if(buf[0] == 0)
        {
            buf[1] = d.time().second();
        }
        else  //车辆从内驶出停车场时计算当前消费,同时时间字节清零
        {
            moneyConsume = ((d.time().second())- buf[1]) * 1;
            if(moneyConsume <= 0)
                moneyConsume += 60;
            buf[1] = 0;
        }
        //不管进还是出，都更新钱包状态
        Widget::walletGet(1);
    }
}

//更新钱包状态
void Widget::walletGet(int money)
{
    money = rfidCtrller->getWallet();
    ui->plainTextEdit->appendPlainText("wallet money is:"+QString::number(money));
    char *buf = statusBuf.data();
    int *mbuf = (int *)statusBuf.data();
    //进入停车场
    if(buf[0] == 0)
    {
        //当前余额
        ui->lineEdit_current->setText(QString::number(money));
        //本次消费
        ui->lineEdit_consume->clear();
        //剩余金额，进入的时候这里不显示
        ui->lineEdit_remaining->clear();
        //车辆状态显示
        ui->lineEdit_status->setText("Drive into the park!");
        //写卡，车辆状态改变
        buf[0] = 1;
        mbuf[1] = money;
        rfidCtrller->writeCard(2,statusBuf);
    }
    //出停车场
    else
    {
        //当前余额
        ui->lineEdit_current->setText(QString::number(money));
        //本次消费
        ui->lineEdit_consume->setText(QString::number(moneyConsume));
        ui->lineEdit_status->setText("Drive out of the park!");
        if(moneyConsume <= money) {
            // 更新本地金额
            rfidCtrller->walletCharge(moneyConsume);
            // 写入状态
            buf[0] = 0;
            mbuf[1] = money - moneyConsume;
            rfidCtrller->writeCard(2,statusBuf);
            ui->lineEdit_remaining->setText(QString::number(rfidCtrller->getWallet()));
        }
        else {
            ui->plainTextEdit->appendPlainText("Consume Error! Please recharge!");
            ui->lineEdit_remaining->setText("Error!");
        }
    }
}


void Widget::onWrittenCard(int block)
{
    ui->plainTextEdit->appendPlainText("Data Written!");
}

void Widget::onWalletReCharged(int block)
{
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText("Recharge success!");
    //车辆状态
    ui->lineEdit_status->clear();
    //当前余额
    ui->lineEdit_current->clear();
    //本次消费
    ui->lineEdit_consume->clear();
    //剩余金额
    ui->lineEdit_remaining->setText(QString::number(rfidCtrller->getWallet()));
}

void Widget::onWalletCharged(int block)
{
    ui->plainTextEdit->appendPlainText("Charge success!");
    char *buf = statusBuf.data();
    buf[0] = 0;
    rfidCtrller->writeCard(2,statusBuf);
    ui->lineEdit_remaining->setText(QString::number(rfidCtrller->getWallet()));
}

//点击开始扫卡按钮
void Widget::on_pushButton_clicked()
{
    // 启动扫描卡的过程
    ui->plainTextEdit->clear();
    ui->plainTextEdit->appendPlainText("Scanning card...");
    rfidCtrller->getCardId();
}

//点击充值按钮
void Widget::on_pushButton_2_clicked()
{
    ui->plainTextEdit->appendPlainText("Scanning card...");
    reChargeStatus = 1;
    rfidCtrller->getCardId();
}
