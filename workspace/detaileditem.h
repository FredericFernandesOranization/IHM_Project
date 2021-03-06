#ifndef DETAILEDITEM_H
#define DETAILEDITEM_H


#include "plat.h"
#include "imagelabel.h"
#include <QLabel>
#include <QImage>
#include <QDebug>
#include <QPixmap>
#include <QPen>
#include <QPainter>
#include <QPushButton>
#include <QHBoxLayout>
#include "backbutton.h"
#include "flowlayout.h"
#include "commanderbutton.h"
#include "database.h"

class DetailedItem :public QWidget
{
    Q_OBJECT
public:
    DetailedItem(Plat plat, int imgSizeW=450 ,int imgSizeH=300, QColor background=QColor(70,130,180), QWidget *parent = 0);
    CommanderButton* getAjouterButton();
    BackButton* getBackButton();
    CommanderButton* getCommanderButton();
    static DetailedItem* getInstance() {
        if(instance == NULL){
            Plat p = Database::getInstance()->getDish(0);
            instance = new DetailedItem(p);
        }
        return instance;
    }

    void setPlat(Plat p);
    Plat getPlat();
    void setInstance(DetailedItem* d);
    void update();
private:
    FlowLayout *leftPartLayout;
    //void updateItem();
    QLabel *descriptionLabel;
    QLabel *nameLabel;
    QColor background;
    CommanderButton* commander;
    QHBoxLayout *itemLayout;
    static DetailedItem* instance;
    BackButton* backButton;
    Plat plat;
    ImageLabel* image;
    QImage *img;
    int imgSizeW;
    int imgSizeH;
signals:
    void clicked(QString);

};

#endif // DETAILEDITEM_H
