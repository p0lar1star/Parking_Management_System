#-------------------------------------------------
#
# Project created by QtCreator 2014-01-07T16:57:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Parking
TEMPLATE = app

INCLUDEPATH += \
    ../Parking/qextserialport/include \
    ../Parking/QRFID

LIBS += \
    -L../Parking/qextserialport/lib

unix {
    LIBS += -lqextserialport
} else:win32 {
    CONFIG(debug, debug|release){
        LIBS += -lqextserialportd1
    }else{
        LIBS += -lqextserialport1
    }
}


SOURCES += main.cpp\
        Widget.cpp \
    QRFID/ChannelMan/RFIDChannelMan.cpp \
    QRFID/IEEE14443/IEEE14443Package.cpp \
    QRFID/IEEE14443/IEEE14443Control.cpp

HEADERS  += Widget.h \
    QRFID/ChannelMan/RFIDChannelMan.h \
    QRFID/IEEE14443/IEEE14443Package.h \
    QRFID/IEEE14443/IEEE14443Control.h

FORMS    += Widget.ui

linux-* {
    target.path = /root
    INSTALLS += target
}
