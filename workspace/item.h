#ifndef ITEM_H
#define ITEM_H
#include <QImage>
#include <QGraphicsScene>
#include<plat.h>
class Item : public QGraphicsScene
{
public:
    Item(QString name);
    Item(Plat plat,int imgSizeW=150 ,int imgSizeH=100, QColor background=QColor(70,130,180));
    void show(QWidget * parent = 0);
private:

    QImage image;
    int imgSizeW;
    int imgSizeH;
    QGraphicsEllipseItem *ellipse;
    QGraphicsRectItem *rectangle;
    QGraphicsTextItem *text;
};

#endif // ITEM_H
