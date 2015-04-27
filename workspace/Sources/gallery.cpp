#include "Headers/gallery.h"

Gallery::Gallery() : QWidget()
{
    //Gallery Properties
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(Qt::blue));
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //Gallery Layout
    this->layout = new FlowLayout;
    this->setLayout(this->layout);

    //loading Database
    this->database = Database::getInstance();

    //Adding Gallery Items
    for(int i=0; i<this->database->getNbDishes(); i++){
        //QWidget* q = new QWidget;
        Item *item = new Item(this->database->getDish(i));
        this->layout->addWidget(item);
    }
    //this->showType(QString("boisson"));

}

void Gallery::showType(QString type)
{
    QList<Plat*> listePlats = this->database->filterType(type);
    this->layout = new FlowLayout;
    for(int i=0; i<listePlats.size(); i++){
        Item *item = new Item(*listePlats.at(i));
        this->layout->addWidget(item);
    }
}
