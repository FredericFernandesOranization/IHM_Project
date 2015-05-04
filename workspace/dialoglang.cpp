#include "dialoglang.h"
#include "ui_dialoglang.h"

DialogLang::DialogLang(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogLang)
{
    ui->setupUi(this);
    setStyleSheet("border-radius: 15px;");
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(0,0,0)));
    setWindowOpacity(0.9);
    //this->setWindowFlags(Qt::Popup);
    const QRect screen = QApplication::desktop()->screenGeometry();
    this->move( screen.center() - this->rect().center() );
    setWindowFlags(Qt::FramelessWindowHint);

    ui->btnAnglais->setFixedWidth(100);
    ui->btnAnglais->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    ui->btnAnglais->setStyleSheet("border-image:  url(:/images/resources/imagesPlats/anglais.png) 0 0 0 0 stretch stretch; border-width: 0px;");

    ui->btnArabe->setFixedWidth(100);
    ui->btnArabe->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    ui->btnArabe->setStyleSheet("border-image:  url(:/images/resources/imagesPlats/Arabe.png) 0 0 0 0 stretch stretch; border-width: 0px;");

    ui->btnChinois->setFixedWidth(100);
    ui->btnChinois->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    ui->btnChinois->setStyleSheet("border-image:  url(:/images/resources/imagesPlats/chine.png) 0 0 0 0 stretch stretch; border-width: 0px;");

    ui->btnEspagne->setFixedWidth(100);
    ui->btnEspagne->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    ui->btnEspagne->setStyleSheet("border-image:  url(:/images/resources/imagesPlats/espagne.jpg) 0 0 0 0 stretch stretch; border-width: 0px;");

    ui->btnFrancais->setFixedWidth(100);
    ui->btnFrancais->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    ui->btnFrancais->setStyleSheet("border-image:  url(:/images/resources/imagesPlats/flag.jpg) 0 0 0 0 stretch stretch; border-width: 0px;");

    ui->btnItalie->setFixedWidth(100);
    ui->btnItalie->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    ui->btnItalie->setStyleSheet("border-image:  url(:/images/resources/imagesPlats/italie.png) 0 0 0 0 stretch stretch; border-width: 0px;");


}

DialogLang::~DialogLang()
{
    delete ui;
}

void DialogLang::on_btnItalie_clicked()
{
    this->close();
}

void DialogLang::on_btnAnglais_clicked()
{
    this->close();
}

void DialogLang::on_btnFrancais_clicked()
{
    this->close();
}

void DialogLang::on_btnArabe_clicked()
{
    this->close();
}

void DialogLang::on_btnEspagne_clicked()
{
    this->close();
}

void DialogLang::on_btnChinois_clicked()
{
    this->close();
}
