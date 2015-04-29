#ifndef EDITALLERGIEWINDOW_H
#define EDITALLERGIEWINDOW_H

#include <QDialog>
#include "database.h"

namespace Ui {
class EditAllergieWindow;
}

class EditAllergieWindow : public QDialog
{
    Q_OBJECT

public:
    explicit EditAllergieWindow(QWidget *parent = 0);
    ~EditAllergieWindow();

private:
    Ui::EditAllergieWindow *ui;
    Database * dataBase;
    void updateUi();
    //void closeEvent(QCloseEvent *event);
    //void showEvent(QShowEvent *event);
};

#endif // EDITALLERGIEWINDOW_H
