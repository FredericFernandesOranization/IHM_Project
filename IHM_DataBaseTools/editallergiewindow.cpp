#include "editallergiewindow.h"
#include "ui_editallergiewindow.h"

EditAllergieWindow::EditAllergieWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditAllergieWindow)
{
    ui->setupUi(this);
}

EditAllergieWindow::~EditAllergieWindow()
{
    delete ui;
}
