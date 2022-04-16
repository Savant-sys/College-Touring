QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Campus.cpp \
    Database.cpp \
    adminwindow.cpp \
    campusWidget.cpp \
    listOfCampus.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    trip.cpp

HEADERS += \
    Campus.h \
    Database.h \
    adminwindow.h \
    campusWidget.h \
    listOfCampus.h \
    login.h \
    mainwindow.h \
    trip.h

FORMS += \
    adminwindow.ui \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
