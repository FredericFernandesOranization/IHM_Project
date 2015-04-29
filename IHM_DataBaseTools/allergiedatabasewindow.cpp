#include "allergiedatabasewindow.h"
#include "ui_allergiedatabasewindow.h"

AllergieDataBaseWindow::AllergieDataBaseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AllergieDataBaseWindow)
{
    ui->setupUi(this);
}

AllergieDataBaseWindow::~AllergieDataBaseWindow()
{
    delete ui;
}
