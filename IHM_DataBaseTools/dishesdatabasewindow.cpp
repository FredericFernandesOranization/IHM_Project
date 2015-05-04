#include "dishesdatabasewindow.h"
#include "ui_dishesdatabasewindow.h"


DishesDataBaseWindow::DishesDataBaseWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DishesDataBaseWindow){
    ui->setupUi(this);
    this->dataBase = Database::getInstance();
    ui->listDishDataBase->setIconSize(QSize(150, 150));
    this->setAutoFillBackground(true);
    this->setPalette(QPalette(QColor(80,142,150)));


    connect(ui->listDishDataBase,SIGNAL(itemClicked(QListWidgetItem*)),this,SLOT(fillIfos(QListWidgetItem*)));

    connect(ui->lineEditNom,SIGNAL(textEdited(QString)),this,SLOT(changedInfo()));
    connect(ui->comboBoxType,SIGNAL(currentIndexChanged(int)),this,SLOT(changedInfo()));
    connect(ui->textEditDescr,SIGNAL(textChanged()),this,SLOT(changedInfo()));
    connect(ui->doubleSpinBox,SIGNAL(valueChanged(double)),SLOT(changedInfo()));

    connect(ui->listDishDataBase,SIGNAL(itemPressed(QListWidgetItem*)),this,SLOT(inBlockUi()));

    // updateUi();
    blockChange=false;

}

DishesDataBaseWindow::~DishesDataBaseWindow(){
    delete ui;
}

void DishesDataBaseWindow::updateUi(){

    blockChange = true;
    clearAndBlockUi();

    for(int i = 0;i <dataBase->getNbDishes(); i ++){
        Plat p = dataBase->getDish(i);
        QVariant qv;
        qv.setValue(p);
        QListWidgetItem *item = new QListWidgetItem(QIcon(p.getImagePath()),p.getName());
        item->setData(Qt::UserRole,qv);
        ui->listDishDataBase->addItem(item);
    }

    blockChange = false;
}

void DishesDataBaseWindow::closeEvent(QCloseEvent *)
{
    int nbItems = ui->listDishDataBase->count();
    QList<Plat> listDishes;
    for (int i =0 ; i < nbItems ; i ++)
    {
        QVariant qv = ui->listDishDataBase->item(i)->data(Qt::UserRole);
        Plat p = qv.value<Plat>();
        listDishes<<p;
    }
    dataBase->updateDishes(listDishes);
}

void DishesDataBaseWindow::showEvent(QShowEvent *){
    dataBase->loadDishs();
    updateUi();
}

void DishesDataBaseWindow::fillIfos(QListWidgetItem *item)
{
    QVariant qv = item->data(Qt::UserRole);
    Plat p = qv.value<Plat>();

    ui->doubleSpinBox->setValue(static_cast<double>(p.getPrice()));
    ui->lineEditNom->setText(p.getName());
    ui->textEditDescr->setText(p.getDescription());

    QPixmap pix(p.getImagePath());
    pix = pix.scaled(ui->labelImg->rect().size());
    ui->labelImg->setPixmap(pix);

    //int index = ui->comboBoxType->findText(p.getType());
    ui->comboBoxType->setCurrentText(p.getType());
}

void DishesDataBaseWindow::changedInfo()
{
    if((!blockChange) && (ui->listDishDataBase->getItemSelected()!=0)) {
        QVariant qv = ui->listDishDataBase->currentItem()->data(Qt::UserRole);
        Plat p = qv.value<Plat>();
        p.setName(ui->lineEditNom->text().simplified());
        p.setType(ui->comboBoxType->currentText());

        p.setDescription(ui->textEditDescr->toPlainText());
        p.setPrice(ui->doubleSpinBox->value());

        qv.setValue(p);
        ui->listDishDataBase->currentItem()->setData(Qt::UserRole,qv);
        ui->listDishDataBase->currentItem()->setText(p.getName());
    }
}
void DishesDataBaseWindow::clearAndBlockUi()
{
    ui->listDishDataBase->clearSelection();
    ui->listDishDataBase->setItemSelected(0);
    ui->listDishDataBase->clear();
    ui->lineEditNom->clear();
    ui->comboBoxType->setCurrentIndex(0);
    ui->textEditDescr->setText("");
    ui->doubleSpinBox->setValue(0.0);
    ui->labelImg->clear();

    ui->lineEditNom->setDisabled(true);
    ui->comboBoxType->setDisabled(true);
    ui->textEditDescr->setDisabled(true);
    ui->doubleSpinBox->setDisabled(true);
    ui->labelImg->setDisabled(true);
    ui->btnAllergies->setDisabled(true);
    ui->btnIngredients->setDisabled(true);
    ui->btnImg->setDisabled(true);
}

void DishesDataBaseWindow::inBlockUi()
{
    ui->lineEditNom->setDisabled(false);
    ui->comboBoxType->setDisabled(false);
    ui->textEditDescr->setDisabled(false);
    ui->doubleSpinBox->setDisabled(false);
    ui->labelImg->setDisabled(false);
    ui->btnAllergies->setDisabled(false);
    ui->btnIngredients->setDisabled(false);
    ui->btnImg->setDisabled(false);
}

void DishesDataBaseWindow::on_btnAllergies_clicked()
{
    EditAllergieWindow *win = new EditAllergieWindow(ui->listDishDataBase->currentItem());
    //this->setModal(false);
    win->setModal(true);
    win->show();
}

void DishesDataBaseWindow::on_btnIngredients_clicked()
{
    EditIngredientWindow *win = new EditIngredientWindow(ui->listDishDataBase->currentItem());
    //this->setModal(false);
    win->setModal(true);
    win->show();
}

void DishesDataBaseWindow::on_btnImg_clicked()
{
    QString imagePath = QFileDialog::getOpenFileName(
                this, "Ouvrir une image", dataBase->getPathIMG(), "Images (*.png *.gif *.jpg *.jpeg)");

    QDir pwd(QCoreApplication::applicationDirPath());
    QString pathRelatif = pwd.relativeFilePath(imagePath);
    QVariant qv = ui->listDishDataBase->currentItem()->data(Qt::UserRole);
    Plat p = qv.value<Plat>();
    p.setImagePath(pathRelatif);
    qv.setValue(p);

    QPixmap pix(p.getImagePath());
    pix = pix.scaled(ui->labelImg->rect().size());
    ui->labelImg->setPixmap(pix);

    ui->listDishDataBase->currentItem()->setData(Qt::UserRole,qv);
    ui->listDishDataBase->currentItem()->setIcon( QIcon(p.getImagePath()));

}

void DishesDataBaseWindow::on_btnNewDish_clicked()
{
    Plat newPlat("Nouveau plat "+QString::number(Plat::nbPlat),"Mettez votre desciption ici","","",
                 0.0,QStringList(),QStringList(),ui->comboBoxType->itemText(0));
    QVariant qv;
    qv.setValue(newPlat);
    QListWidgetItem *item = new QListWidgetItem(QIcon(newPlat.getImagePath()),newPlat.getName());
    item->setData(Qt::UserRole,qv);
    ui->listDishDataBase->addItem(item);
}
