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
    plat.cpp \
    database.cpp \
    item.cpp \
    leftzone.cpp \
    rightzone.cpp \
    gallery.cpp \
    flowlayout.cpp

HEADERS  += mainwindow.h \
    plat.h \
    database.h \
    item.h \
    leftzone.h \
    rightzone.h \
    gallery.h \
    flowlayout.h

FORMS    += mainwindow.ui

RESOURCES += \
    images.qrc

OTHER_FILES += \
    resources/plats.xml
