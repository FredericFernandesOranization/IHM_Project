#include "commande.h"

Commande *Commande::instance = NULL;
Commande::Commande(QWidget *parent) : QWidget(parent)
{
    commandLayout = new QVBoxLayout;
    this->setLayout(commandLayout);
    //this->setStyleSheet("background: rgb(255,158,65)");

}

void Commande::addDish(Plat p)
{
    qDebug() << "dish added: " << p.getName();
    if(itemList.contains(p.getName())){ // already exist
        //qDebug()<<"exist";
        OrderItem *item = itemList.value(p.getName());
        item->add();
    }else {
        //qDebug()<<"not exist";
        OrderItem *newItem = new OrderItem(p,this);
        connect(newItem,SIGNAL(remoove(Plat)),this,SLOT(removeDish(Plat)));
        connect(newItem,SIGNAL(add(Plat)),this,SLOT(addDish(Plat)));
        itemList.insert(p.getName(),newItem);
        commandLayout->addWidget(newItem);
    }
}

//only called when item is in command list
void Commande::removeDish(Plat p){
    //qDebug() << "removeDish dish : " << p.getName();
    if(itemList.contains(p.getName())){ // already exist
        OrderItem *item = itemList.value(p.getName());
        if(item->remove()){ // return true item have 0 elem
            qDebug()<<"delate";
            itemList.take(p.getName()); // remove
            commandLayout->removeWidget(item);
            disconnect(item,SIGNAL(remoove(Plat)),this,SLOT(removeDish(Plat)));
            disconnect(item,SIGNAL(add(Plat)),this,SLOT(addDish(Plat)));
            delete item;
            this->repaint();
        }
    }
}
