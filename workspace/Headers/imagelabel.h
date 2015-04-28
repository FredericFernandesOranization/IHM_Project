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
    ImageLabel(Plat p, QWidget *parent, int imgSizeW, int imgSizeH, QColor background );
private slots:
    //void paintEvent(QPaintEvent *e);
    QString imagePath;
    int imgSizeW;
    int imgSizeH;
    QColor background;
};
