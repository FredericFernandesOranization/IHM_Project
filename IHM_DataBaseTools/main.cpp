#include "mainwindow.h"
#include <QApplication>
#include "allergiedatabasewindow.h"
#include "ingredientdatabasewindow.h"
#include "database.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    a.setStyleSheet("QPushButton {font-family: Arial,sans-serif;font: bold;width: 200px;height: 43px;padding-top: 7px;text-align: center;color: #000;background: rgb(255,158,65);border-radius: 8px;}");
    w.show();

//    AllergieDataBaseWindow al;
//    al.show();

//    EditAllergieWindow e;
//    e.show();

//    EditIngredientWindow eA;
//    eA.show();

//    IngredientDataBaseWindow I;
//    I.show();
    //Database::getInstance();

    return a.exec();
}
