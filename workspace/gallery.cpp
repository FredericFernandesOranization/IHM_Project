#include "gallery.h"
#include <QVBoxLayout>
#include <QPushButton>

Gallery::Gallery() : QWidget()
{
    //Gallery Properties
    QWidget *gallery = new QWidget();
    //this->setStyleSheet("background-image: url(:/images/lightB.png)");
    this->setStyleSheet("background-color: Green");

    //Gallery Layout
    QVBoxLayout *galleryLayout = new QVBoxLayout();
    gallery->setLayout(galleryLayout);

    //Adding Gallery Items
    for(int i=0; i<4; i++){
        QPushButton *b = new QPushButton("Button");
        b->setFixedSize(150,150);
        b->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        galleryLayout->addWidget(b);
    }
    //Item *i = new Item(data->getDish(1));
    //i->show(gallery);

}
