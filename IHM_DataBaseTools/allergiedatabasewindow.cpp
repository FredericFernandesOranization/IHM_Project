#include "allergiedatabasewindow.h"
#include "ui_allergiedatabasewindow.h"
AllergieDataBaseWindow::AllergieDataBaseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AllergieDataBaseWindow)
{
    ui->setupUi(this);
    this->dataBase = Database::getInstance();
    updateUi();
}

AllergieDataBaseWindow::~AllergieDataBaseWindow()
{
    delete ui;
}

void AllergieDataBaseWindow::on_btnAddAllergie_clicked()
{
    QString txt = ui->lineEditNameAllergie->text().simplified();
    ui->listAllergiesDataBase->myAddIten(txt);
}

void AllergieDataBaseWindow::updateUi(){   
    ui->listAllergiesDataBase->clear();
    ui->lineEditNameAllergie->clear();
    ui->listAllergiesDataBase->addItems(dataBase->getClientAllergiesList());
}

void AllergieDataBaseWindow::closeEvent(QCloseEvent *){
    dataBase->updateAllergies(ui->listAllergiesDataBase->getStrings());
}

void AllergieDataBaseWindow::showEvent( QShowEvent* event ) {
    dataBase->loadAllergies();  // for reload
    updateUi();

    QWidget::showEvent( event );
}
