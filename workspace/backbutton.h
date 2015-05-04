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
    void setFromGallery(QString type);
private:
    QString label;
    QString fromGallery;
public slots :
    void backToGallery();
signals:
    void clicked(int index);

};

#endif // BACKBUTTON_H
