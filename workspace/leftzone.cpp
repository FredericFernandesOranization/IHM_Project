#include "leftzone.h"

LeftZone::LeftZone() : QWidget()
{
    //Left Zone Properties
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    this->resize(500, 100);
    this->setStyleSheet("background-color: Orange");
        //leftZone->setStyleSheet("background-image: url(:/images/lightB.png)");
    this->setSizePolicy(sizePolicy);

    //separation SwapButton - Command Zone
    QVBoxLayout *leftVerticalLayout = new QVBoxLayout;
    //leftVerticalLayout->sizeConstraint();
    //leftVerticalLayout->setSpacing(0);
    this->setLayout(leftVerticalLayout);

    //Creating Swap Button
    QPushButton *switchButton = new QPushButton("Switch Button", this);
    switchButton->setFixedHeight(100);
        //switchButton->setFixedSize(300,90);
    switchButton->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Maximum);
        //switchButton->setStyleSheet("background-color: Blue");
    switchButton->setStyleSheet("background-image: url(:/images/middleEarth.jpg)");
    leftVerticalLayout->addWidget(switchButton);

    Gallery* g = Gallery::getInstance();
    //Creating Left Menu Bar
    QList<QString> stringMenu = QList<QString>() << QString("Boissons") << QString("Entree") << QString("Plat") << QString("Dessert");
    for(int i=0; i<4; i++){
        QPushButton *b = new QPushButton(stringMenu.at(i));

        //connect(b, SIGNAL(clicked()), b, b->showType(stringMenu.at(i)));
        b->setFixedWidth(280);
        b->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        leftVerticalLayout->addWidget(b);
    }
}
// /usr/bin/qmake-qt4
