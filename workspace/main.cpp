#include "mainwindow.h"
#include <QApplication>
#include "database.h"
#include <qdebug.h>
#include <item.h>
#include <QGraphicsView>
#include <QListWidget>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QString pathBase = "../workspace/resources/plats.xml";
    QString pathIMG= "../workspace/resources/imagesPlats/";
    Database *data = new Database(pathBase,pathIMG);

    Item *item1 = new Item(data->getDish(0));
    //item1->show();
    Item *item2 = new Item(data->getDish(1));
    //item2->show();

    QListWidget *m_listeWidget = new QListWidget();
    m_listeWidget->addItem(item1);
    m_listeWidget->addItem(item2);

    m_listeWidget->setViewMode(QListWidget::IconMode);

    m_listeWidget->setIconSize(QSize(200,200));

    m_listeWidget->setResizeMode(QListWidget::Adjust);

    m_listeWidget->addItem(new QListWidgetItem(QIcon("../workspace/resources/imagesPlats/plat1.jpg"),"plat1"));
    m_listeWidget->addItem(new QListWidgetItem(QIcon("../workspace/resources/imagesPlats/plat2.jpg"),"plat2"));
    m_listeWidget->addItem(new QListWidgetItem(QIcon("../workspace/resources/imagesPlats/plat1.jpg"),"plat3"));
    w.setCentralWidget(m_listeWidget);


     w.show();









    return a.exec();
}
