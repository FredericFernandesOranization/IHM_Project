#include "confirmdialog.h"
#include "ui_confirmdialog.h"

ConfirmDialog::ConfirmDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConfirmDialog)
{
    ui->setupUi(this);
    ui->btnAnnuler->setStyleSheet("font-family: Arial,sans-serif;font: bold;width: 200px;height: 43px;padding-top: 7px;text-align: center;color: #000;background: rgb(255,158,65);border-radius: 8px;");
    ui->btnValid->setStyleSheet("font-family: Arial,sans-serif;font: bold;width: 200px;height: 43px;padding-top: 7px;text-align: center;color: #000;background: rgb(255,158,65);border-radius: 8px;");
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(80,142,150)));

    //this->setStyleSheet();
    //this->setPalette(QPalette(QColor(70,130,180)));
    this->setWindowFlags(Qt::Popup);
    QPixmap pix("../workspace/resources/imagesPlats/images.jpg");
    pix = pix.scaled(ui->lblImg->rect().size());
    ui->lblImg->setPixmap(pix);
    //ui->lblImg->
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

