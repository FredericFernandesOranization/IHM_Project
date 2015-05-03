#include "detaileditem.h"

/*DetailedItem::DetailedItem(Plat plat,int imgSizeW ,int imgSizeH, QColor background, QWidget *parent) : QWidget(parent)
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
}*/

DetailedItem::DetailedItem(Plat plat,int imgSizeW ,int imgSizeH, QColor background, QWidget *parent) : QWidget(parent)
{
    //detailed item properties
    QHBoxLayout *itemLayout = new QHBoxLayout;
    this->setLayout(itemLayout);
    this->plat = plat;
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(70,130,180)));
    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    //creating buttons
    QPushButton* commander = new QPushButton(QString("commander"));
    this->backButton = new BackButton(QString("Back"));

    //creating image
    this->image = new ImageLabel(plat, imgSizeW, imgSizeH, background, this);

    //creating name Label
    QLabel *nameLabel = new QLabel(plat.getName(),this);
    QFont shortDescFont("Helvetica", 80);
    nameLabel->setFont(shortDescFont);
    QPalette pal(nameLabel->palette());
    pal.setColor(QPalette::WindowText, QColor(Qt::white));
    nameLabel->setPalette(pal);
    //nameLabel->setStyleSheet("font-family: Arial,sans-serif;font: Helvetica; padding-top: 7px; text-align: center;color: #000; border-radius: 8px;");


    //creating description Label
    QLabel *descriptionLabel = new QLabel(plat.getDescription(),this);
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

    //setting item layout and adding components
    itemLayout->addWidget(leftPart);
    itemLayout->addWidget(rightPart);


}

BackButton* DetailedItem::getBackButton(){ return this->backButton; }




