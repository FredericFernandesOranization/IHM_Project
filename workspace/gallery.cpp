#include "gallery.h"
#include <QVBoxLayout>
#include <QPushButton>
#include "database.h"
#include "item.h"

Gallery::Gallery() : QWidget()
{
    //Gallery Properties
    //QWidget *gallery = new QWidget();
    //this->setStyleSheet("background-image: url(:/images/lightB.png)");
    this->setStyleSheet("background-color: Blue");
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //Gallery Layout
    QVBoxLayout *galleryLayout = new QVBoxLayout();
    this->setLayout(galleryLayout);

    //Adding Gallery Items
    /*for(int i=0; i<4; i++){
        QPushButton *b = new QPushButton("Button");
        //b->setFixedSize(150,150);
        //b->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        galleryLayout->addWidget(b);
    }*/

    //loading Database
    QString pathBase = "../workspace/resources/plats.xml";
    QString pathIMG= "../workspace/resources/imagesPlats/";
    Database *data = new Database(pathBase,pathIMG);

    Item *i = new Item(data->getDish(1));
    galleryLayout->addWidget(i);
    //i->show(this);

}
