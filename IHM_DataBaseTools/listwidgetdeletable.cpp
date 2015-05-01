#include "listwidgetdeletable.h"
#include <QApplication>
ListwidgetDeletable::ListwidgetDeletable(QWidget *parent) : QListWidget(parent)
{
    setSelectionMode(QAbstractItemView::SingleSelection);
    setDragEnabled(true);
    setAcceptDrops(true);
    setDropIndicatorShown(true);
    setDragDropMode(QAbstractItemView::DragDrop);
    itemSelected =0;
    connect(this,SIGNAL(itemPressed(QListWidgetItem*)),this,SLOT(MyitemPressed(QListWidgetItem*)));
}

void ListwidgetDeletable::dragEnterEvent(QDragEnterEvent *event){
    qDebug()<<"dragEnterEvent";
    if(event->source()==this){
        dragAddItem();
    }
    event->acceptProposedAction();

}

void ListwidgetDeletable::dragMoveEvent(QDragMoveEvent *event){
    //event->acceptProposedAction();
}

void ListwidgetDeletable::dragLeaveEvent(QDragLeaveEvent *event){
    qDebug()<<"dragLeaveEvent";
    QWidget * w = QApplication::focusWidget ();
    if( w== this){ // it's me"
        dragRemoveItem();
        this->clearSelection();

    }
    event->accept();



}

void ListwidgetDeletable::dropEvent(QDropEvent *event){
    qDebug()<<"dropEvent";
    if(event->source()==this){
        event->ignore();
    }else{
        if(event->mimeData()->hasFormat("text/plain")) {
            QListWidget *source = qobject_cast<QListWidget*>(event->source());
            int indexSource  = event->mimeData()->text().toInt();
            QListWidgetItem *newItem = source->item(indexSource)->clone();
            this->myAddIten(newItem);
        }
    }
}

QListWidgetItem *ListwidgetDeletable::getItemSelected() const
{
    return itemSelected;
}

void ListwidgetDeletable::setItemSelected(QListWidgetItem *value)
{
    itemSelected = value;
}





void ListwidgetDeletable::dragAddItem(){
    QList<QListWidgetItem*> items = this->findItems(itemSelected->text(),Qt::MatchFixedString);
    if(items.isEmpty()){ // for not added doublon
        this->addItem(itemSelected);
    }

}

void ListwidgetDeletable::dragRemoveItem(){
    //qDebug()<<"dragAddItem";
    QList<QListWidgetItem*> items = this->findItems(itemSelected->text(),Qt::MatchFixedString);
    foreach (QListWidgetItem* item , items) {
        takeItem(row(item));
    }
}
void ListwidgetDeletable::MyitemPressed(QListWidgetItem *item){
    itemSelected = item->clone();
}


void ListwidgetDeletable::myAddIten(QString txt){
    if((!txt.isEmpty()) && (!getStrings().contains(txt)) ){
        addItem(new QListWidgetItem(txt));
    }else
        QMessageBox::warning(this,"Erreur","Item déja existante ou le nom est vide !");
}

void ListwidgetDeletable::myAddIten(QListWidgetItem *item){
    QString txt = item->text();
    if((!txt.isEmpty()) && (!getStrings().contains(txt)) ){
        addItem(item);
    }else
        QMessageBox::warning(this,"Erreur","Item déja existante ou le nom est vide !");
}

QStringList ListwidgetDeletable::getStrings(){
    QStringList list;
    for (int i =0 ; i < count(); i++){
        list << item(i)->text();
    }
    return list;
}





