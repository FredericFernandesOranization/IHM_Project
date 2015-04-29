#ifndef EDITINGREDIENTWINDOW_H
#define EDITINGREDIENTWINDOW_H

#include <QDialog>

namespace Ui {
class EditIngredientWindow;
}

class EditIngredientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditIngredientWindow(QWidget *parent = 0);
    ~EditIngredientWindow();

private:
    Ui::EditIngredientWindow *ui;
};

#endif // EDITINGREDIENTWINDOW_H
