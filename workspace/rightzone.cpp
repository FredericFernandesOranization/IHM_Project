#include "rightzone.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "gallery.h"

RightZone::RightZone() : QWidget()
{
    //RightZone Properties
    this->resize(1000,50);
    //this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->setStyleSheet("background-color: Yellow");
    //this->setStyleSheet("background-image: url(:/images/lightB.png)");

    //Separation UpperMenu - Gallery
    QVBoxLayout *rightVerticalLayout = new QVBoxLayout;
    this->setLayout(rightVerticalLayout);

    //Creation UpperMenu
    QHBoxLayout *upperMenuHorizontalLayout = new QHBoxLayout; //creation Layout Menu
    upperMenuHorizontalLayout->setSpacing(0);

    QWidget *upperMenu = new QWidget;
    upperMenu->setStyleSheet("padding : 0 ; margin : 0");
    upperMenu->setFixedHeight(100);
    upperMenu->setLayout(upperMenuHorizontalLayout);
    rightVerticalLayout->addWidget(upperMenu); //Adding UpperMenu in RightPart

    //Creating UpperMenuBar
    QList<QString> stringMenu = QList<QString>() << QString("Menu1") << QString("Menu2") << QString("Menu3") << QString("Menu4");
    for(int i=0; i<4; i++){
        QPushButton *b = new QPushButton(stringMenu.at(i));
        b->setFixedSize(300,90);
        b->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        upperMenuHorizontalLayout->addWidget(b);
    }

    //Creating Gallery
    Gallery *gallery = new Gallery();
    rightVerticalLayout->addWidget(gallery); //Adding Gallery to RightZone

}
