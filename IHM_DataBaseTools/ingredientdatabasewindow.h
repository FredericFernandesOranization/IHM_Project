#ifndef INGREDIENTDATABASEWINDOW_H
#define INGREDIENTDATABASEWINDOW_H

#include <QDialog>
#include "database.h"
#include <QMessageBox>
namespace Ui {
class IngredientDataBaseWindow;
}

class IngredientDataBaseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit IngredientDataBaseWindow(QWidget *parent = 0);
    ~IngredientDataBaseWindow();

private slots:
    void on_btnAddIngred_clicked();

private:
    Ui::IngredientDataBaseWindow *ui;
    Database * dataBase;
    void updateUi();
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);
};

#endif // INGREDIENTDATABASEWINDOW_H
