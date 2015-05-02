#include "backbutton.h"

BackButton::BackButton() : QPushButton()
{

}

BackButton::BackButton(QString label) : QPushButton(label)
{
    this->label = label;
}


BackButton::~BackButton()
{

}



