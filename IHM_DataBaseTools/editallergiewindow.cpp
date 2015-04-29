#include "editallergiewindow.h"
#include "ui_editallergiewindow.h"

EditAllergieWindow::EditAllergieWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditAllergieWindow)
{
    ui->setupUi(this);
    this->dataBase = Database::getInstance();
    updateUi();
}

EditAllergieWindow::~EditAllergieWindow()
{
    delete ui;
}

void EditAllergieWindow::updateUi()
{
    ui->listAllDataBase->clear();
    ui->listAllProd->clear();
    ui->listAllDataBase->addItems(dataBase->getClientAllergiesList());

}
