#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "allergiedatabasewindow.h"
#include "ingredientdatabasewindow.h"
#include "dishesdatabasewindow.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_btnLesPlats_clicked();

    void on_btnIngr_clicked();

    void on_btnAlle_clicked();

private:
    Ui::MainWindow *ui;
    AllergieDataBaseWindow *allergieWindows;
    IngredientDataBaseWindow *ingrWindows;
    DishesDataBaseWindow * dishesWindows;
};

#endif // MAINWINDOW_H
