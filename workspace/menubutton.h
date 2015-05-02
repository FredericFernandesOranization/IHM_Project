#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QPushButton>
#include <QDebug>
#include "gallerieslayout.h"

class MenuButton : public QPushButton
{
    Q_OBJECT
public:
    MenuButton(QString label, QWidget* parent=0);
    ~MenuButton();
    QString getLabel();

public slots:
    void onClick();
signals:
    void setUnclicked(QString label);
private:
    QString label;

};

#endif // MENUBUTTON_H
