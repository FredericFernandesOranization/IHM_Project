#include "commande.h"

Commande *Commande::instance = NULL;
Commande::Commande(QWidget *parent) : QWidget(parent)
{
    commandLayout = new QVBoxLayout;
    this->setLayout(commandLayout);

}

void Commande::addDish(Plat p)
{
    qDebug() << "dish added: " << p.getName();
    if(itemList.contains(p.getName())){ // already exist
        qDebug()<<"exist";
        OrderItem *item = itemList.value(p.getName());
        item->add();
    }else {
        qDebug()<<"not exist";
         OrderItem *newItem = new OrderItem(p);
         itemList.insert(p.getName(),newItem);
         commandLayout->addWidget(newItem);
    }
}

//only called when item is in command list
void Commande::removeDish(Plat p){
    qDebug() << "removeDish dish : " << p.getName();
    if(itemList.contains(p.getName())){ // already exist
        OrderItem *item = itemList.value(p.getName());
        if(item->remove()){ // return true item have 0 elem
            itemList.take(p.getName()); // remove
            commandLayout->removeWidget(item);
        }
    }
}
