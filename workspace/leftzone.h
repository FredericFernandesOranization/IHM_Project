#ifndef LEFTZONE_H
#define LEFTZONE_H

#include <QPushButton>
#include <QList>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>
#include "gallery.h"
#include "menubutton.h"


class LeftZone : public QWidget
{
    Q_OBJECT
public:
    LeftZone();

private slots:
    void getUnclicked(QString label);
<<<<<<< HEAD
private:
    QList<MenuButton*> buttonLists;
=======
    void test();
>>>>>>> 3e7768cfc11cda64c20e2f1083b52d5fc27da223
};

#endif // LEFTZONE_H
