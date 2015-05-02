#ifndef LEFTZONE_H
#define LEFTZONE_H

#include <QPushButton>
#include <QList>
#include <QString>
#include <QVBoxLayout>
#include <QWidget>
#include <QStackedLayout>
#include "gallery.h"
#include "menubutton.h"
#include "leftbarlayout.h"

class LeftZone : public QWidget
{
    Q_OBJECT
public:
    LeftZone();

private slots:
    void getUnclicked(QString label);

private:
    QList<MenuButton*> buttonLists;
    LeftBarLayout *leftZoneStackedLayout;
    MenuButton *switchButton;
};

#endif // LEFTZONE_H
