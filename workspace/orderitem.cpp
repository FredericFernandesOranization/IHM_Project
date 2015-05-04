#include "orderitem.h"

OrderItem::OrderItem(Plat p) : QWidget()
{
    this->plat = plat;
    //creating layout
    QVBoxLayout *mainLayout = new QVBoxLayout;
    this->setLayout(mainLayout);
    mainLayout->setSpacing(1);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setStyleSheet("text-align: center; margin: 2px; font-family: Arial,sans-serif; font: bold; border-style: solid; border-width: 1px; background: rgb(255,158,65); ");
    this->setAutoFillBackground(true);

    //upper part
    QWidget* upperPart = new QWidget;
    QHBoxLayout *upperLayout = new QHBoxLayout;
    upperPart->setLayout(upperLayout);
    QLabel *dishName = new QLabel(p.getName());
    dishName->setStyleSheet("margin: 2px; font-family: Arial,sans-serif; font: bold; border-style: none; border-width: 1px; background: rgb(255,158,65); ");

    QLabel *dishPrice = new QLabel("Price: " + QString::number(p.getPrice()) + "€");
    dishPrice->setStyleSheet("margin: 2px; font-family: Arial,sans-serif; font: bold; border-style: none; border-width: 1px; background: rgb(255,158,65); ");

    upperLayout->addWidget(dishName);
    upperLayout->addWidget(dishPrice);

    //lower part
    QWidget* lowerPart = new QWidget;
    QHBoxLayout *lowerLayout = new QHBoxLayout;
    lowerPart->setLayout(lowerLayout);

    QLabel *minusSign = new QLabel("-");
    minusSign->setStyleSheet("text-align: center; color: rgb(0, 255, 27)");

    QLabel *quantityLabel = new QLabel("1");
    quantityLabel->setStyleSheet("margin: 2px; font-family: Arial,sans-serif; font: bold; text-align: center; color: rgb(255, 255, 255)");

    QLabel *plusSign = new QLabel("+");
    plusSign->setStyleSheet("margin: 2px; width: 5px; height:5px; font-family: Arial,sans-serif; font: bold;text-align: center; color: rgb(255, 0, 43)");

    lowerLayout->addWidget(minusSign);
    lowerLayout->addWidget(quantityLabel);
    lowerLayout->addWidget(plusSign);


    //adding components to layout
    mainLayout->addWidget(upperPart);
    mainLayout->addWidget(lowerPart);

    this->show();
}

OrderItem::~OrderItem()
{

}

QString OrderItem::getName()
{
    return this->plat.getName();
}

