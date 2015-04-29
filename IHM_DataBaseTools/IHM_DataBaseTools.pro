#-------------------------------------------------
#
# Project created by QtCreator 2015-04-27T19:01:31
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IHM_DataBaseTools
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    editallergiewindow.cpp \
    editingredientwindow.cpp \
    allergiedatabasewindow.cpp \
    ingredientdatabasewindow.cpp \
    plat.cpp \
    listwidget.cpp \
    database.cpp \
    dishesdatabasewindow.cpp

HEADERS  += mainwindow.h \
    editallergiewindow.h \
    editingredientwindow.h \
    allergiedatabasewindow.h \
    ingredientdatabasewindow.h \
    plat.h \
    listwidget.h \
    database.h \
    dishesdatabasewindow.h

FORMS    += mainwindow.ui \
    editallergiewindow.ui \
    editingredientwindow.ui \
    allergiedatabasewindow.ui \
    ingredientdatabasewindow.ui \
    dishesdatabasewindow.ui
