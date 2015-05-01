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
    void test();
};

#endif // LEFTZONE_H
