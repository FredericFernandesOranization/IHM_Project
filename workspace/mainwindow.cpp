#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QWidget *mainWidget = new QWidget();
    mainWidget->setMinimumSize(1000,550);
    mainWidget->setStyleSheet("background-color: Red");
    mainWidget->setStyleSheet("background-image: url(:/images/lightB.png)");

    //QHBoxLayout *mainLayout = new QHBoxLayout;
    QHBoxLayout *mainLayout = new QHBoxLayout (mainWidget);

    //mainWidget->setLayout(mainLayout);

    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);



// THE LEFT PART OF THE SCREEN

    QWidget *leftZoneWidget = new QWidget();
    leftZoneWidget->resize(500, 100);
    //leftZoneWidget->setStyleSheet("background-color: Orange");
    leftZoneWidget->setStyleSheet("background-image: url(:/images/lightB.png)");

    leftZoneWidget->setSizePolicy(sizePolicy);
    QVBoxLayout *leftVerticalLayout = new QVBoxLayout;
    leftVerticalLayout->sizeConstraint();
    leftVerticalLayout->setSpacing(0);
    leftZoneWidget->setLayout(leftVerticalLayout);

    QPushButton *switchButton = new QPushButton("Switch Button", this);
    switchButton->setFixedHeight(100);
    //switchButton->setFixedSize(300,90);
    switchButton->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Maximum);
    //switchButton->setStyleSheet("background-color: Blue");
    switchButton->setStyleSheet("background-image: url(:/images/middleEarth.jpg)");




//    QScrollArea *leftVScrollArea = new QScrollArea;
//    leftVScrollArea->resize(330,900);
//    leftVScrollArea->setBackgroundRole(QPalette::Dark);
//    leftVScrollArea->setStyleSheet("background-color : white");

//    leftVScrollArea->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);

    //QWidget *leftVScrollAreaWidget = new QWidget();
    //leftVScrollAreaWidget->setStyleSheet("background-color: Green");
    //leftVScrollAreaWidget->setStyleSheet("background-image: url(:/images/lightB.png)");

    //leftVScrollAreaWidget->resize(300,900);
    //leftVScrollArea->setWidget(leftVScrollAreaWidget);


    leftVerticalLayout->addWidget(switchButton);
    //leftVerticalLayout->addWidget(leftZoneWidget);

//    QVBoxLayout *verticalScrollAreaLayout = new QVBoxLayout;

//    leftVScrollAreaWidget->setLayout(verticalScrollAreaLayout);


    QPushButton *b1 = new QPushButton("Vertical Button 1", this);
    //b1->setFixedSize(300,90);
    b1->setFixedWidth(280);
    b1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b2 = new QPushButton("Vertical Button 2", this);
    b2->setFixedWidth(280);
    //b2->setFixedSize(300,90);
    b2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b3 = new QPushButton("Vertical Button 3", this);
    b3->setFixedWidth(280);
    //b3->setFixedSize(300,90);
    b3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b4 = new QPushButton("Vertical Button 4", this);
    b4->setFixedWidth(280);
    //b4->setFixedSize(300,90);
    b4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b5 = new QPushButton("Vertical Button 5", this);
    b5->setFixedWidth(280);
    //b5->setFixedSize(300,90);
    b5->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b6 = new QPushButton("Vertical Button 6", this);
    b6->setFixedWidth(280);
    //b6->setFixedSize(300,90);
    b6->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b7 = new QPushButton("Vertical Button 7", this);
    b7->setFixedWidth(280);
    //b7->setFixedSize(300,90);
    b7->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b8 = new QPushButton("Vertical Button 8", this);
    b8->setFixedWidth(280);
    //b8->setFixedSize(300,90);
    b8->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b9 = new QPushButton("Vertical Button 9", this);
    b9->setFixedWidth(280);
    //b9->setFixedSize(300,90);
    b9->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);


    leftVerticalLayout->addWidget(b1);
    leftVerticalLayout->addWidget(b2);
    leftVerticalLayout->addWidget(b3);
    leftVerticalLayout->addWidget(b4);
    leftVerticalLayout->addWidget(b5);
    leftVerticalLayout->addWidget(b6);
    leftVerticalLayout->addWidget(b7);


//    verticalScrollAreaLayout->addWidget(b1);
//    verticalScrollAreaLayout->addWidget(b2);
//    verticalScrollAreaLayout->addWidget(b3);
//    verticalScrollAreaLayout->addWidget(b4);
//    verticalScrollAreaLayout->addWidget(b5);
//    verticalScrollAreaLayout->addWidget(b6);
//    verticalScrollAreaLayout->addWidget(b7);
//    verticalScrollAreaLayout->addWidget(b8);
//    verticalScrollAreaLayout->addWidget(b9);



// THE RIGHT PART OF THE SCREEN

    QWidget *rightZoneWidget = new QWidget();
    rightZoneWidget->resize(1000,50);
    rightZoneWidget->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    rightZoneWidget->setStyleSheet("background-color: Yellow");
    rightZoneWidget->setStyleSheet("background-image: url(:/images/lightB.png)");

    QVBoxLayout *rightVerticalLayout = new QVBoxLayout;
    rightZoneWidget->setLayout(rightVerticalLayout);

//    QScrollArea *rightHScrollArea = new QScrollArea;
//    //rightHScrollArea->setStyleSheet("background-color: Gray");
//    rightHScrollArea->setStyleSheet("background-image: url(:/images/aa.jpg)");

   // rightHScrollArea->resize(80,10);
//    rightHScrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
//    rightHScrollArea->setBackgroundRole(QPalette::Dark);


    QWidget *rightHScrollAreaWidget = new QWidget;
    rightHScrollAreaWidget->setStyleSheet("padding : 0 ; margin : 0");

    rightHScrollAreaWidget->setFixedHeight(100);
    //rightHScrollAreaWidget->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);

    QHBoxLayout *rightHorizontalLayout = new QHBoxLayout;
    rightHorizontalLayout->setSpacing(0);
    //horizontalScrollAreaLayout->addWidget(rightHScrollAreaWidget);

    rightHScrollAreaWidget->setLayout(rightHorizontalLayout);

//    rightHScrollArea->setWidget(rightHScrollAreaWidget);

    QPushButton *hb1 = new QPushButton("Horizontal Bouton 1", this);
    hb1->setStyleSheet("font : bold large");
    hb1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //hb1->setFixedSize(300,90);

    QPushButton *hb2 = new QPushButton("Horizontal Bouton 2", this);
    hb2->setStyleSheet("font : bold large");
    hb2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //hb2->setFixedSize(300,90);

    QPushButton *hb3 = new QPushButton("Horizontal Bouton 3", this);
    hb3->setStyleSheet("font : bold large");
    hb3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //hb3->setFixedSize(300,90);

    QPushButton *hb4 = new QPushButton("Horizontal Bouton 4", this);
    hb4->setStyleSheet("font : bold large");
    hb4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    //hb4->setFixedSize(300,90);

    QPushButton *hb5 = new QPushButton("Horizontal Bouton 5", this);
    hb5->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    hb5->setFixedSize(300,90);

    QPushButton *hb6 = new QPushButton("Horizontal Bouton 6", this);
    hb6->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    hb6->setFixedSize(300,90);

    QPushButton *hb7 = new QPushButton("Horizontal Bouton 7", this);
    hb7->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    hb7->setFixedSize(300,90);




    rightHorizontalLayout->addWidget(hb1);
    rightHorizontalLayout->addWidget(hb2);
    rightHorizontalLayout->addWidget(hb3);
    rightHorizontalLayout->addWidget(hb4);


    //rightVerticalLayout->addLayout(horizontalScrollAreaLayout);
    rightVerticalLayout->addWidget(rightHScrollAreaWidget);

    QWidget *mainButton = new QWidget();
    //mainButton->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    QVBoxLayout *leftMainVerticalLayout = new QVBoxLayout;
    mainButton->setLayout(leftMainVerticalLayout);

    QPushButton *mb1 = new QPushButton("Main Bouton 1", this);
    mb1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    mb1->setFixedSize(150,150);

    QPushButton *mb2 = new QPushButton("Main Bouton 2", this);
    mb2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    mb2->setFixedSize(150,150);

    QPushButton *mb3 = new QPushButton("Main Bouton 3", this);
    mb3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    mb3->setFixedSize(150,150);

    QPushButton *mb4 = new QPushButton("Main Bouton 4", this);
    mb4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    mb4->setFixedSize(150,150);

    leftMainVerticalLayout->addWidget(mb1);
    leftMainVerticalLayout->addWidget(mb2);
    leftMainVerticalLayout->addWidget(mb3);
    leftMainVerticalLayout->addWidget(mb4);
    mainButton->setStyleSheet("background-image: url(:/images/lightB.png)");
    rightVerticalLayout->addWidget(mainButton);




    mainLayout->addWidget(leftZoneWidget);
    mainLayout->addWidget(rightZoneWidget);
    setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
