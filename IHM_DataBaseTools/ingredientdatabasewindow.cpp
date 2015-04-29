#include "ingredientdatabasewindow.h"
#include "ui_ingredientdatabasewindow.h"

IngredientDataBaseWindow::IngredientDataBaseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IngredientDataBaseWindow)
{
    ui->setupUi(this);
}

IngredientDataBaseWindow::~IngredientDataBaseWindow()
{
    delete ui;
}
