#ifndef DIALOGLANG_H
#define DIALOGLANG_H

#include <QDialog>
#include <QDesktopWidget>
namespace Ui {
class DialogLang;
}

class DialogLang : public QDialog
{
    Q_OBJECT

public:
    explicit DialogLang(QWidget *parent = 0);
    ~DialogLang();

private slots:
    void on_btnItalie_clicked();

    void on_btnAnglais_clicked();

    void on_btnFrancais_clicked();

    void on_btnArabe_clicked();

    void on_btnEspagne_clicked();

    void on_btnChinois_clicked();

private:
    Ui::DialogLang *ui;
};

#endif // DIALOGLANG_H
