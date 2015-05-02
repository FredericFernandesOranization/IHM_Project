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
    this->layout->setSpacing(20);

    //loading Database
    this->database = Database::getInstance();

    //Adding Gallery Items
    /*for(int i=0; i<this->database->getNbDishes(); i++){
        //QWidget* q = new QWidget;
        Item *item = new Item(this->database->getDish(i));
        this->layout->addWidget(item);
    }*/
    this->showType(QString("Boissons"));

}

Gallery::Gallery(QString type) : QWidget()
{
    //Gallery Properties
    this->type = type;
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(70,130,180)));
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
    QList<Plat*> listePlats = this->database->filterType(type);
    for(int i=0; i<listePlats.size(); i++){
        Item *item = new Item(*listePlats.at(i));
        ImageLabel* i = item->getImage();
        connect(i, SIGNAL(clickedImage(Plat)), this, SLOT(onItemClick(Plat)));
        this->layout->addWidget(item);
    }
}

void Gallery::onItemClick(Plat p){
    this->showItem(p);
}

void Gallery::showItem(Plat p){
    qDebug() << "clicked on : " << p.getName();
    //still need to show right plate
    GalleriesLayout::getInstance()->setCurrentIndex(4);
}

void Gallery::onBackClick(QString type){
    QStringList myOptions;
    myOptions << "Entrees" << "Boissons" << "Plats" << "Desserts";
    qDebug() << "back to ... " << myOptions.indexOf(type);
    switch(myOptions.indexOf(type)){
        case 0: //entrees
            qDebug() << "putting 0 index";
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






