#include "uppermenu.h"

UpperMenu::UpperMenu() : QWidget()
{
    //left - right part separation
    this->upperMenuHorizontalLayout = new QHBoxLayout;
    QWidget *upperMenu = new QWidget;
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(70,130,180)));
    //this->setStyleSheet("padding : 0 ; margin : 0");
    this->setFixedHeight(100);
    this->setLayout(this->upperMenuHorizontalLayout);
    this->upperMenuHorizontalLayout->setSpacing(100);

    //Creating left part
    QWidget *leftPart = new QWidget();
    QHBoxLayout *leftPartLayout = new QHBoxLayout;
    leftPart->setLayout(leftPartLayout);
    this->upperMenuHorizontalLayout->addWidget(leftPart);
    QList<QString> stringMenu = QList<QString>() << QString("Régimes") << QString("Ingrédients") << QString("Trier Par");
    for(int i=0; i<3; i++){
        QPushButton *b = new QPushButton(stringMenu.at(i));
        b->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

        //b->setFixedHeight(85);
        //b->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        b->setStyleSheet("border: none; background-color: rgb(60,68,84); ");
        leftPartLayout->addWidget(b);
    }

    //creating right part
    QWidget *rightPart = new QWidget();
    QHBoxLayout *rightPartLayout = new QHBoxLayout;
    rightPart->setLayout(rightPartLayout);
    this->upperMenuHorizontalLayout->addWidget(rightPart);
    QPushButton* appelerServeur = new QPushButton("APPELER SERVEUR");
    appelerServeur->setStyleSheet("border: none; background-color: rgb(70,130,180); color: rgb(255, 255, 255) ");
    //appelerServeur->setFixedHeight(80);
    appelerServeur->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QPushButton* flag = new QPushButton("Flag");
    flag->setStyleSheet("border-image: url(:/images/flag.jpg);border-width: 0px;");
    rightPartLayout->addWidget(appelerServeur);
    rightPartLayout->addWidget(flag);
}

UpperMenu::~UpperMenu()
{

}

