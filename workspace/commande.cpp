#include "commande.h"

Commande *Commande::instance = NULL;
Commande::Commande() : QScrollArea()
{
    commandLayout = new QVBoxLayout;
}

void Commande::addDish(Plat p)
{
    qDebug() << "dish added: " << p.getName();
    for(int i = 0; i < this->itemList.size(); i++){
        if(this->itemList.at(i)->getName().compare(p.getName()) == true){
            this->itemList.append(new OrderItem(p));
            this->quantities.insert(p.getName(), this->quantities.value(p.getName())+1);
        }
    }
    this->itemList.append(new OrderItem(p));
    this->quantities.insert(p.getName(), 1);

}

//only called when item is in command list
void Commande::removeDish(Plat p)
{
    this->quantities.remove(p.getName());
    for(int i = 0; i < this->itemList.size(); i++){
        if(this->itemList.at(i)->getName().compare(p.getName()) == true){
            this->itemList.removeAt(i);
        }
    }
}
