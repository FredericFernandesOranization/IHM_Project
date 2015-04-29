#ifndef INGREDIENTDATABASEWINDOW_H
#define INGREDIENTDATABASEWINDOW_H

#include <QDialog>

namespace Ui {
class IngredientDataBaseWindow;
}

class IngredientDataBaseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit IngredientDataBaseWindow(QWidget *parent = 0);
    ~IngredientDataBaseWindow();

private:
    Ui::IngredientDataBaseWindow *ui;
};

#endif // INGREDIENTDATABASEWINDOW_H
