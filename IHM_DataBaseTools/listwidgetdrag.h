#ifndef LISTWIDGETDRAG_H
#define LISTWIDGETDRAG_H

#include <QtGui>
#include <QtCore>
#include <QMessageBox>
#include <QListWidget>
#include <QListWidgetItem>
#include <QPoint>
#include <QApplication>

class listWidgetDrag : public QListWidget
{
    Q_OBJECT
public:
    listWidgetDrag(QWidget *parent=0);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
private:
    QPoint dragStartPosition;
    void drag();




};

#endif // LISTWIDGETDRAG_H
