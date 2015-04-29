#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ingrWindows = new IngredientDataBaseWindow(this);
    ingrWindows->setModal(true);
    allergieWindows = new AllergieDataBaseWindow(this);
    allergieWindows->setModal(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnLesPlats_clicked()
{
    qDebug()<<"test";
}

void MainWindow::on_btnIngr_clicked()
{
    ingrWindows->setModal(true);
    ingrWindows->show();
}

void MainWindow::on_btnAlle_clicked()
{

    allergieWindows->setModal(true);
    allergieWindows->show();
}
