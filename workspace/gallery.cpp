#include "gallery.h"
#include <QVBoxLayout>
#include <QPushButton>
#include "database.h"
#include "item.h"
#include "flowlayout.h"

Gallery::Gallery() : QWidget()
{
    //Gallery Properties
    //QWidget *gallery = new QWidget();
    //this->setStyleSheet("background-image: url(:/images/lightB.png)");
    this->setStyleSheet("background-color: Blue");
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //Gallery Layout
    //FlowLayout *galleryLayout = new FlowLayout;
    QVBoxLayout *galleryLayout = new QVBoxLayout();

    galleryLayout->addWidget(new QPushButton(tr("Short")));
    this->setLayout(galleryLayout);

    //loading Database
    Database* data = Database::getInstance();

    //Adding Gallery Items
    for(int i=0; i<2; i++){
        QWidget* q = new QWidget;
        q->setStyleSheet("background-color: Green");

        //QPushButton *b = new QPushButton("Button");
        //b->setFixedSize(150,150);
        //b->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        galleryLayout->addWidget(q);
        //Item *itemM = new Item(data->getDish(i));
        //itemM->show(q);
    }



    //galleryLayout->addWidget(i);



}
