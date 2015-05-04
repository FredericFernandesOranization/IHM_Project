#include "detaileditem.h"

DetailedItem* DetailedItem::instance = NULL;

DetailedItem::DetailedItem(Plat plat,int imgSizeW ,int imgSizeH, QColor background, QWidget *parent) : QWidget(parent)
{
    this->plat = plat;
    //detailed item properties
    QHBoxLayout *itemLayout = new QHBoxLayout;
    this->setLayout(itemLayout);
    this->plat = plat;
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(70,130,180)));
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    //creating buttons
    this->commander = new CommanderButton(QString("commander"));
    this->commander->setPlat(plat);
    this->backButton = new BackButton(QString("Back"));

    //creating image
    this->image = new ImageLabel(this->plat, imgSizeW, imgSizeH, background, this);

    //creating name Label
    QLabel *nameLabel = new QLabel(this->plat.getName(),this);
    QFont shortDescFont("Helvetica", 80);
    nameLabel->setFont(shortDescFont);
    QPalette pal(nameLabel->palette());
    pal.setColor(QPalette::WindowText, QColor(Qt::white));
    nameLabel->setPalette(pal);
    //nameLabel->setStyleSheet("font-family: Arial,sans-serif;font: Helvetica; padding-top: 7px; text-align: center;color: #000; border-radius: 8px;");


    //creating description Label
    QLabel *descriptionLabel = new QLabel(this->plat.getDescription(),this);
    QFont descriptionLabelFont("Helvetica", 25);
    descriptionLabel->setWordWrap(true);
    descriptionLabel->setFont(descriptionLabelFont);
    descriptionLabel->setPalette(QPalette(Qt::white));
    descriptionLabel->setPalette(pal);
    descriptionLabel->setMaximumWidth(imgSizeW-35);
    //descriptionLabel->setStyleSheet("font-family: Arial,sans-serif;font: Helvetica; padding-top: 7px; text-align: center;color: #000; border-radius: 8px;");


    //division left - right part
    QWidget* leftPart = new QWidget; //creating left part
    FlowLayout *leftPartLayout = new FlowLayout;
    leftPart->setLayout(leftPartLayout);
    leftPartLayout->addWidget(image);
    leftPartLayout->addWidget(nameLabel);

    QWidget* rightPart = new QWidget; //creating right part
    FlowLayout *rightPartLayout = new FlowLayout;
    rightPart->setLayout(rightPartLayout);
    rightPartLayout->addWidget(descriptionLabel);
    rightPartLayout->addWidget(backButton);
    rightPartLayout->addWidget(commander);


    //setting item layout and adding components
    itemLayout->addWidget(leftPart);
    itemLayout->addWidget(rightPart);
}
/*
DetailedItem::DetailedItem(Plat *plat,int imgSizeW ,int imgSizeH, QColor background, QWidget *parent) : QWidget(parent)
{
    //item properties
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(70,130,180)));
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    //attributes initialization
    this->itemLayout = new QHBoxLayout;
    this->imgSizeH = imgSizeH;
    this->imgSizeW = imgSizeW;
    this->background = background;
    this->setPlat(plat);
}
*/


BackButton* DetailedItem::getBackButton(){ return this->backButton; }

CommanderButton *DetailedItem::getCommanderButton(){ return this->commander; }

Plat DetailedItem::getPlat()
{
    return this->plat;
}
