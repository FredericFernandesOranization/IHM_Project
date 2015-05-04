#include "orderitem.h"

//OrderItem::OrderItem(Plat p) : QWidget()
//{
//    this->plat = Plat::copie(p);
//    qDebug() << "creation OrderItem -> plat.name = " << this->plat.getName();
//    //creating layout
//    QVBoxLayout *mainLayout = new QVBoxLayout;
//    this->setLayout(mainLayout);
//    mainLayout->setSpacing(1);
//    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
//    this->setStyleSheet("text-align: center; margin: 2px; font-family: Arial,sans-serif; font: bold; border-style: solid; border-width: 1px; background: rgb(255,158,65); ");
//    this->setAutoFillBackground(true);

//    //upper part
//    QWidget* upperPart = new QWidget;
//    QHBoxLayout *upperLayout = new QHBoxLayout;
//    upperPart->setLayout(upperLayout);
//    QLabel *dishName = new QLabel(p.getName());
//    dishName->setStyleSheet("margin: 2px; font-family: Arial,sans-serif; font: bold; border-style: none; border-width: 1px; background: rgb(255,158,65); ");

//    QLabel *dishPrice = new QLabel("Price: " + QString::number(p.getPrice()) + "€");
//    dishPrice->setStyleSheet("margin: 2px; font-family: Arial,sans-serif; font: bold; border-style: none; border-width: 1px; background: rgb(255,158,65); ");

//    upperLayout->addWidget(dishName);
//    upperLayout->addWidget(dishPrice);

//    //lower part
//    QWidget* lowerPart = new QWidget;
//    QHBoxLayout *lowerLayout = new QHBoxLayout;
//    lowerPart->setLayout(lowerLayout);

//    QLabel *minusSign = new QLabel("-");
//    minusSign->setStyleSheet("text-align: center; color: rgb(0, 255, 27)");

//    QLabel *quantityLabel = new QLabel("1");
//    quantityLabel->setStyleSheet("margin: 2px; font-family: Arial,sans-serif; font: bold; text-align: center; color: rgb(255, 255, 255)");

//    QLabel *plusSign = new QLabel("+");
//    plusSign->setStyleSheet("margin: 2px; width: 5px; height:5px; font-family: Arial,sans-serif; font: bold;text-align: center; color: rgb(255, 0, 43)");

//    lowerLayout->addWidget(minusSign);
//    lowerLayout->addWidget(quantityLabel);
//    lowerLayout->addWidget(plusSign);


//    //adding components to layout
//    mainLayout->addWidget(upperPart);
//    mainLayout->addWidget(lowerPart);

//    //this->show();
//}

OrderItem::OrderItem(Plat p, QWidget *parent) : QWidget(parent)
{
    this->plat = Plat(p);
    nbItem=1;
    //creating layout
    QVBoxLayout *mainLayout = new QVBoxLayout;

    this->setLayout(mainLayout);
    mainLayout->setSpacing(0);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setStyleSheet("text-align: center; font-family: Arial,sans-serif; font: bold; border-style: solid; border-width: 1px; background: rgb(255,158,65); ");
    this->setAutoFillBackground(true);

    //upper part
    QWidget* upperPart = new QWidget;
    QHBoxLayout *upperLayout = new QHBoxLayout;
    upperPart->setLayout(upperLayout);

    //creating Name Label
    QLabel *dishName = new QLabel();
    //QString labelPrice("Price: " + QString::number(somme) + "€");
    dishName->setText("<a style=\"font-size:13pt; font : bold;font-family: Arial,sans-serif; font: bold; background: rgb(255,158,65);\">" + p.getName() + "</a>");
    dishName->setAlignment(Qt::AlignLeft);
    dishName->setStyleSheet("border-style: none");
    //dishName->setStyleSheet("margin: 2px; font-family: Arial,sans-serif; font: bold; border-style: none; border-width: 1px; background: rgb(255,158,65); ");

    //create Price Label
    int somme = p.getPrice()*nbItem;
    QString labelPrice("Price: " + QString::number(somme) + "€");
    dishPrice = new QLabel();
    dishPrice->setText("<a style=\"font-size:13pt; font : bold;font-family: Arial,sans-serif; font: bold; background: rgb(255,158,65);\">" + labelPrice + "</a>");
    dishPrice->setAlignment(Qt::AlignRight);
    dishPrice->setStyleSheet("border-style: none");
    upperLayout->addWidget(dishName);
    upperLayout->addWidget(dishPrice);

    //lower part
    QWidget* lowerPart = new QWidget;
    QHBoxLayout *lowerLayout = new QHBoxLayout;
    lowerPart->setLayout(lowerLayout);

    minusSign = new QLabel("-");
    //minusSign->setText("<a style=\"font-size:13pt; font : bold;text-shadow: 5px 5px #558ABB; text-decoration : underline;font-family : Arial, Helvetica, sans-serif\">ENTREES</a>");
    minusSign->setStyleSheet("text-align: center; color: rgb(0, 255, 27)");

    quantityLabel = new QLabel(QString::number(nbItem));
    quantityLabel->setStyleSheet("margin: 2px; font-family: Arial,sans-serif; font: bold; text-align: center; color: rgb(255, 255, 255)");

    plusSign = new QLabel("+");
    plusSign->setStyleSheet("margin: 2px; width: 5px; height:5px; font-family: Arial,sans-serif; font: bold;text-align: center; color: rgb(255, 0, 43)");

    lowerLayout->addWidget(minusSign);
    lowerLayout->addWidget(quantityLabel);
    lowerLayout->addWidget(plusSign);

    //adding components to layout
    mainLayout->addWidget(upperPart);
    mainLayout->addWidget(lowerPart);
    mainLayout->setSpacing(0);
    //mainLayout->setSizeConstraint(QLayout::SetMaximumSize);


    //this->show();

}

OrderItem::~OrderItem()
{

}

QString OrderItem::getName() const
{
    return this->plat.getName();
}

bool OrderItem::operator==( const OrderItem &item)
{
    QString n1 = this->getName();
    QString n2 = item.getName();
    return (n1.compare(n2));
}

void OrderItem::drow(){
    int somme = this->plat.getPrice()*nbItem;
    dishPrice->setText("Price: " + QString::number(somme) + "€");
    quantityLabel->setText(QString::number(nbItem));
}

//void OrderItem::paintEvent(QPaintEvent *e)
//{
//    QRect minusRect = minusSign->rect();
//    minusRect.moveRight(90);
//    minusRect.moveBottom(80);
//    QRect plusRect = plusSign->rect();
//    plusRect.moveRight(245);
//    plusRect.moveBottom(80);

//    QPainter painter(this);
//    painter.setRenderHint(QPainter::Antialiasing);
//    painter.setPen(Qt::black);
//    painter.drawRect(minusRect);
//     painter.drawRect(plusRect);
//}
void OrderItem::mousePressEvent(QMouseEvent * event){
    qDebug()<<"click";
    QRect minusRect = minusSign->rect();
    minusRect.moveRight(90);
    minusRect.moveBottom(80);
    QRect plusRect = plusSign->rect();
    plusRect.moveRight(245);
    plusRect.moveBottom(80);

    if(plusRect.contains(event->pos())){
        qDebug()<<"plusSign";
         emit add(plat);
    }else if(minusRect.contains(event->pos())){
        qDebug()<<"minusSign";
        emit remoove(plat);

    }else
        qDebug()<<"que dal";
}



