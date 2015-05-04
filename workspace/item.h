#ifndef ITEM_H
#define ITEM_H

#include "imagelabel.h"
#include <QLabel>
#include <QImage>
#include <QDebug>
#include <QPixmap>
#include <QPen>
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include "commande.h"

class Item :public QWidget
{
    Q_OBJECT
public:
    Item(QString name);
    Item(Plat plat,int imgSizeW=150 ,int imgSizeH=100, QColor background=QColor(70,130,180),QWidget *parent = 0);
    //virtual void paintEvent(QPaintEvent *);
    ImageLabel* getImage();
private:
    ImageLabel* image;
    QImage *img;
    int imgSizeW;
    int imgSizeH;
    Plat plat;
private slots:
    void buy();

signals:
    void commande(Plat);
};

#endif // ITEM_H
