#ifndef ITEM_H
#define ITEM_H
#include <plat.h>
#include <QLabel>
#include <QImage>

class Item :public QWidget
{
public:
    Item(QString name);
    Item(Plat plat,int imgSizeW=150 ,int imgSizeH=100, QColor background=QColor(70,130,180),QWidget *parent = 0);
    virtual void paintEvent(QPaintEvent *);
private:


    QImage *img;
    int imgSizeW;
    int imgSizeH;

};

#endif // ITEM_H
