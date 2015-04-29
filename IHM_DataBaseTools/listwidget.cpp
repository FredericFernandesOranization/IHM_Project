#include "listwidget.h"

ListWidget::ListWidget(QWidget *parent) : QListWidget(parent)
{
    setSelectionMode(QAbstractItemView::SingleSelection);
    setDragEnabled(true);
    setAcceptDrops(true);
    setDropIndicatorShown(true);
    setDragDropMode(QAbstractItemView::DragDrop);
    connect(this,SIGNAL(itemPressed(QListWidgetItem*)),this,SLOT(MyitemPressed(QListWidgetItem*)));
}

void ListWidget::dragEnterEvent(QDragEnterEvent *event){
    dragAddItem();
    event->acceptProposedAction();
}

void ListWidget::dragMoveEvent(QDragMoveEvent *event){
    event->acceptProposedAction();
}

void ListWidget::dragLeaveEvent(QDragLeaveEvent *event){
    dragRemoveItem();
    this->clearSelection();
    event->accept();

}

void ListWidget::dropEvent(QDropEvent *event){
    event->acceptProposedAction();
}
QListWidgetItem *ListWidget::getItemSelected() const{
    return itemSelected;
}


void ListWidget::dragAddItem(){
    QList<QListWidgetItem*> items = this->findItems(itemSelected->text(),Qt::MatchFixedString);
    if(items.isEmpty()){ // for not added doublon
        this->addItem(itemSelected);
    }

}

void ListWidget::dragRemoveItem(){
    qDebug()<<"dragAddItem";
    QList<QListWidgetItem*> items = this->findItems(itemSelected->text(),Qt::MatchFixedString);
    foreach (QListWidgetItem* item , items) {
        takeItem(row(item));
    }
}
void ListWidget::MyitemPressed(QListWidgetItem *item){
    itemSelected = item->clone();
}

void ListWidget::myAddIten(QString txt)
{
        if((!txt.isEmpty()) && (!getStrings().contains(txt)) ){
            addItem(new QListWidgetItem(txt));
        }else
            QMessageBox::warning(this,"Erreur","Allergie déja existante ou le nom est vide !");
}

QStringList ListWidget::getStrings(){
    QStringList list;
    for (int i =0 ; i < count(); i++){
        list << item(i)->text();
    }
    return list;
}





