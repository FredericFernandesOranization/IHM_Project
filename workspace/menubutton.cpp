#include "menubutton.h"

MenuButton::MenuButton(QString label, QWidget* parent) : QPushButton(label, parent)
{
    this->label = label;
}

MenuButton::~MenuButton()
{

}

void MenuButton::onClick(){
    //qDebug() << "dans onClick";
    QStringList myOptions;
    myOptions << "Entrees" << "Boissons" << "Plats" << "Desserts";
    //qDebug() << this->label;
    qDebug() << myOptions.indexOf(this->label);
    switch(myOptions.indexOf(this->label)){
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
    // QObject::connect(instance of the gallery, SIGNAL(clicked()), instance of the gallery, SLOT(onClick()));

