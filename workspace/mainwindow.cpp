#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include <QListWidget>
#include <QListWidgetItem>
#include "item.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *mainWidget = new QWidget();
    mainWidget->setMinimumSize(1000,550);
    mainWidget->setStyleSheet("background-color: Red");
    mainWidget->setStyleSheet("background-image: url(:/images/Elegant_Background-3_grey.jpg)");

    //QHBoxLayout *mainLayout = new QHBoxLayout;
    QHBoxLayout *mainLayout = new QHBoxLayout (mainWidget);

    //mainWidget->setLayout(mainLayout);

    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);



// THE LEFT PART OF THE SCREEN

    QWidget *leftZoneWidget = new QWidget();
    leftZoneWidget->resize(500, 100);
    //leftZoneWidget->setStyleSheet("background-color: Orange");
    leftZoneWidget->setStyleSheet("background-image: url(:/images/Elegant_Background-3_grey.jpg)");

    leftZoneWidget->setSizePolicy(sizePolicy);
    QVBoxLayout *leftVerticalLayout = new QVBoxLayout;
    leftVerticalLayout->sizeConstraint();
    leftZoneWidget->setLayout(leftVerticalLayout);

    QPushButton *switchButton = new QPushButton("Switch Button", this);
    //switchButton->resize(300, 250);
    switchButton->setFixedSize(300,90);
    switchButton->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Maximum);
    //switchButton->setStyleSheet("background-color: Blue");
    switchButton->setStyleSheet("background-image: url(:/images/middleEarth.jpg)");




    QScrollArea *leftVScrollArea = new QScrollArea;
    leftVScrollArea->resize(330,900);
    leftVScrollArea->setBackgroundRole(QPalette::Dark);
    leftVScrollArea->setStyleSheet("background-color : white");

    leftVScrollArea->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    QWidget *leftVScrollAreaWidget = new QWidget();
    //leftVScrollAreaWidget->setStyleSheet("background-color: Green");
    leftVScrollAreaWidget->setStyleSheet("background-image: url(:/images/Elegant_Background-3_grey.jpg)");

    leftVScrollAreaWidget->resize(300,900);
    leftVScrollArea->setWidget(leftVScrollAreaWidget);


    leftVerticalLayout->addWidget(switchButton);
    leftVerticalLayout->addWidget(leftVScrollArea);

    QVBoxLayout *verticalScrollAreaLayout = new QVBoxLayout;

    leftVScrollAreaWidget->setLayout(verticalScrollAreaLayout);


    QPushButton *b1 = new QPushButton("Vertical Button 1", this);
     b1->setFixedSize(300,90);
    b1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b2 = new QPushButton("Vertical Button 2", this);
    b2->setFixedSize(300,90);
    b2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b3 = new QPushButton("Vertical Button 3", this);
    b3->setFixedSize(300,90);
    b3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b4 = new QPushButton("Vertical Button 4", this);
    b4->setFixedSize(300,90);
    b4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b5 = new QPushButton("Vertical Button 5", this);
    b5->setFixedSize(300,90);
    b5->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b6 = new QPushButton("Vertical Button 6", this);
    b6->setFixedSize(300,90);
    b6->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b7 = new QPushButton("Vertical Button 7", this);
    b7->setFixedSize(300,90);
    b7->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b8 = new QPushButton("Vertical Button 8", this);
    b8->setFixedSize(300,90);
    b8->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b9 = new QPushButton("Vertical Button 9", this);
    b9->setFixedSize(300,90);
    b9->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    verticalScrollAreaLayout->addWidget(b1);
    verticalScrollAreaLayout->addWidget(b2);
    verticalScrollAreaLayout->addWidget(b3);
    verticalScrollAreaLayout->addWidget(b4);
    verticalScrollAreaLayout->addWidget(b5);
    verticalScrollAreaLayout->addWidget(b6);
    verticalScrollAreaLayout->addWidget(b7);
    verticalScrollAreaLayout->addWidget(b8);
    verticalScrollAreaLayout->addWidget(b9);



// THE RIGHT PART OF THE SCREEN

    QWidget *rightZoneWidget = new QWidget();
    rightZoneWidget->resize(1000,50);
    rightZoneWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    rightZoneWidget->setStyleSheet("background-color: Yellow");
    rightZoneWidget->setStyleSheet("background-image: url(:/images/Elegant_Background-3_grey.jpg)");

    QVBoxLayout *rightVerticalLayout = new QVBoxLayout;
    rightZoneWidget->setLayout(rightVerticalLayout);

    QScrollArea *rightHScrollArea = new QScrollArea;
    //rightHScrollArea->setStyleSheet("background-color: Gray");
    rightHScrollArea->setStyleSheet("background-image: url(:/images/aa.jpg)");

   // rightHScrollArea->resize(80,10);
    rightHScrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    rightHScrollArea->setBackgroundRole(QPalette::Dark);


    QWidget *rightHScrollAreaWidget = new QWidget;
    rightHScrollAreaWidget->setStyleSheet("background-color: Grey");

    rightHScrollAreaWidget->resize(2000, 140);
    //rightHScrollAreaWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    QHBoxLayout *horizontalScrollAreaLayout = new QHBoxLayout;

    //horizontalScrollAreaLayout->addWidget(rightHScrollAreaWidget);

    rightHScrollAreaWidget->setLayout(horizontalScrollAreaLayout);

    rightHScrollArea->setWidget(rightHScrollAreaWidget);

    QPushButton *hb1 = new QPushButton("Horizontal Bouton 1", this);
    hb1->setStyleSheet("background-image: url(:/images/aa.jpg)");
    hb1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    hb1->setFixedSize(300,90);

    QPushButton *hb2 = new QPushButton("Horizontal Bouton 2", this);
    hb2->setStyleSheet("background-image: url(:/images/aa.jpg)");
    hb2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    hb2->setFixedSize(300,90);

    QPushButton *hb3 = new QPushButton("Horizontal Bouton 3", this);
    hb3->setStyleSheet("background-image: url(:/images/aa.jpg)");
    hb3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    hb3->setFixedSize(300,90);

    QPushButton *hb4 = new QPushButton("Horizontal Bouton 4", this);
    hb4->setStyleSheet("background-image: url(:/images/aa.jpg)");
    hb4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    hb4->setFixedSize(300,90);

    QPushButton *hb5 = new QPushButton("Horizontal Bouton 5", this);
    hb5->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    hb5->setFixedSize(300,90);

    QPushButton *hb6 = new QPushButton("Horizontal Bouton 6", this);
    hb6->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    hb6->setFixedSize(300,90);

    QPushButton *hb7 = new QPushButton("Horizontal Bouton 7", this);
    hb7->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    hb7->setFixedSize(300,90);

    horizontalScrollAreaLayout->addWidget(hb1);
    horizontalScrollAreaLayout->addWidget(hb2);
    horizontalScrollAreaLayout->addWidget(hb3);
    horizontalScrollAreaLayout->addWidget(hb4);
    horizontalScrollAreaLayout->addWidget(hb5);
    horizontalScrollAreaLayout->addWidget(hb6);
    horizontalScrollAreaLayout->addWidget(hb7);

    //rightVerticalLayout->addLayout(horizontalScrollAreaLayout);
    rightVerticalLayout->addWidget(rightHScrollArea);

    QPushButton *mainButton = new QPushButton("Main Button", this);
    mainButton->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    mainButton->setStyleSheet("background-image: url(:/images/wlp.jpg)");
    rightVerticalLayout->addWidget(mainButton);




    mainLayout->addWidget(leftZoneWidget);
    mainLayout->addWidget(rightZoneWidget);
    setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
