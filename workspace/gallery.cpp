#include "gallery.h"

//Gallery *Gallery::instance = NULL;
Gallery::Gallery() : QWidget()
{
    //Gallery Properties
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(Qt::blue));

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    //scroller->setWidgetResizable(true);

    //Gallery Layout

    this->layout = new FlowLayout;
    this->setLayout(this->layout);
    //this->layout->setSpacing(20);

    //loading Database
    this->database = Database::getInstance();

    this->showType(QString("Boissons"));

}

Gallery::Gallery(QString type) : QWidget()
{
    //Gallery Properties
    this->type = type;
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(70,130,180)));
    //this->setPalette(QPalette(QColor(80,142,150)));
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //Gallery Layout
    this->layout = new FlowLayout;
    this->setLayout(this->layout);
    this->layout->setSpacing(20);

    //loading Database
    this->database = Database::getInstance();

    //Adding Gallery Items
    this->showType(type);
}

void Gallery::showType(QString type)
{
    //qDebug() << "in showType function";
    QList<Plat*> listePlats = this->database->filterType(type);
    for(int i=0; i<listePlats.size(); i++){
        Item *item = new Item(*listePlats.at(i));
        ImageLabel* img = item->getImage();
        connect(img, SIGNAL(clickedImage(Plat)), this, SLOT(onItemClick(Plat)));
        this->layout->addWidget(item);
    }
}


void Gallery::onItemClick(Plat p){
    this->showItem(p);
}

void Gallery::showItem(Plat p){
    GalleriesLayout* g = GalleriesLayout::getInstance();
    DetailedItem* from = DetailedItem::getInstance();
    //qDebug() << "FROM: \n" << from->getPlat().getId();
    DetailedItem* to = new DetailedItem(p);
    BackButton* back = to->getBackButton();
    CommanderButton* commander = to->getCommanderButton();
    back->setFromGallery(p.getType());
    Commande* commandeZone = Commande::getInstance();
    connect(commander, SIGNAL(onClick(Plat)), commandeZone, SLOT(addDish(Plat)));
    connect(commander, SIGNAL(clicked()), commander, SLOT(sendToCommandZone()));
    connect(back, SIGNAL(clicked()), back, SLOT(backToGallery()));
    from->setInstance(to);
    g->replaceWidget(from, to);
    g->setCurrentIndex(4);
    //qDebug() << "TO : \n " << to->getPlat().getId();
}

void Gallery::onBackClick(QString type){
    QStringList myOptions;
    myOptions << "Entrees" << "Boissons" << "Plats" << "Desserts";
    //qDebug() << "back to ... " << myOptions.indexOf(type);
    switch(myOptions.indexOf(type)){
        case 0: //entrees
            GalleriesLayout::getInstance()->setCurrentIndex(0);
            break;
        case 1: //plats
            GalleriesLayout::getInstance()->setCurrentIndex(1);
            break;
        case 2: //boissons
            GalleriesLayout::getInstance()->setCurrentIndex(2);
            break;
        case 3: //desserts
            GalleriesLayout::getInstance()->setCurrentIndex(3);
            break;
        default:
            break;
        //il faut ajouter les bouton du upperMenu
    }
}






