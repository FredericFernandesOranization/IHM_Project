#ifndef COMMANDERBUTTON_H
#define COMMANDERBUTTON_H

#include "plat.h"
#include <QPushButton>
//#include "detaileditem.h"

class CommanderButton : public QPushButton
{
    Q_OBJECT
public:
    CommanderButton(QString label);
    ~CommanderButton();
    void setPlat(Plat p);
private:
    Plat plat;
public slots:
    void sendToCommandZone();
signals:
    void onClick(Plat p);
};

#endif // COMMANDERBUTTON_H
