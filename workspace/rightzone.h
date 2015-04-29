#ifndef RIGHTZONE_H
#define RIGHTZONE_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QPushButton>
#include "gallery.h"
#include <gallerieslayout.h>

class RightZone : public QWidget
{
public:
    RightZone();
private:
    GalleriesLayout *galleriesLayout;
};

#endif // RIGHTZONE_H
