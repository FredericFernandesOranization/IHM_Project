#ifndef EDITINGREDIENTWINDOW_H
#define EDITINGREDIENTWINDOW_H

#include <QDialog>
#include "database.h"
#include <QListWidgetItem>
#include "plat.h"

namespace Ui {
class EditIngredientWindow;
}

class EditIngredientWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditIngredientWindow(QListWidgetItem *item,QWidget *parent = 0);
    ~EditIngredientWindow();

private:
    Ui::EditIngredientWindow *ui;
    Database * dataBase;
    Plat plat;
    QListWidgetItem *item;
    void updateUi();
    void closeEvent(QCloseEvent *event);
};

#endif // EDITINGREDIENTWINDOW_H
