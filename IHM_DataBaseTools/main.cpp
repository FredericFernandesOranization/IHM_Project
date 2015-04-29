#include "mainwindow.h"
#include <QApplication>
#include "allergiedatabasewindow.h"
#include "editallergiewindow.h"
#include "editingredientwindow.h"
#include "ingredientdatabasewindow.h"
#include "database.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
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
