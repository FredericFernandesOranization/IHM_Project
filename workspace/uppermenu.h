#ifndef UPPERMENU_H
#define UPPERMENU_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>

class UpperMenu : public QWidget
{
public:
    UpperMenu();
    ~UpperMenu();
private:
    QHBoxLayout *upperMenuHorizontalLayout;
};

#endif // UPPERMENU_H
