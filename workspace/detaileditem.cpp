#include "detaileditem.h"
DetailedItem* DetailedItem::instance = NULL;

DetailedItem::DetailedItem(Plat plat,int imgSizeW ,int imgSizeH, QColor background, QWidget *parent) : QWidget(parent)
{
    //detailed item properties
    this->plat = Plat(plat);
    QHBoxLayout *itemLayout = new QHBoxLayout;
    this->setLayout(itemLayout);
    this->plat = plat;
    this->background = QColor(background);
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(70,130,180)));

    this->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    //creating buttons
    this->commander = new CommanderButton(QString("AJOUTER AU PANIER"));
    this->commander->setPlat(Plat(plat));
    this->commander->setStyleSheet("font-size: 30pt; font-family: Arial,sans-serif;font: bold; text-align: center;color: white; background: rgb(255,158,65); border-radius: 8px;");
    this->backButton = new BackButton(QString("RETOUR"));
    this->backButton->setStyleSheet("font-size: 30pt; font : bold;font-family: Arial,sans-serif; border-width: 1px; background-color: rgb(60,68,84); text-align: center;color: white; border-radius: 8px; border-width: 2px;");



    //creating image
    this->image = new ImageLabel(this->plat, 430, 290, background, this);

    //creating name Label
    QLabel *nameLabel = new QLabel();
    nameLabel->setText("<a style=\"font-size: 30pt; font : bold;font-family: Arial,sans-serif; font: bold; background: rgb(70,130,180);\">" + this->plat.getName() + "</a>");
    nameLabel->setAlignment(Qt::AlignCenter);
    //QFont shortDescFont("Helvetica", 30);
    //nameLabel->setFont(shortDescFont);
    QPalette pal(nameLabel->palette());
    pal.setColor(QPalette::WindowText, QColor(Qt::white));
    nameLabel->setPalette(pal);
    nameLabel->setStyleSheet("margin-left: 3");
    //nameLabel->setStyleSheet("font-family: Arial,sans-serif;font: Helvetica; padding-top: 7px; text-align: center;color: #000; border-radius: 8px;");

    //create intestation
    QLabel *intestation = new QLabel();
    intestation->setText("<a style=\"font-size: 25pt; font : bold; color: white; font-family: Arial,sans-serif; font: bold; background: rgb(70,130,180);\">DESCRIPTION</a>");
    intestation->setAlignment(Qt::AlignCenter);


    //creating description Label
    QLabel *descriptionLabel = new QLabel(this->plat.getDescription(),this);
    descriptionLabel->setText("<a style=\"font-size: 20pt; font : bold;font-family: Arial,sans-serif; font: bold; background: rgb(70,130,180);\">" + this->plat.getDescription() + "</a>");
    descriptionLabel->setAlignment(Qt::AlignJustify);
    //QFont descriptionLabelFont("Helvetica", 20);
    descriptionLabel->setWordWrap(true);
    //descriptionLabel->setFont(descriptionLabelFont);
    descriptionLabel->setPalette(QPalette(Qt::white));
    descriptionLabel->setPalette(pal);
    descriptionLabel->setMaximumWidth(imgSizeW-35);
    descriptionLabel->setAlignment(Qt::AlignJustify);
    //descriptionLabel->setStyleSheet("text: 65");
    //descriptionLabel->setStyleSheet("font-family: Arial,sans-serif;font: Helvetica; padding-top: 7px; text-align: center;color: #000; border-radius: 8px;");

    //division left - right part
    QWidget* leftPart = new QWidget; //creating left part
    this->leftPartLayout = new FlowLayout;
    leftPart->setLayout(leftPartLayout);
    leftPartLayout->addWidget(image);
    leftPartLayout->addWidget(nameLabel);

    QWidget* rightPart = new QWidget; //creating right part
    QVBoxLayout *rightPartLayout = new QVBoxLayout;
    rightPart->setLayout(rightPartLayout);
    rightPartLayout->addWidget(intestation);
    rightPartLayout->addWidget(descriptionLabel);
    rightPartLayout->addWidget(backButton);
    rightPartLayout->addWidget(commander);

    //setting item layout and adding components
    itemLayout->addWidget(leftPart);
    itemLayout->addWidget(rightPart);
}

CommanderButton *DetailedItem::getAjouterButton()
{
    return this->commander;
}

void DetailedItem::update(){
    this->plat = Plat(plat);
    //detailed item properties
    this->commander->setPlat(plat);

    //creating image
    //this->leftPartLayout->removeWidget(this->image);
    ImageLabel* from = this->image;
    this->image = new ImageLabel(this->plat, 450, 300, this->background, this);
    this->leftPartLayout->replaceWidget(from, this->image);

    //creating name Label
    QLabel *nameLabel = new QLabel(this->plat.getName(),this);
    //nameLabel->setStyleSheet("font-family: Arial,sans-serif;font: Helvetica; padding-top: 7px; text-align: center;color: #000; border-radius: 8px;");

    //creating description Label
    QLabel *descriptionLabel = new QLabel(this->plat.getDescription(),this);
    //descriptionLabel->setStyleSheet("font-family: Arial,sans-serif;font: Helvetica; padding-top: 7px; text-align: center;color: #000; border-radius: 8px;");
}

BackButton* DetailedItem::getBackButton(){ return this->backButton; }

CommanderButton *DetailedItem::getCommanderButton(){ return this->commander; }

void DetailedItem::setPlat(Plat p)
{
    this->plat = Plat(p);
}

Plat DetailedItem::getPlat()
{
    return this->plat;
}

void DetailedItem::setInstance(DetailedItem *d)
{
    this->instance = d;
}
