#ifndef ALLERGIEDATABASEWINDOW_H
#define ALLERGIEDATABASEWINDOW_H

#include <QDialog>
#include "database.h"
#include "listwidget.h"
namespace Ui {
class AllergieDataBaseWindow;
}

class AllergieDataBaseWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AllergieDataBaseWindow(QWidget *parent = 0);
    ~AllergieDataBaseWindow();

private slots:
    void on_btnAddAllergie_clicked();

private:
    Ui::AllergieDataBaseWindow *ui;
    Database * dataBase;
    void updateUi();
    void closeEvent(QCloseEvent *event);
    void showEvent(QShowEvent *event);
};

#endif // ALLERGIEDATABASEWINDOW_H
