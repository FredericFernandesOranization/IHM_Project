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
    flowlayout.cpp \
    menubutton.cpp \
    imagelabel.cpp \
    gallerieslayout.cpp \
    detaileditem.cpp \
    backbutton.cpp \
    leftbarlayout.cpp \
    confirmdialog.cpp \
    uppermenu.cpp \
    commande.cpp \
    orderitem.cpp \
    commanderbutton.cpp \
    dialoglang.cpp
    imagelabel.cpp

HEADERS  += mainwindow.h \
    plat.h \
    database.h \
    item.h \
    leftzone.h \
    rightzone.h \
    gallery.h \
    flowlayout.h \
    menubutton.h \
    imagelabel.h \
    gallerieslayout.h \
    detaileditem.h \
    backbutton.h \
    leftbarlayout.h \
    confirmdialog.h \
    uppermenu.h \
    commande.h \
    orderitem.h \
    commanderbutton.h \
    dialoglang.h
    imagelabel.h

FORMS    += mainwindow.ui \
    confirmdialog.ui \
    dialoglang.ui

OTHER_FILES += \
    replats.xml

RESOURCES += \
    images.qrc
