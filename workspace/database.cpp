#include "database.h"

Database::Database(QString databasePath)
{
    this->databasePath = databasePath; //on sauvegarde le path du database
    this->loadDatabase(); //on charge le database du fichier XML
}

Plat Database::getDish(int dishId)
{
    Plat result;
    //parcour les liste des plats et renvoie le bon plat grace à l'id
    return result;
}

void Database::loadDatabase()
{//utilise l'attribut databasePath de la classe Database
}

QList<Plat *> Database::filterType(QString type)
{
    //renvoie seulement la liste des plats qui match le Type
    return this->dishesMap[type];
}

QList<Plat *> Database::getDrinks()
{
    return filterType("boisson");
}

QList<Plat *> Database::getStarters()
{
    return filterType("entree");
}

QList<Plat *> Database::getDishes()
{
    return filterType("plat");
}

QList<Plat *> Database::getDesserts()
{
    return filterType("dessert");
}

