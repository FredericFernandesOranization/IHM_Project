#include "gallery.h"

Gallery *Gallery::instance = NULL;
Gallery::Gallery() : QWidget()
{
    //Gallery Properties
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(Qt::blue));
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);


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
    /*for(int i=0; i<this->database->getNbDishes(); i++){
        //QWidget* q = new QWidget;
        Item *item = new Item(this->database->getDish(i));
        this->layout->addWidget(item);
    }*/
    this->showType(type);
}

void Gallery::showType(QString type)
{
    QList<Plat*> listePlats = this->database->filterType(type);
    for(int i=0; i<listePlats.size(); i++){
        Item *item = new Item(*listePlats.at(i));
        this->layout->addWidget(item);
    }
}
