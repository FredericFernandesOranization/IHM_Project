#ifndef MENUBUTTON_H
#define MENUBUTTON_H

#include <QPushButton>
#include <QString>

class MenuButton : QPushButton
{
    Q_OBJECT
public:
    MenuButton(QString label);
    ~MenuButton();

public slots:
    void onClick();
private:
    QString label;

};

#endif // MENUBUTTON_H
