#include "listwidgetdrag.h"

listWidgetDrag::listWidgetDrag(QWidget *parent): QListWidget(parent)
{
    setSelectionMode(QAbstractItemView::SingleSelection);
    setDragEnabled(true);
    setDragDropMode(QAbstractItemView::DragOnly);
    setDropIndicatorShown(true);
    setAcceptDrops(false);
}

void listWidgetDrag::mousePressEvent(QMouseEvent *event){
    if (event->button() == Qt::LeftButton)
        dragStartPosition = event->pos();

    QListWidget::mousePressEvent(event);
}
void listWidgetDrag::mouseMoveEvent(QMouseEvent *event){
    if (event->buttons() & Qt::LeftButton) {
        int distance = (event->pos() - dragStartPosition).manhattanLength();
        if (distance >= QApplication::startDragDistance())
            drag();
    }
    //QListWidget::mouseMoveEvent(event);

}
void listWidgetDrag::drag()
{
    QListWidgetItem *item = currentItem();
    if (item) {
        QMimeData *mimeData = new QMimeData;
        mimeData->setText(QString::number(this->row(this->currentItem())));
        QDrag *drag = new QDrag(this);
        drag->setMimeData(mimeData);
        drag->exec(Qt::MoveAction);


    }
}
