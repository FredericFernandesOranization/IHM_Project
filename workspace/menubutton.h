#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QPushButton>
#include <QString>
#include <QWidget>
#include "gallerieslayout.h"
#include <qdebug.h>
#include <QObject>


class MenuButton : public QPushButton
{
    Q_OBJECT
public:
    MenuButton(QString label, QWidget* parent=0);
    ~MenuButton();

public slots:
    void onClick();
    void getUnclicked(QString label);
signals:
    void setUnclickedFred(QString label);
private:
    QString label;

};

#endif // MENUBUTTON_H
