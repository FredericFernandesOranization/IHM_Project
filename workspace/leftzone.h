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
public:
    LeftZone();

private slots:
    void getUnclicked(QString label);
<<<<<<< HEAD
<<<<<<< HEAD
private:
    QList<MenuButton*> buttonLists;
=======
    void test();
>>>>>>> 3e7768cfc11cda64c20e2f1083b52d5fc27da223
||||||| merged common ancestors
    void test();
=======

>>>>>>> 8757284eaeac6c2bdd6be628d8b85bb7a1dbc2e2
};

#endif // LEFTZONE_H
