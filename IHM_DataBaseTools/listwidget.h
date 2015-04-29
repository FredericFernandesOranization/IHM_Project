#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QtGui>
#include <QtCore>
#include <QMessageBox>
#include <QListWidget>
#include <QListWidgetItem>
class ListWidget  :public QListWidget
{
    Q_OBJECT
public:
    ListWidget(QWidget *parent = 0);

    QListWidgetItem *getItemSelected() const;
    void myAddIten(QString name);
    QStringList getStrings();


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
