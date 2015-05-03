#include "confirmdialog.h"
#include "ui_confirmdialog.h"

ConfirmDialog::ConfirmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmDialog)
{
    ui->setupUi(this);
    ui->btnAnnuler->setStyleSheet("font-family: Arial,sans-serif;font: bold;width: 200px;height: 43px;padding-top: 7px;text-align: center;color: #000;background: orange;border-radius: 8px;");
    ui->btnValid->setStyleSheet("font-family: Arial,sans-serif;font: bold;width: 200px;height: 43px;padding-top: 7px;text-align: center;color: #000;background: orange;border-radius: 8px;");
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(70,130,180)));
    this->setWindowFlags(Qt::Popup);
    const QRect screen = QApplication::desktop()->screenGeometry();
     this->move( screen.center() - this->rect().center() );
}

ConfirmDialog::~ConfirmDialog()
{
    delete ui;
}

void ConfirmDialog::on_btnValid_clicked()
{
    qDebug()<<"Vaildation";
    this->close();
}

void ConfirmDialog::on_btnAnnuler_clicked()
{
    qDebug()<<"Annulation";
    this->close();
}
