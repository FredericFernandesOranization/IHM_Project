#include "commanderbutton.h"

CommanderButton::CommanderButton(QString label) : QPushButton(label)
{

}

CommanderButton::~CommanderButton()
{

}

void CommanderButton::setPlat(Plat p)
{
    this->plat = p;
}

void CommanderButton::sendToCommandZone()
{
    emit onClick(this->plat);
}

