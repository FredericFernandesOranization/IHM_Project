#include "backbutton.h"

BackButton::BackButton() : QPushButton()
{

}

BackButton::BackButton(QString label) : QPushButton(label)
{
    this->label = label;

}


BackButton::~BackButton()
{

}

void BackButton::setFromGallery(QString type)
{
    this->fromGallery = type;
}

void BackButton::backToGallery(){
    qDebug() << " in back to gallery button";

    QStringList myOptions;
    myOptions << "Entrees" << "Boissons" << "Plats" << "Desserts";
    qDebug() << this->fromGallery;
    qDebug() << myOptions.indexOf(this->fromGallery);
    switch(myOptions.indexOf(this->fromGallery)){
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


