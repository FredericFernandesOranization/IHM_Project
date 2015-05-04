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
    rightVerticalLayout->setContentsMargins(5, 0, 0, 0);
    rightVerticalLayout->setSpacing(3);
    this->setLayout(rightVerticalLayout);

    //Creation UpperMenu
    UpperMenu* upperMenu = new UpperMenu;
    rightVerticalLayout->addWidget(upperMenu); //Adding UpperMenu in RightPart

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
    DetailedItem* detailedItem = DetailedItem::getInstance();
    //DetailedItem* detailedItem = new DetailedItem(Database::getInstance()->getDish(0));

    //Adding Galleries To StackedLayout
    QList<QString> galleriesLabels = QList<QString>() << QString("Entrees") << QString("Boissons") << QString("Plats") << QString("Desserts");
    for(int i=0; i<4; i++){
       Gallery* g = new Gallery(galleriesLabels.at(i));
       galleriesLayout->addWidget(g);
    }


    BackButton* button = detailedItem->getBackButton();
    connect(button, SIGNAL(clicked()), button, SLOT(backToGallery()));

    CommanderButton* commander = detailedItem->getCommanderButton();
    Commande* commandeZone = Commande::getInstance();
    connect(commander, SIGNAL(clicked()), commander, SLOT(sendToCommandZone()));
    connect(commander, SIGNAL(onClick(Plat)), commandeZone, SLOT(addDish(Plat)));

    //adding detailed Widget to StackedLayout
    galleriesLayout->addWidget(detailedItem);
}
