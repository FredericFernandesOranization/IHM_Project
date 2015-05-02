#ifndef BACKBUTTON_H
#define BACKBUTTON_H

#include <QPushButton>
#include <QString>
#include <QWidget>
#include <qdebug.h>
#include <QObject>

class BackButton : public QPushButton
{
    Q_OBJECT
public:
    BackButton();
    BackButton(QString label);
    ~BackButton();
private:
    QString label;

};

#endif // BACKBUTTON_H
