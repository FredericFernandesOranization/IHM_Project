#include "rightzone.h"

RightZone::RightZone() : QWidget()
{

    //RightZone Properties
    //this->resize(1000,50);
    //this->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(Qt::gray));
//    this->setFixedHeight(400);

    //Separation UpperMenu - Gallery
    QVBoxLayout *rightVerticalLayout = new QVBoxLayout;
    rightVerticalLayout->setSpacing(3);
    this->setLayout(rightVerticalLayout);

    //Creation UpperMenu
    QHBoxLayout *upperMenuHorizontalLayout = new QHBoxLayout; //creation Layout Menu

    QWidget *upperMenu = new QWidget;
    upperMenu->setAutoFillBackground(true);
    upperMenu->setPalette(QPalette(QColor(70,130,180)));
    upperMenu->setStyleSheet("padding : 0 ; margin : 0");
    upperMenu->setFixedHeight(100);
    upperMenu->setLayout(upperMenuHorizontalLayout);
    rightVerticalLayout->addWidget(upperMenu); //Adding UpperMenu in RightPart

    //Creating UpperMenuBar
    QList<QString> stringMenu = QList<QString>() << QString("Menu 1") << QString("Menu 2") << QString("Menu 3") << QString("Menu 4");
    for(int i=0; i<4; i++){
        QPushButton *b = new QPushButton(stringMenu.at(i));
        b->setFixedHeight(85);
        b->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        upperMenuHorizontalLayout->addWidget(b);
    }

    //Creating Stack Layout for Gallery
    QScrollArea *galleryScroll = new QScrollArea;
    galleryScroll->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    galleryScroll->setWidgetResizable(true);
    //galleryScroll->setStyleSheet("background-color : blue");
    this->galleriesLayout = GalleriesLayout::getInstance();
    QWidget* galleriesList = new QWidget();
    galleryScroll->setWidget(galleriesList);
    rightVerticalLayout->addWidget(galleryScroll); //Adding Gallery to RightZone
    galleriesList->setLayout(galleriesLayout);

    //Creating Detailled Widget
    DetailedItem* detailedItem = new DetailedItem(Database::getInstance()->getDish(0));

    //Adding Galleries To StackedLayout
    QList<QString> galleriesLabels = QList<QString>() << QString("Entrees") << QString("Boissons") << QString("Plats") << QString("Desserts");
    for(int i=0; i<4; i++){
       Gallery* g = new Gallery(galleriesLabels.at(i));
       //galleriesLayout->addWidget(new Gallery(galleriesLabels.at(i)));
       /*QScrollArea *scroller = new QScrollArea;
       scroller->setLayout();
       scroller->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
       scroller->setWidget(g);*/
       BackButton* button = detailedItem->getBackButton();
       connect(button, SIGNAL(onBackClick(QString)), g, SLOT(onBackClick(QString)));
       galleriesLayout->addWidget(g);
    }

    //adding detailed Widget to StackedLayout
    galleriesLayout->addWidget(detailedItem);
}
