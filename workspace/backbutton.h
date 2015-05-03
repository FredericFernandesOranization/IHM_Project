#ifndef BACKBUTTON_H
#define BACKBUTTON_H

#include <QPushButton>
#include <QString>
#include <QWidget>
#include <qdebug.h>
#include <QObject>
#include "gallerieslayout.h"


class BackButton : public QPushButton
{
    Q_OBJECT
public:
    BackButton();
    BackButton(QString label);
    ~BackButton();
private:
    QString label;

public slots :
    void backToGallery(){
        qDebug() << " in back to gallery button";
        GalleriesLayout::getInstance()->setCurrentIndex(0);

    }

};

#endif // BACKBUTTON_H
