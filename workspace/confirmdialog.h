#ifndef CONFIRMDIALOG_H
#define CONFIRMDIALOG_H

#include <QDialog>
#include <QDebug>
#include <QDesktopWidget>

namespace Ui {
class ConfirmDialog;
}

class ConfirmDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ConfirmDialog(QWidget *parent = 0);
    ~ConfirmDialog();

private slots:
    void on_btnValid_clicked();

    void on_btnAnnuler_clicked();

private:
    Ui::ConfirmDialog *ui;
};

#endif // CONFIRMDIALOG_H
