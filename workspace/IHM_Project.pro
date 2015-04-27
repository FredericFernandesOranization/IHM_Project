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


SOURCES += Sources/main.cpp\
        Sources/mainwindow.cpp \
    Sources/plat.cpp \
    Sources/database.cpp \
    Sources/item.cpp \
    Sources/leftzone.cpp \
    Sources/rightzone.cpp \
    Sources/gallery.cpp \
    Sources/flowlayout.cpp \
    #Sources/menubutton.cpp

HEADERS  += Headers/mainwindow.h \
    Headers/plat.h \
    Headers/database.h \
    Headers/item.h \
    Headers/leftzone.h \
    Headers/rightzone.h \
    Headers/gallery.h \
    Headers/flowlayout.h \
    #Headers/menubutton.h

FORMS    += mainwindow.ui

OTHER_FILES += \
    resources/plats.xml
