#ifndef GALLERY_H
#define GALLERY_H

#include <QWidget>
#include <QVBoxLayout>
#include <QPushButton>
#include <QString>
#include "Headers/database.h"
#include "Headers/item.h"
#include "Headers/flowlayout.h"

class Gallery : public QWidget
{
public:
    Gallery();
    static Gallery* getInstance() {
        if(instance == NULL)
            instance = new Gallery();
        return instance;
    }
public slots:
        void showType(QString type);

private:
    static Gallery* instance; // for Singleton Pattern
    FlowLayout *layout;
    Database* database;
};

#endif // GALLERY_H
