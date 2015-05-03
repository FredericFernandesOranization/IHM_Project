#include "leftzone.h"

LeftZone::LeftZone() : QWidget()
{
    //Left Zone Properties
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    //this->resize(500, 100);
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(70,130,180)));
    //this->setStyleSheet("background-color: rgb(70,130,180)");
    this->setSizePolicy(sizePolicy);

    //separation SwapButton - Command Zone
    QVBoxLayout *leftVerticalLayout = new QVBoxLayout;
    //leftVerticalLayout->sizeConstraint();
    //leftVerticalLayout->setSpacing(0);
    this->setLayout(leftVerticalLayout);

    //Creating Swap Button
    switchButton = new MenuButton("Switch Button", this);
    switchButton->setFixedHeight(100);
    switchButton->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    leftVerticalLayout->addWidget(switchButton);
    //switchButton->setStyleSheet("border: none; background-color: orange; padding: 6px;");
    switchButton->setStyleSheet("font-family: Arial,sans-serif;font: bold;width: 200px;height: 43px;padding-top: 7px;text-align: center;color: #000; background: rgb(255,158,65);border-radius: 8px;");


    //Creating the area to swap (commandBar and MenuBar)
    QWidget *leftBar = new QWidget;
    leftZoneStackedLayout = LeftBarLayout::getInstance();
    leftBar->setLayout(leftZoneStackedLayout);


    //Creating Left Menu Bar
    QWidget *menuBar = new QWidget;
    QVBoxLayout *menuBarLayout = new QVBoxLayout;
    menuBar->setLayout(menuBarLayout);
    this->buttonLists = QList<MenuButton*>();
    QList<QString> stringMenu = QList<QString>() << QString("Boissons") << QString("Entrees") << QString("Plats") << QString("Desserts");
    for(int i=0; i<4; i++){
        MenuButton *b = new MenuButton(stringMenu.at(i), this);
        buttonLists.append(b);       
        connect(b, SIGNAL(clicked()), b, SLOT(onClick()));
        connect(b, SIGNAL(setUnclicked(QString)), this, SLOT(getUnclicked(QString)));
        b->setFixedWidth(280);
        b->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        menuBarLayout->addWidget(b);
    }
    leftZoneStackedLayout->addWidget(menuBar);

    //Creating Command Bar
    QScrollArea *commandBarScrollArea = new QScrollArea;
    commandBarScrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    //commandBarScrollArea->setFixedHeight(400);
    QWidget *commandBar = new QWidget;
    QVBoxLayout *commandBarLayout = new QVBoxLayout;
    commandBar->setLayout(commandBarLayout);
    commandBarScrollArea->setWidget(commandBar);
    commandBarScrollArea->setWidgetResizable(true);
    //commandBarScrollArea->setLayout(commandBarLayout);
    this->buttonLists = QList<MenuButton*>();
    QList<QString> stringCommand = QList<QString>() << QString("PEUT IMPORTE") << QString("JE SAIS PAS QUOI") << QString("VOIR TOTAL") << QString("COMMANDER");
    for(int i=0; i<4; i++){
        MenuButton *b = new MenuButton(stringCommand.at(i), this);

        buttonLists.append(b);
        connect(b, SIGNAL(clicked()), b, SLOT(onClick()));
        connect(b, SIGNAL(setUnclicked(QString)), this, SLOT(getUnclicked(QString)));

        //connect(b, SIGNAL(clicked()), b, SLOT(onClick()));
        //connect(b, SIGNAL(setUnclicked(QString)), this, SLOT(getUnclicked(QString)));

        b->setFixedWidth(280);
        //b->setFixedHeight(200);
        b->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        commandBarLayout->addWidget(b);
    }

    leftZoneStackedLayout->addWidget(commandBarScrollArea);
    connect(switchButton, SIGNAL(clicked()), switchButton, SLOT(changeLayout()));
    //leftZoneStackedLayout->setCurrentIndex(1);
    leftVerticalLayout->addWidget(leftBar);
    QPushButton *commandButton = new QPushButton("Commander", this);
    connect(commandButton,SIGNAL(clicked()),this,SLOT(openConfirmWindow()));
    commandButton->setFixedHeight(100);
    commandButton->setStyleSheet("font-family: Arial,sans-serif;font: bold;width: 200px;height: 43px;padding-top: 7px;text-align: center;color: #000; background: rgb(255,158,65);border-radius: 8px;");
    leftVerticalLayout->addWidget(commandButton);
}






void LeftZone::getUnclicked(QString label)
{
    qDebug() << "receiving SIGNAL from BUTTON!";
    for(int i=0; i<4; i++){
        MenuButton* button = this->buttonLists.at(i);
        if(button->getLabel().compare(label) == false){
            qDebug() << "dentro l'if!";
            //button->setStyleSheet("background-color: rgb(70,130,180)");
            //this->setAutoFillBackground(true);
            this->setPalette(QPalette(QColor(70,130,180)));
        }
    }
        /*if(this->label != label){
        this->setAutoFillBackground(true);
        this->setPalette(QPalette(QColor(70,130,180)));
    }*/
}

void LeftZone::openConfirmWindow(){
    ConfirmDialog *conf = new ConfirmDialog(this);
    conf->show();
}
