#ifndef IMAGELABEL_H
#define IMAGELABEL_H

#include <QLabel>
#include <QPen>
#include <QPainter>

#include "plat.h"

class ImageLabel : public QLabel{
    Q_OBJECT
public:
    ImageLabel(Plat plat,int imgSizeW,int imgSizeH ,QColor background, QWidget *parent);
private slots:
    void paintEvent(QPaintEvent *e);
//signals:
//    void clickedImage(Plat p);

//protected:
//    void mousePressEvent(QMouseEvent * event);
private:
    //Plat plat;
    QString imagePath;
    QImage* img;
    int imgSizeW;
    int imgSizeH;
    QColor background;
};

#endif // IMAGELABEL_H
