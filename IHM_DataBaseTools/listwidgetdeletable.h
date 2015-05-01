#ifndef LISTWIDGETDELETABLE_H
#define LISTWIDGETDELETABLE_H

#include <QtGui>
#include <QtCore>
#include <QMessageBox>
#include <QListWidget>
#include <QListWidgetItem>
#include "listwidgetdrag.h"
class ListwidgetDeletable  :public QListWidget
{
    Q_OBJECT
public:
    ListwidgetDeletable(QWidget *parent = 0);

    void myAddIten(QString name);
    void myAddIten(QListWidgetItem *item);
    QStringList getStrings();


    QListWidgetItem *getItemSelected() const;
    void setItemSelected(QListWidgetItem *value);


protected:
    void dragEnterEvent(QDragEnterEvent *event);
    void dragMoveEvent(QDragMoveEvent *event);
    void dragLeaveEvent(QDragLeaveEvent *event);
    void dropEvent(QDropEvent *event);
    QListWidgetItem *itemSelected;
    void dragAddItem();
    void dragRemoveItem();

private slots:

    void MyitemPressed(QListWidgetItem *item);
};

#endif // LISTWIDGET_H
