#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(80,142,150)));
    ingrWindows = new IngredientDataBaseWindow(this);
    ingrWindows->setModal(true);

    allergieWindows = new AllergieDataBaseWindow(this);
    allergieWindows->setModal(true);

    dishesWindows = new DishesDataBaseWindow(this);
    dishesWindows->setModal(true);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnLesPlats_clicked()
{
   dishesWindows->show();
}

void MainWindow::on_btnIngr_clicked()
{
    ingrWindows->show();
}

void MainWindow::on_btnAlle_clicked()
{
    allergieWindows->show();
}
