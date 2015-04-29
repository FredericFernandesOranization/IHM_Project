#ifndef ALLERGIEDATABASEWINDOW_H
#define ALLERGIEDATABASEWINDOW_H

#include <QDialog>

namespace Ui {
class AllergieDataBaseWindow;
}

class AllergieDataBaseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AllergieDataBaseWindow(QWidget *parent = 0);
    ~AllergieDataBaseWindow();

private:
    Ui::AllergieDataBaseWindow *ui;
};

#endif // ALLERGIEDATABASEWINDOW_H
