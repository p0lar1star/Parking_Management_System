/********************************************************************************
** Form generated from reading UI file 'Widget.ui'
**
** Created: Fri Dec 17 08:34:13 2021
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout;
    QPlainTextEdit *plainTextEdit;
    QLabel *label_2;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_status;
    QGridLayout *gridLayout_3;
    QLabel *label_3;
    QLineEdit *lineEdit_current;
    QGridLayout *gridLayout_4;
    QLabel *label_4;
    QLineEdit *lineEdit_consume;
    QGridLayout *gridLayout_5;
    QLabel *label_5;
    QLineEdit *lineEdit_remaining;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLineEdit *lineEdit;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(603, 213);
        gridLayout_7 = new QGridLayout(Widget);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QString::fromUtf8("plainTextEdit"));

        gridLayout->addWidget(plainTextEdit, 1, 1, 1, 2);

        label_2 = new QLabel(Widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 1, 1, 1);


        gridLayout_7->addLayout(gridLayout, 0, 0, 1, 3);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(Widget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        lineEdit_status = new QLineEdit(Widget);
        lineEdit_status->setObjectName(QString::fromUtf8("lineEdit_status"));

        gridLayout_2->addWidget(lineEdit_status, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_2, 0, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_3 = new QLabel(Widget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout_3->addWidget(label_3, 0, 0, 1, 1);

        lineEdit_current = new QLineEdit(Widget);
        lineEdit_current->setObjectName(QString::fromUtf8("lineEdit_current"));

        gridLayout_3->addWidget(lineEdit_current, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_3, 1, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_4 = new QLabel(Widget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_4->addWidget(label_4, 0, 0, 1, 1);

        lineEdit_consume = new QLineEdit(Widget);
        lineEdit_consume->setObjectName(QString::fromUtf8("lineEdit_consume"));

        gridLayout_4->addWidget(lineEdit_consume, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_4, 2, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_5 = new QLabel(Widget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_5->addWidget(label_5, 0, 0, 1, 1);

        lineEdit_remaining = new QLineEdit(Widget);
        lineEdit_remaining->setObjectName(QString::fromUtf8("lineEdit_remaining"));

        gridLayout_5->addWidget(lineEdit_remaining, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 3, 0, 1, 1);


        gridLayout_7->addLayout(gridLayout_6, 0, 3, 1, 1);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));

        gridLayout_7->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout_7->addWidget(pushButton_2, 1, 1, 1, 1);

        lineEdit = new QLineEdit(Widget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setMaxLength(8);

        gridLayout_7->addWidget(lineEdit, 1, 2, 1, 2);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Widget", "\345\215\241\347\211\207\345\244\204\347\220\206\347\212\266\346\200\201", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Widget", "\350\275\246\350\276\206\347\212\266\346\200\201\357\274\232", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("Widget", "\345\275\223\345\211\215\344\275\231\351\242\235\357\274\232", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("Widget", "\346\234\254\346\254\241\346\266\210\350\264\271\357\274\232", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("Widget", "\345\211\251\344\275\231\351\207\221\351\242\235\357\274\232", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("Widget", "\346\211\253\346\217\217\345\215\241\347\211\207", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("Widget", "\345\205\205\345\200\274", 0, QApplication::UnicodeUTF8));
        lineEdit->setText(QApplication::translate("Widget", "0", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
