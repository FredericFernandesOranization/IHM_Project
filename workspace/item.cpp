#include "item.h"

Item::Item(Plat plat,int imgSizeW,int imgSizeH ,QColor background, QWidget *parent): QWidget(parent)
{
    //order button
    QPushButton* commander = new QPushButton("Commander");

    //creating image
    ImageLabel* image = new ImageLabel(plat, imgSizeW, imgSizeH, background, this);

    //creating short description
    QLabel *labelShortDesc = new QLabel(plat.getName(),this);
    //QLabel *labelShortDesc = new QLabel(plat.getShortDescription(),this);
    QFont shortDescFont("Helvetica", 12);
    labelShortDesc->setFont(shortDescFont);
    labelShortDesc->setPalette(QPalette(Qt::white));
    QPalette pal(labelShortDesc->palette());
    pal.setColor(QPalette::WindowText, QColor(Qt::white));
    labelShortDesc->setPalette(pal);
    labelShortDesc->setMaximumWidth(imgSizeW);
    //labelShortDesc->move(10,imgSizeH+5);

    //setting item layout and adding components
    QVBoxLayout *itemLayout = new QVBoxLayout;
    this->setLayout(itemLayout);
    itemLayout->addWidget(image);
    itemLayout->addWidget(labelShortDesc);
    itemLayout->addWidget(commander);

}
/*
void Item::paintEvent(QPaintEvent *)
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

    //paint.drawImage(5,5,*img);
    paint.drawEllipse(ellipseX,ellipseY,ellipseSize,ellipseSize);

}*/


/*
      //setFixedSize(imgSizeW+150,imgSizeH+100);


    //creation image
    /*this->imgSizeW= imgSizeW;
    this->imgSizeH= imgSizeH;
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(background));
    img = new QImage(plat.getImagePath());
    *img = img->scaled(imgSizeW, imgSizeH);
*/


    /*QGraphicsEllipseItem *ellipse =*/
    //addEllipse((imgSizeW-(elSize/2)), ((imgSizeH/2)-(elSize/2)), elSize, elSize, outlinePen, greenBrush);
    //ellipse->setFlag(QGraphicsItem::ItemIsMovable);

    //QGraphicsTextItem * price =  addText();
    //    QFont priceFont("Helvetica", 12, QFont::Bold);
    //    price->setFont(priceFont);
    //    price->setPos((imgSizeW)-16,(imgSizeH/2)-10);
    //    this->addItem(price);

    //labelShortDesc->setFixedWidth(imgSizeW);
    //labelShortDesc->show();
    //labelShortDesc->setFWidth(imgSizeW);

    //QRectF rec = labelShortDesc->boundingRect();
    //this->addItem(shortDesc);
//labelShortDesc->move((imgSizeW)-16,(imgSizeH/2)-10);
//labelShortDesc->setWordWrap(true);
// labelShortDesc->setLineWidth(imgSizeH);

