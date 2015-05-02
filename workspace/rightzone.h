#ifndef RIGHTZONE_H
#define RIGHTZONE_H
#include "gallerieslayout.h"
#include <QWidget>
#include <QPushButton>
#include "detaileditem.h"
#include "gallery.h"

class RightZone : public QWidget
{
    Q_OBJECT
public:
    RightZone();
private:
    GalleriesLayout *galleriesLayout;
};

#endif // RIGHTZONE_H
