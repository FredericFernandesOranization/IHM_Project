#ifndef RIGHTZONE_H
#define RIGHTZONE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "gallery.h"
#include <gallerieslayout.h>
#include "detaileditem.h"

class RightZone : public QWidget
{
    Q_OBJECT
public:
    RightZone();
private:
    GalleriesLayout *galleriesLayout;

};

#endif // RIGHTZONE_H
