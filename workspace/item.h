#ifndef ITEM_H
#define ITEM_H
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>
#include <QDebug>
#include <QMouseEvent>
#include "imagelabel.h"

#include "plat.h"

class Item :public QWidget
{
    Q_OBJECT
public:
    Item(QString name);
    Item(Plat plat,int imgSizeW=150 ,int imgSizeH=100, QColor background=QColor(70,130,180),QWidget *parent = 0);
    //virtual void paintEvent(QPaintEvent *);
    //ImageLabel* getImage();
private:
    ImageLabel* image;
    QImage *img;
    Plat plat;
    int imgSizeW;
    int imgSizeH;
    int galleryParent;

signals:
    void clickedImage(Plat p);

protected:
    void mousePressEvent(QMouseEvent * event);

};

#endif // ITEM_H
