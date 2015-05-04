#include "editingredientwindow.h"
#include "ui_editingredientwindow.h"

EditIngredientWindow::EditIngredientWindow(QListWidgetItem *item,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditIngredientWindow)
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

EditIngredientWindow::~EditIngredientWindow()
{
    delete ui;
}

void EditIngredientWindow::updateUi()
{
    dataBase->loadIngredients();
    ui->listIngrDataBase->clear();
    ui->listIngrProduct->clear();
    ui->listIngrDataBase->addItems(dataBase->getClientIngredientsList());
    ui->listIngrProduct->addItems(plat.getIngredientsList());
}

void EditIngredientWindow::closeEvent(QCloseEvent *)
{
    QStringList list = ui->listIngrProduct->getStrings();
    plat.setIngredientsList(list);

    QVariant qv;
    qv.setValue(plat);
    this->item->setData(Qt::UserRole,qv);

}
