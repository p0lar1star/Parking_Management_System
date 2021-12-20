#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class IEEE14443Control;
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void onCardError(int cmdType, const QString &result);
    void onFoundCard(const QByteArray &cardid);
    void onWalletCharged(int block);
    void onWalletReCharged(int block);
    void on_pushButton_clicked();
    void onReadCard(int block,const QByteArray &data);
    void onWrittenCard(int block);
    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    IEEE14443Control *rfidCtrller;
    int reChargeStatus;
    QByteArray statusBuf;
    QByteArray moneyBuf;
    qint16 moneyConsume;
    void walletGet(int mon);
};

#endif // WIDGET_H
