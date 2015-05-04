#include "ingredientdatabasewindow.h"
#include "ui_ingredientdatabasewindow.h"

IngredientDataBaseWindow::IngredientDataBaseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::IngredientDataBaseWindow)
{
    ui->setupUi(this);
    this->dataBase = Database::getInstance();
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(80,142,150)));
    updateUi();

}

IngredientDataBaseWindow::~IngredientDataBaseWindow()
{
    delete ui;
}

void IngredientDataBaseWindow::updateUi(){
    ui->listIngredDataBase->clear();
    ui->lineEditNameIngred->clear();
    ui->listIngredDataBase->addItems(dataBase->getClientIngredientsList());
}



void IngredientDataBaseWindow::on_btnAddIngred_clicked()
{
    QString txt = ui->lineEditNameIngred->text().simplified();
    ui->listIngredDataBase->myAddIten(txt);

}
void IngredientDataBaseWindow::closeEvent(QCloseEvent *){
    dataBase->updateIngredients(ui->listIngredDataBase->getStrings());

}
void IngredientDataBaseWindow::showEvent( QShowEvent* event ) {
    dataBase->loadIngredients();  // for reload
    updateUi();

    QWidget::showEvent( event );
}
