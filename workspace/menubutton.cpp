#include "menubutton.h"

MenuButton::MenuButton(QString label, QWidget* parent) : QPushButton(label, parent)
{
    this->label = label;
    this->setStyleSheet("border: none; border-radius: 55px;  padding: 6px;");
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(70,130,180)));
}

MenuButton::~MenuButton()
{

}

QString MenuButton::getLabel(){ return this->label; }

void MenuButton::changeLayout(){

      qDebug() << "dans ChangeLayout";
      int i = LeftBarLayout::getInstance()->currentIndex();
      LeftBarLayout::getInstance()->setCurrentIndex(1-i);

//    int i = this->leftZoneStackedLayout->currentIndex();
//    leftZoneStackedLayout->setCurrentIndex(i-1);
}


void MenuButton::onClick(){
    //this->setPalette(QPalette(QPalette::dark));
    this->setPalette(QPalette(Qt::darkBlue));
    //this->setStyleSheet("background-color: #A3C1DA; border: none;");
    emit setUnclicked(this->label);
    //qDebug() << "dans onClick";
    QStringList myOptions;
    myOptions << "Entrees" << "Boissons" << "Plats" << "Desserts" << "Back";
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

