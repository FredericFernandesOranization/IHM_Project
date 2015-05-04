#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <QWidget>
#include <QHBoxLayout>
#include "plat.h"
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>

class OrderItem : public QWidget
{
public:
    OrderItem(Plat p);
    OrderItem(Plat p, QWidget* parent);
    ~OrderItem();
    QString getName();
private:
    Plat plat;
};

#endif // ORDERITEM_H
