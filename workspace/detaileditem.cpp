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
    QLabel *labelShortDesc = new QLabel(plat.getDescription(),this);
    labelShortDesc->setFont(shortDescFont);
    labelShortDesc->setPalette(QPalette(Qt::white));
    labelShortDesc->setPalette(pal);
    labelShortDesc->setMaximumWidth(imgSizeW);

    //setting item layout and adding components
    QHBoxLayout *itemLayout = new QHBoxLayout;
    this->setLayout(itemLayout);
    itemLayout->addWidget(image);
    itemLayout->addWidget(labelShortDesc);
    itemLayout->addWidget(commander);
    itemLayout->addWidget(backButton);
}

BackButton* DetailedItem::getBackButton(){ return this->backButton; }


