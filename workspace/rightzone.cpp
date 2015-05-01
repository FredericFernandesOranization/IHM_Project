#include "rightzone.h"

RightZone::RightZone() : QWidget()
{
    //RightZone Properties
    //this->resize(1000,50);
    //this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(Qt::gray));

    //Separation UpperMenu - Gallery
    QVBoxLayout *rightVerticalLayout = new QVBoxLayout;
    rightVerticalLayout->setSpacing(5);
    this->setLayout(rightVerticalLayout);

    //Creation UpperMenu
    QHBoxLayout *upperMenuHorizontalLayout = new QHBoxLayout; //creation Layout Menu

    QWidget *upperMenu = new QWidget;
    upperMenu->setAutoFillBackground(true);
    upperMenu->setPalette(QPalette(QColor(70,130,180)));
    upperMenu->setStyleSheet("padding : 0 ; margin : 0");
    //upperMenu->setFixedHeight(100);
    upperMenu->setLayout(upperMenuHorizontalLayout);
    rightVerticalLayout->addWidget(upperMenu); //Adding UpperMenu in RightPart

    //Creating UpperMenuBar
    QList<QString> stringMenu = QList<QString>() << QString("Menu1") << QString("Menu2") << QString("Menu3") << QString("Menu4");
    for(int i=0; i<4; i++){
        QPushButton *b = new QPushButton(stringMenu.at(i));
        //b->setFixedSize(300,90);
        //b->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        upperMenuHorizontalLayout->addWidget(b);
    }

    //Creating Stack Layout for Gallery
    this->galleriesLayout = GalleriesLayout::getInstance();
    QWidget* galleriesList = new QWidget();
    rightVerticalLayout->addWidget(galleriesList); //Adding Gallery to RightZone
    galleriesList->setLayout(galleriesLayout);

    //Adding Galleries To StackedLayout
    QList<QString> galleriesLabels = QList<QString>() << QString("Entrees") << QString("Boissons") << QString("Plats") << QString("Desserts");
    for(int i=0; i<4; i++){
       galleriesLayout->addWidget(new Gallery(galleriesLabels.at(i)));
    }
}
