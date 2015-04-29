#ifndef GALLERIESLAYOUT_H
#define GALLERIESLAYOUT_H

#include <QStackedLayout>

class GalleriesLayout : public QStackedLayout
{
public:
    ~GalleriesLayout();
    static GalleriesLayout* getInstance() {
        if(instance == NULL)
            instance = new GalleriesLayout();
        return instance;
    }
private:
    GalleriesLayout();
    static GalleriesLayout* instance;

};

#endif // GALLERIESLAYOUT_H
