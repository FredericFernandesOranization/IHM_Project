#ifndef DETAILEDITEM_H
#define DETAILEDITEM_H

#include<backbutton.h>
#include<QHBoxLayout>
#include "plat.h"
#include "imagelabel.h"


class DetailedItem :public QWidget
{
    Q_OBJECT
public:
    DetailedItem(Plat plat,int imgSizeW=150 ,int imgSizeH=100, QColor background=QColor(70,130,180), QWidget *parent = 0);
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
