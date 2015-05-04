#include "editallergiewindow.h"
#include "ui_editallergiewindow.h"

EditAllergieWindow::EditAllergieWindow(QListWidgetItem *item,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditAllergieWindow)
{
    ui->setupUi(this);
    this->dataBase = Database::getInstance();
    QVariant qv = item->data(Qt::UserRole);
    this->plat = qv.value<Plat>();
    this->item = item;
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(80,142,150)));
    updateUi();
}

EditAllergieWindow::~EditAllergieWindow(){
    delete ui;
}

void EditAllergieWindow::updateUi(){
    dataBase->loadAllergies();
    ui->listAllDataBase->clear();
    ui->listAllProd->clear();
    ui->listAllDataBase->addItems(dataBase->getClientAllergiesList());
    ui->listAllProd->addItems(plat.getPossibleAllergiesList());

}

void EditAllergieWindow::closeEvent(QCloseEvent *)
{
    QStringList list = ui->listAllProd->getStrings();
    plat.setPossibleAllergiesList(list);

    QVariant qv;
    qv.setValue(plat);
    this->item->setData(Qt::UserRole,qv);
}
