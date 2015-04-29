#ifndef DISHESDATABASEWINDOW_H
#define DISHESDATABASEWINDOW_H

#include <QDialog>

namespace Ui {
class DishesDataBaseWindow;
}

class DishesDataBaseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit DishesDataBaseWindow(QWidget *parent = 0);
    ~DishesDataBaseWindow();

private:
    Ui::DishesDataBaseWindow *ui;
};

#endif // DISHESDATABASEWINDOW_H
