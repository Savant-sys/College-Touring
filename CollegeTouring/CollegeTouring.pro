QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    allfromsaddleback.cpp \
    campus.cpp \
    campus_widget.cpp \
    database.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    menuwidget.cpp

HEADERS += \
    allfromsaddleback.h \
    campus.h \
    campus_widget.h \
    database.h \
    login.h \
    mainwindow.h \
    map.h \
    menuwidget.h

FORMS += \
    allfromsaddleback.ui \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
