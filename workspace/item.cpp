#include "item.h"
#include <QPushButton>
#include <QGraphicsView>
#include <QDebug>
#include <QGraphicsItem>
#include<QListWidgetItem>


Item::Item(QString name): QListWidgetItem(), QGraphicsScene()
{
    //QPushButton *bouton = new QPushButton(name);
    //this->addWidget(bouton);


    QBrush greenBrush(Qt::green);
    QBrush blueBrush(Qt::blue);
    QPen outlinePen(Qt::black);
    outlinePen.setWidth(2);

    this->addRect(100, 0, 80, 100, outlinePen, blueBrush);
    this->addRect(100, 0, 100, 80, outlinePen, blueBrush);

    // addEllipse(x,y,w,h,pen,brush)
    this->addEllipse(0, -100, 300, 60, outlinePen, greenBrush);

    this->addText("bogotobogo.com", QFont("Arial", 20) );
    // movable text
    //text->setFlag(QGraphicsItem::ItemIsMovable);

}

Item::Item(Plat plat,int imgSizeW,int imgSizeH ,QColor background)
{
    qDebug()<<imgSizeW;
    this->imgSizeW= imgSizeW;
    this->imgSizeH= imgSizeH;

    int elSize= 50;
    setBackgroundBrush(QBrush(background, Qt::SolidPattern));
    qDebug()<< plat.getName();
    QImage *img = new QImage(plat.getImagePath());
    QImage img2 = img->scaled(imgSizeW, imgSizeH);
    addPixmap(QPixmap::fromImage(img2));
    QColor orange(255,165,0,255);
    QBrush greenBrush(orange);
    QPen outlinePen(orange);

    /*QGraphicsEllipseItem *ellipse =*/ addEllipse((imgSizeW-(elSize/2)), ((imgSizeH/2)-(elSize/2)), elSize, elSize, outlinePen, greenBrush);
    //ellipse->setFlag(QGraphicsItem::ItemIsMovable);
    //QGraphicsTextItem * price =  addText();

    QGraphicsTextItem * price = new QGraphicsTextItem(QString::number(plat.getPrice()));
    QFont priceFont("Helvetica", 12, QFont::Bold);
    price->setFont(priceFont);
    price->setPos((imgSizeW)-16,(imgSizeH/2)-10);
    this->addItem(price);

    QGraphicsTextItem * shortDesc = new QGraphicsTextItem(plat.getShortDescription());
    QFont shortDescFont("Helvetica", 12);
    shortDesc->setFont(shortDescFont);
    shortDesc->setDefaultTextColor(Qt::white);
    shortDesc->setTextWidth(imgSizeW);
    //shortDesc->setPen(QPen(QColor(255, 255, 255), 0.5, Qt::SolidLine, Qt::SquareCap, Qt::RoundJoin));
    shortDesc->setPos(10,imgSizeH+5);
    QRectF rec = shortDesc->boundingRect();
    this->addItem(shortDesc);

    setSceneRect(-10,-10,imgSizeW+50,imgSizeH+rec.height()+20);

}
void Item::show(QWidget *parent)
{
    QGraphicsView *view = new QGraphicsView(this,parent);
    view->setHorizontalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->setVerticalScrollBarPolicy ( Qt::ScrollBarAlwaysOff );
    view->show();
    //return view;
}
