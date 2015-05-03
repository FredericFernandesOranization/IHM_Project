#include "detaileditem.h"

DetailedItem::DetailedItem(Plat plat,int imgSizeW ,int imgSizeH, QColor background, QWidget *parent) : QWidget(parent)
{
    //detailed item properties
    this->plat = plat;
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(70,130,180)));
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    //creating buttons
    QPushButton* commander = new QPushButton(QString("commander"));
    this->backButton = new BackButton(QString("Back"));

    //creating image
    this->image = new ImageLabel(plat, imgSizeW, imgSizeH, background, this);

    //creating name Label
    QLabel *nameLabel = new QLabel(plat.getName(),this);
    QFont shortDescFont("Helvetica", 12);
    nameLabel->setFont(shortDescFont);
    QPalette pal(nameLabel->palette());
    pal.setColor(QPalette::WindowText, QColor(Qt::white));
    nameLabel->setPalette(pal);

    //creating description Label
    QLabel *descriptionLabel = new QLabel(plat.getDescription(),this);
    descriptionLabel->setFont(shortDescFont);
    descriptionLabel->setPalette(QPalette(Qt::white));
    descriptionLabel->setPalette(pal);
    descriptionLabel->setMaximumWidth(imgSizeW);


    //division left - right part
    QWidget* leftPart = new QWidget; //creating left part
    QVBoxLayout *leftPartLayout = new QVBoxLayout;
    leftPart->setLayout(leftPartLayout);
    leftPartLayout->addWidget(image);
    leftPartLayout->addWidget(nameLabel);

    QWidget* rightPart = new QWidget; //creating right part
    QVBoxLayout *rightPartLayout = new QVBoxLayout;
    rightPart->setLayout(rightPartLayout);
    rightPartLayout->addWidget(descriptionLabel);
    rightPartLayout->addWidget(backButton);

    //setting item layout and adding components
    QHBoxLayout *itemLayout = new QHBoxLayout;
    this->setLayout(itemLayout);
    itemLayout->addWidget(leftPart);
    itemLayout->addWidget(rightPart);


}

BackButton* DetailedItem::getBackButton(){ return this->backButton; }


