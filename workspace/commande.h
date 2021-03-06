#ifndef COMMANDE_H
#define COMMANDE_H

#include "plat.h"
#include<QScrollArea>
#include<QVBoxLayout>
#include "orderitem.h"
#include "flowlayout.h"


class Commande : public QWidget
{
    Q_OBJECT
public:

    static Commande* getInstance() {
        if(instance == NULL)
            instance = new Commande();
        return instance;
    }

public slots:
    void addDish(Plat p);
    void removeDish(Plat p);
signals:
    void updatePrice(int,int);
private:
    Commande(QWidget *parent=0);
    static Commande* instance;
    //FlowLayout *commandLayout;
    QVBoxLayout *commandLayout;
    QHash<QString, OrderItem*> itemList;

};
#endif // COMMANDE
