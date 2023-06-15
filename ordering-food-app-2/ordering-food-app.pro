QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    dbmanager.cpp \
    main.cpp \

    mainwindow.cpp
    dbManager.cpp

HEADERS += \
    dbmanager.h \
    mainwindow.h
    dbManager.h

    mainwindow.cpp \
    produkt.cpp

HEADERS += \
    mainwindow.h \
    produkt.h


FORMS += \
    mainwindow.ui \
    produkt.ui

RESOURCES += \
    resource.qrc


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
