#include "mainwindow.h"
#include <QApplication>
#include "database.h"
#include <qdebug.h>
#include <item.h>
#include <QGraphicsView>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
     w.show();
    QString pathBase = "../workspace/resources/plats.xml";
    QString pathIMG= "../workspace/resources/imagesPlats/";
    Database *data = new Database(pathBase,pathIMG);


    Item *item1 = new Item(data->getDish(0));
    item1->show();
    Item *item2 = new Item(data->getDish(1));
    item2->show();


    return a.exec();
}
