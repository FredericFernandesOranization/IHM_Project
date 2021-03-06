#ifndef ORDERITEM_H
#define ORDERITEM_H

#include <QWidget>
#include <QHBoxLayout>
#include "plat.h"
#include <QLabel>
#include <QListWidget>
#include <QListWidgetItem>
#include <QMouseEvent>
#include <QRect>
#include <QPainter>


class OrderItem : public QWidget
{
    Q_OBJECT
public:
    //OrderItem(Plat p);
    OrderItem(Plat p, QWidget* parent=0);
    ~OrderItem();
    QString getName()const ;
    int getPrice()const ;
    bool operator==(const OrderItem &item);
    inline void add(){nbItem++;drow();}
    inline bool remove(){nbItem--;drow();return nbItem==0;}
    int getNbItem();
    void mousePressEvent(QMouseEvent *event);
private:
    void drow();
    Plat plat;
    int nbItem;
    QLabel *dishPrice;
    QLabel *quantityLabel;
    QLabel *minusSign;
    QLabel *plusSign;
private slots:
    // void paintEvent(QPaintEvent *e);
signals:
    void remoove(Plat);
    void add(Plat);
};

#endif // ORDERITEM_H
