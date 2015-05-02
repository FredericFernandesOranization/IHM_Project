#ifndef BACKBUTTON_H
#define BACKBUTTON_H
#include <QPushButton>

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
