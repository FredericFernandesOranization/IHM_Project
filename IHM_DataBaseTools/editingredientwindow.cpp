#include "editingredientwindow.h"
#include "ui_editingredientwindow.h"

EditIngredientWindow::EditIngredientWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditIngredientWindow)
{
    ui->setupUi(this);
}

EditIngredientWindow::~EditIngredientWindow()
{
    delete ui;
}
