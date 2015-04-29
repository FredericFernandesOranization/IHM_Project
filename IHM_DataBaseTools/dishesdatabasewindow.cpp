#include "dishesdatabasewindow.h"
#include "ui_dishesdatabasewindow.h"

DishesDataBaseWindow::DishesDataBaseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DishesDataBaseWindow)
{
    ui->setupUi(this);
}

DishesDataBaseWindow::~DishesDataBaseWindow()
{
    delete ui;
}
