#ifndef UPPERMENU_H
#define UPPERMENU_H

#include <QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QComboBox>
#include "dialoglang.h"

class UpperMenu : public QWidget
{
    Q_OBJECT
public:
    UpperMenu();
    ~UpperMenu();
private:
    QHBoxLayout *upperMenuHorizontalLayout;

private slots:
    void openLangWindow();
};

#endif // UPPERMENU_H
