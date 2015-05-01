#ifndef DISHESDATABASEWINDOW_H
#define DISHESDATABASEWINDOW_H

#include <QDialog>
#include "database.h"
#include <QListWidgetItem>
#include <plat.h>
#include <QIcon>
#include "editallergiewindow.h"
#include "editingredientwindow.h"
#include <QFileDialog>

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
    Database * dataBase;
    void updateUi();
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);
    bool blockChange;

private slots:
    void fillIfos(QListWidgetItem *item);
    void changedInfo();
    void clearAndBlockUi();
    void inBlockUi();
    void on_btnAllergies_clicked();
    void on_btnIngredients_clicked();
    void on_btnImg_clicked();
    void on_btnNewDish_clicked();
};

#endif // DISHESDATABASEWINDOW_H
