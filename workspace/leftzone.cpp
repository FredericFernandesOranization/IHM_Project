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
    switchButton->setStyleSheet("border: none; background-color: orange; padding: 6px;");

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

        //connect(b, SIGNAL(clicked()), b, SLOT(onClick()));
        //connect(b, SIGNAL(setUnclicked(QString)), this, SLOT(getUnclicked(QString)));

        b->setFixedWidth(280);
        b->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        menuBarLayout->addWidget(b);
    }
    leftZoneStackedLayout->addWidget(menuBar);

    //Creating Command Bar

    QWidget *commandBar = new QWidget;
    QVBoxLayout *commandBarLayout = new QVBoxLayout;
    commandBar->setLayout(commandBarLayout);
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
        b->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
        commandBarLayout->addWidget(b);
    }
    leftZoneStackedLayout->addWidget(commandBar);
    leftZoneStackedLayout->setCurrentIndex(1);
    connect(switchButton, SIGNAL(clicked()), switchButton, SLOT(changeLayout()));
    //leftZoneStackedLayout->setCurrentIndex(1);
    leftVerticalLayout->addWidget(leftBar);
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
