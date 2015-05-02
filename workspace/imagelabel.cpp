#include "imagelabel.h"

ImageLabel::ImageLabel(Plat plat,int imgSizeW,int imgSizeH ,QColor background, QWidget *parent): QLabel(parent)
{
    this->imgSizeW= imgSizeW;
    this->imgSizeH= imgSizeH;
    //this->plat = plat;

    this->setAutoFillBackground(true);
    this->setPalette(QPalette(background));
    //this->setPalette(QPalette(Qt::blue));

    this->img = new QImage(plat.getImagePath());
    *img = img->scaled(imgSizeW, imgSizeH);

    QLabel *labelPrice = new QLabel(QString::number(plat.getPrice()),this);
    QFont priceFont("Helvetica", 12, QFont::Bold);
    labelPrice->setFont(priceFont);
    labelPrice->move((imgSizeW)-15,(imgSizeH/2)-10);

    setFixedSize(imgSizeW+27,imgSizeH+10);
}

//void ImageLabel::mousePressEvent(QMouseEvent * event){
//    qDebug() << "clicked on image";
//    emit clickedImage(this->plat);
//}



void ImageLabel::paintEvent(QPaintEvent *)
{
    QColor orange(255,165,0,255);
    QBrush orangeBrush(orange);
    QPen outlinePen(orange);
    QPainter paint(this);
    paint.setBrush(orangeBrush);
    paint.setPen(outlinePen);
    int ellipseSize= 50;
    int ellipseX= (imgSizeW-(ellipseSize/2));
    int ellipseY= ((imgSizeH/2)-(ellipseSize/2));

    paint.drawImage(5,5,*img);
    paint.drawEllipse(ellipseX,ellipseY,ellipseSize,ellipseSize);
}

/*ImageLabel::ImageLabel(Plat p, QWidget *parent, int imgSizeW, int imgSizeH, QColor background): QLabel(parent){
    this->setFixedSize(150,150);

    //creating price Label
    QLabel *labelPrice = new QLabel(QString::number(p.getPrice()),this);
    QFont priceFont("Helvetica", 12, QFont::Bold);
    labelPrice->setFont(priceFont);
    //labelPrice->move(this->x()-150,(this->y()/2)-10);

    int imageWidth = 128;
    int imageHeight = 128;
    QString imageCssCode = "<img src='" + p.getImagePath() + "' width=\"" + QVariant(imageWidth).toString() + "\"" + " height=\"" + QVariant(imageHeight).toString() + "\" />";
    qDebug() << imageCssCode;
    this->setText(imageCssCode);
}*/

/*void ImageLabel::paintEvent(QPaintEvent *e){
    QLabel::paintEvent(e);
    //creating price circle
    QImage tmp(this->pixmap()->toImage());
    QPainter paint(&tmp);

    QColor orange(255,165,0,255);
    QBrush orangeBrush(orange);
    QPen outlinePen(orange);
    paint.setBrush(orangeBrush);
    paint.setPen(outlinePen);
    int ellipseSize = 100;
    int ellipseX = 100;
    int ellipseY = 100;
    //qDebug() << this->size();
    //int ellipseX = (tmp.size().width()-(ellipseSize/2));
    //int ellipseY = ((tmp.size().height()/2)-(ellipseSize/2));
    paint.drawEllipse(ellipseX, ellipseY, ellipseSize, ellipseSize);
    this->setPixmap(QPixmap::fromImage(tmp));
}*/

/*void ImageLabel::paintEvent(QPaintEvent *)
{
    //creation image
    this->imgSizeW= imgSizeW;
    this->imgSizeH= imgSizeH;
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(background));
    QImage *img = new QImage(this->imagePath);
    *img = img->scaled(imgSizeW, imgSizeH);

    QColor orange(255,165,0,255);
    QBrush orangeBrush(orange);
    QPen outlinePen(orange);
    QPainter paint(this);
    paint.setBrush(orangeBrush);
    paint.setPen(outlinePen);
    int ellipseSize= 50;
    int ellipseX= (imgSizeW-(ellipseSize/2));
    int ellipseY= ((imgSizeH/2)-(ellipseSize/2));

    paint.drawImage(5,5,*img);
    paint.drawEllipse(ellipseX,ellipseY,ellipseSize,ellipseSize);

}*/





/*creating image autre façon
int imageWidth = 128;
int imageHeight = 128;
QString imageCssCode = "<img src='" + plat.getImagePath() + "' width=\"" + QVariant(imageWidth).toString() + "\"" + " height=\"" + QVariant(imageHeight).toString() + "\" />";
this->setText(imageCssCode);
//QLabel = new QLabel(imageCss)


    //this->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    QPixmap pm1(p.getImagePath());
    //pm1.scaled(QSize(imgSizeW, imgSizeH));
    this->setPixmap(pm1);
    this->adjustSize();
    this->setScaledContents(true);*/
