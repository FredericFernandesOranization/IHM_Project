#ifndef DETAILEDITEM_H
#define DETAILEDITEM_H


#include "plat.h"
#include "imagelabel.h"
#include <QLabel>
#include <QImage>
#include <QDebug>
#include <QPixmap>
#include <QPen>
#include <QPainter>
#include <QPushButton>
#include <QHBoxLayout>
#include "backbutton.h"

class DetailedItem :public QWidget
{
    Q_OBJECT
public:
    DetailedItem(Plat plat,int imgSizeW=500 ,int imgSizeH=350, QColor background=QColor(70,130,180), QWidget *parent = 0);
    BackButton* getBackButton();
private:
    BackButton* backButton;
    Plat plat;
    ImageLabel* image;
    QImage *img;
    int imgSizeW;
    int imgSizeH;
signals:
    void clicked(QString);

};

#endif // DETAILEDITEM_H
