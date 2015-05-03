#ifndef COMMANDE
#define COMMANDE
#include<QScrollArea>
#include<QVBoxLayout>
class Commande : public QScrollArea
{
    Q_OBJECT
public:
    Commande();
    QVBoxLayout *commandLayout;
    QWidget *commandWidget;
};
#endif // COMMANDE

