#ifndef COMMANDE_H
#define COMMANDE_H

#include "orderitem.h"
#include "plat.h"

#include<QScrollArea>
#include<QVBoxLayout>

class Commande : public QScrollArea
{
    Q_OBJECT
public:
    Commande();
    QWidget *commandWidget;
    QList<OrderItem*> itemList;
    QVBoxLayout *commandLayout;
    QHash<QString, int> quantities;
    static Commande* getInstance() {
        if(instance == NULL)
            instance = new Commande();
        return instance;
    }
public slots:
    void addDish(Plat p);
    void removeDish(Plat p);
private:
    static Commande* instance;
};
#endif // COMMANDE
