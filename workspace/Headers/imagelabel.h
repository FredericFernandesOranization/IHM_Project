#include <QLabel>
#include <QLabel>
#include <QImage>
#include <QDebug>
#include <QPixmap>
#include <QPen>
#include <QPainter>
#include <QPushButton>
#include <QVBoxLayout>
#include <QWidget>
#include <QColor>
#include "Headers/plat.h"

class ImageLabel : public QLabel{
    //Q_OBJECT
public:
    ImageLabel(Plat plat,int imgSizeW,int imgSizeH ,QColor background, QWidget *parent);
private slots:
    void paintEvent(QPaintEvent *e);
    QString imagePath;
    QImage* img;
    int imgSizeW;
    int imgSizeH;
    QColor background;
};
