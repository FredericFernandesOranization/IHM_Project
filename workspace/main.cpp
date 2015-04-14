#include "mainwindow.h"
#include <QApplication>
#include "database.h"
#include <qdebug.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QString path = "../workspace/resources/plats.xml";
    Database *data = new Database(path);


    return a.exec();
}
