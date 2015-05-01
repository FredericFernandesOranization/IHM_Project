#ifndef EDITALLERGIEWINDOW_H
#define EDITALLERGIEWINDOW_H

#include <QDialog>
#include "database.h"
#include <QListWidgetItem>
#include "plat.h"

namespace Ui {
class EditAllergieWindow;
}

class EditAllergieWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditAllergieWindow(QListWidgetItem *item, QWidget *parent = 0);
    ~EditAllergieWindow();

private:
    Ui::EditAllergieWindow *ui;
    Database * dataBase;
    void updateUi();
    Plat plat;
    QListWidgetItem *item;
    void closeEvent(QCloseEvent *event);
    //void closeEvent(QCloseEvent *event);
    //void showEvent(QShowEvent *event);

};

#endif // EDITALLERGIEWINDOW_H
