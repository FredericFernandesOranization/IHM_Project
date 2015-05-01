#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Creation Main Window
    QWidget *mainWindow = new QWidget();
    mainWindow->setMinimumSize(1000,550);
    mainWindow->setAutoFillBackground(true);
    mainWindow->setPalette(QPalette(Qt::gray));
    //mainWindow->setStyleSheet("background-color: Grey");
    //mainWindow->setStyleSheet("background-image: url(:/images/lightB.png)");

    //Separation Left (Command Zone and Swap Button) - Right (UpperMenu and Gallery) with Horizontal Layout
    QHBoxLayout *mainWindowLayout = new QHBoxLayout (mainWindow);
    QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    mainWindowLayout->setSpacing(5);

    //Creating Left Zone (Command Zone and Swap Button)
    LeftZone *leftZone = new LeftZone();
    mainWindowLayout->addWidget(leftZone);

    //Creating Right Zone (UpperMenu and Gallery)
    RightZone *rightZone = new RightZone();
    mainWindowLayout->addWidget(rightZone);

    setCentralWidget(mainWindow);
}

MainWindow::~MainWindow()
{
    delete ui;
}
