#ifndef GALLERY_H
#define GALLERY_H

#include <QWidget>
#include "flowlayout.h"
#include "database.h"
#include "item.h"
#include "gallerieslayout.h"

class Gallery : public QWidget
{
    Q_OBJECT
public:
    Gallery();
    Gallery(QString type);
    /*static Gallery* getInstance() {
        if(instance == NULL)
            instance = new Gallery();
        return instance;
    }*/

    void showItem(Plat p);
public slots:
    void showType(QString type);
    void onItemClick(Plat p);
    void onBackClick(QString type);

private:
    //Gallery instance; // for Singleton Pattern
    QString type;
    FlowLayout *layout;
    Database* database;
};

#endif // GALLERY_H
