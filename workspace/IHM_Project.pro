#-------------------------------------------------
#
# Project created by QtCreator 2015-03-25T22:46:18
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IHM_Project
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    test.cpp \
    tsrt.cpp \
    plat.cpp \
    database.cpp

HEADERS  += mainwindow.h \
    test.h \
    tsrt.h \
    plat.h \
    database.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc
