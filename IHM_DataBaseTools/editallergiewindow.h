#ifndef EDITALLERGIEWINDOW_H
#define EDITALLERGIEWINDOW_H

#include <QDialog>

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
};

#endif // EDITALLERGIEWINDOW_H
