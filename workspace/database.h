#ifndef DATABASE_H
#define DATABASE_H

#include "plat.h"
#include <QHash>
#include <QDomDocument>
#include <QDomAttr>
#include <QFile>
#include <qdebug.h>
#include <QStringList>
#include <QXmlStreamWriter>

class Database
{
public:
    Database();
    Plat getDish(int dishId)const ; //renvoie le plat

    QList<Plat*> filter(QStringList clientAllergiesList);
    QList<Plat*> filterType(QString type); //filtre les plats par type, boissons plats etc ...

    QList<Plat*> getDrinks(); //renvoie la liste des boissons ...
    QList<Plat*> getStarters();
    QList<Plat*> getDishes();
    QList<Plat*> getDesserts();
    int getNbDishes(){return nbDishes;}
    static Database* getInstance() {
        if(instance == NULL)
            instance = new Database();

        return instance;
    }

    QStringList getClientAllergiesList() const;
    QStringList getClientIngredientsList() const;
    void loadDishs(); //analyse fichier XML, rempli le HashMap
    void loadAllergies(); //analyse fichier XML, rempli clientAllergiesList
    void loadIngredients(); //analyse fichier XML, rempli clientIngredientsList

    void updateAllergies(QStringList listName);
    void updateIngredients(QStringList listName);
    void updateDishes(QList<Plat> listPlats);

    QString getPathIMG() const;

private:
    void loadDatabase();
    void writeXmlFile(QDomDocument doc,QString path); // for Update Xml file
    QString filterImgPath(const QString path);


    QDomDocument* openXmlFile(QString path);
    static Database * instance; // for Singleton Pattern
    QString pathDish;
    QString pathAllergies;
    QString pathIngredients;
    QString pathIMG;
    QHash<QString, QList<Plat*> > dishesMap; //dishesMap["boissons"] -> renvoie liste boissons (rempli par loadDatabase)
    QStringList clientAllergiesList; //on mémorise les allergies parametrées par le client
    QStringList clientIngredientsList; //on mémorise les Ingredients parametrées par le client
    QStringList getListsInXML(QDomElement elem);
    //QString filterType(QString string);
    int nbDishes;
};

#endif // BASEDONNEES_H
