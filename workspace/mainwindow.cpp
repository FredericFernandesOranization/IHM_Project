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
    //QHBoxLayout *mainLayout = new QHBoxLayout;
    QHBoxLayout *mainLayout = new QHBoxLayout (mainWidget);

    //mainWidget->setLayout(mainLayout);




// THE LEFT PART OF THE SCREEN

    QWidget *leftZoneWidget = new QWidget();
    leftZoneWidget->resize(600, 100);
    leftZoneWidget->setStyleSheet("background-color: Orange");

    QVBoxLayout *leftVerticalLayout = new QVBoxLayout;
    leftVerticalLayout->sizeConstraint();
    leftZoneWidget->setLayout(leftVerticalLayout);

    QPushButton *switchButton = new QPushButton("Switch Button", this);
    switchButton->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    switchButton->setStyleSheet("background-color: Blue");



    QScrollArea *leftVScrollArea = new QScrollArea;
    leftVScrollArea->resize(100,400);
    leftVScrollArea->setBackgroundRole(QPalette::Dark);
    leftVScrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget *leftVScrollAreaWidget = new QWidget();
    leftVScrollAreaWidget->setStyleSheet("background-color: Green");

    leftVScrollAreaWidget->resize(300,1000);
    leftVScrollArea->setWidget(leftVScrollAreaWidget);

    leftVerticalLayout->addWidget(leftVScrollArea);
    leftVerticalLayout->addWidget(switchButton);

    QVBoxLayout *verticalScrollAreaLayout = new QVBoxLayout;

    leftVScrollAreaWidget->setLayout(verticalScrollAreaLayout);


    QPushButton *b1 = new QPushButton("Vertical Button 1", this);
    b1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b2 = new QPushButton("Vertical Button 2", this);
    b2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b3 = new QPushButton("Vertical Button 3", this);
    b3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b4 = new QPushButton("Vertical Button 4", this);
    b4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b5 = new QPushButton("Vertical Button 5", this);
    b5->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b6 = new QPushButton("Vertical Button 6", this);
    b6->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b7 = new QPushButton("Vertical Button 7", this);
    b7->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b8 = new QPushButton("Vertical Button 8", this);
    b8->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *b9 = new QPushButton("Vertical Button 9", this);
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
    rightZoneWidget->resize(700,550);
    rightZoneWidget->setStyleSheet("background-color: Yellow");
    QVBoxLayout *rightVerticalLayout = new QVBoxLayout;
    rightZoneWidget->setLayout(rightVerticalLayout);

    QScrollArea *rightHScrollArea = new QScrollArea;
    rightHScrollArea->setStyleSheet("background-color: Gray");
    rightHScrollArea->resize(100,10);
    rightHScrollArea->setBackgroundRole(QPalette::Dark);
    //rightHScrollArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QWidget *rightHScrollAreaWidget = new QWidget;
    rightHScrollAreaWidget->setStyleSheet("background-color: Green");
    rightHScrollAreaWidget->resize(1000, 220);
    //rightHScrollArea->show();

    QHBoxLayout *horizontalScrollAreaLayout = new QHBoxLayout;

    //horizontalScrollAreaLayout->addWidget(rightHScrollAreaWidget);

    rightHScrollAreaWidget->setLayout(horizontalScrollAreaLayout);

    rightHScrollArea->setWidget(rightHScrollAreaWidget);

    QPushButton *hb1 = new QPushButton("Horizontal Bouton 1", this);
    hb1->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *hb2 = new QPushButton("Horizontal Bouton 2", this);
    hb2->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *hb3 = new QPushButton("Horizontal Bouton 3", this);
    hb3->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *hb4 = new QPushButton("Horizontal Bouton 4", this);
    hb4->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *hb5 = new QPushButton("Horizontal Bouton 5", this);
    hb5->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *hb6 = new QPushButton("Horizontal Bouton 6", this);
    hb6->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

    QPushButton *hb7 = new QPushButton("Horizontal Bouton 7", this);
    hb7->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);

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
    mainButton->setStyleSheet("background-color : Purple");
    rightVerticalLayout->addWidget(mainButton);




    mainLayout->addWidget(leftZoneWidget);
    mainLayout->addWidget(rightZoneWidget);
    setCentralWidget(mainWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
