#include "menubutton.h"

MenuButton::MenuButton(QString label) : QPushButton
{
    this->label = label;
}

MenuButton::~MenuButton()
{

}

void MenuButton::onClick(){
    QStringList myOptions;
    myOptions << "entrees" << "plats" << "boissons" << "desserts";
    switch(myOptions.indexOf(this->label)){
        case 0: //entrees
            Gallery::getInstance()->showType("entree");
            break;
        case 1: //plats
            Gallery::getInstance()->showType("entree");
            break;
        case 2: //boissons
            Gallery::getInstance()->showType("entree");
            break;
        case 3: //desserts
            Gallery::getInstance()->showType("entree");
            break;
        default:
            break;
        //il faut ajouter les bouton du upperMenu
}
    // QObject::connect(instance of the gallery, SIGNAL(clicked()), instance of the gallery, SLOT(onClick()));

