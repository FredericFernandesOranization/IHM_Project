#ifndef DATABASE_H
#define DATABASE_H

#include "plat.h"
#include <QHash>
#include <QStringList>
#include <QDomDocument>
#include <QDomAttr>
class Database
{
public:
    Database(QString databasePath);
    Plat getDish(int dishId)const ; //renvoie le plat
    void loadDatabase(); //analyse fichier XML, rempli le HashMap
    QList<Plat*> filter(QStringList clientAllergiesList);
    QList<Plat*> filterType(QString type); //filtre les plats par type, boissons plats etc ...

    QList<Plat*> getDrinks(); //renvoie la liste des boissons ...
    QList<Plat*> getStarters();
    QList<Plat*> getDishes();
    QList<Plat*> getDesserts();


private:
    QString databasePath;
    QHash<QString, QList<Plat*> > dishesMap; //dishesMap["boissons"] -> renvoie liste boissons (rempli par loadDatabase)
    QStringList clientAllergiesList; //on mémorise les allergies parametrées par le client
    QStringList getListsInXML(QDomElement elem);
};

#endif // BASEDONNEES_H
