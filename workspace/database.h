#ifndef BASEDONNEES_H
#define BASEDONNEES_H

#include "plat.h"

class Database
{
public:
    Database(QString databasePath);
    Plat getDish(int dishId); //renvoie le plat
    QList<Plat*> loadDatabase(); //analyse fichier XML, renvoie la liste des objets Plats
    QList<Plat*> filter(QListString possibleAllergiesList);
private:
    QString databasePath;
    QList<Plat*> dishesList;

};

#endif // BASEDONNEES_H
