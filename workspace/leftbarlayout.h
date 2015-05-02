#ifndef LEFTBARLAYOUT
#define LEFTBARLAYOUT

#include <QStackedLayout>

class LeftBarLayout : public QStackedLayout
{
public:
    ~LeftBarLayout();
    static LeftBarLayout* getInstance() {
        if(instance == NULL)
            instance = new LeftBarLayout();
        return instance;
    }
private:
    LeftBarLayout();
    static LeftBarLayout* instance;

};







#endif // LEFTBARLAYOUT

