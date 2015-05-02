#ifndef LEFTZONE_H
#define LEFTZONE_H
#include "menubutton.h"
#include <QVBoxLayout>
#include <QDebug>



class LeftZone : public QWidget
{
    Q_OBJECT
public:
    LeftZone();

private slots:
    void getUnclicked(QString label);
private:
    QList<MenuButton*> buttonLists;

};

#endif // LEFTZONE_H
