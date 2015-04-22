#include "database.h"

#include <QFile>
#include <qdebug.h>
#include <QStringList>
Database::Database(QString databasePath, QString pathIMG)
{
    this->databasePath = databasePath; //on sauvegarde le path du database
    this->pathIMG = pathIMG;
    this->loadDatabase(); //on charge le database du fichier XML
}

Plat Database::getDish(int dishId) const
{
    foreach (QList<Plat*> listPlat, dishesMap)
        foreach (Plat* plat, listPlat)
            if (plat->getId()== dishId)
                return *plat;
    qCritical() << "WARNING : your dishId doesn't exist !!";
    Q_ASSERT(false); // crash now
    //return Plat();
}

void Database::loadDatabase()
{//utilise l'attribut databasePath de la classe Database
    qDebug() << "loadDatabase ...";
    QDomDocument doc("plats");
    QFile file(this->databasePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "error I can't open .xml file ! ";
        return;
    }
    if (!doc.setContent(&file)) {
        file.close();
        qDebug() << "error your .xml file is incorrect !";
        return;
    }
    file.close();
    qDebug() << "File XML loaded ! ";

    // print out the element names of all elements that are direct children
    // of the outermost element.
    QDomElement docElem = doc.documentElement();

    QDomNode n = docElem.firstChild();
    while(!n.isNull()) {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        if(!e.isNull()) {
            QString name = e.firstChildElement("name").text().simplified();
            QString type = e.firstChildElement("type").text().simplified();
            QString desc = e.firstChildElement("description").text().simplified();
            QString shortDesc = e.firstChildElement("shortDescription").text().simplified();
            QString imagePath = e.firstChildElement("imagePath").text().simplified();
            imagePath = pathIMG+imagePath;
            float price = e.firstChildElement("price").text().toFloat();
            QStringList ingredientsList = getListsInXML(e.firstChildElement("ingredientsList"));
            QStringList possibleAllergiesList = getListsInXML(e.firstChildElement("possibleAllergiesList"));
            Plat *newPlat = new Plat(name,desc,imagePath,shortDesc,price,ingredientsList,possibleAllergiesList,type);
            dishesMap[type].append(newPlat);
        }
        n = n.nextSibling();

    }
    // just for verification
    //    foreach (QString type , dishesMap.keys()){
    //        qDebug() << "~~~~~~~~~~~~Liste des plats de type : "<< type <<"~~~~~~~~~~~~~~";
    //        QList<Plat*> listPlat = dishesMap[type];
    //        foreach (Plat* plat, listPlat){
    //            qDebug() << plat->toString() << endl;
    //        }
    //    }

    //    foreach (QList<Plat*> listPlat, dishesMap)
    //        foreach (Plat* plat, listPlat)
    //            qDebug() << plat->toString() << endl;
}

QList<Plat *> Database::filterType(QString type)
{
    //renvoie seulement la liste des plats qui match le Type
    Q_ASSERT(dishesMap.contains(type)); // crash if dishesMap doesn't containstype
    return this->dishesMap[type];
    //qCritical() << "WARNING : dishesMap doesn't contains : "<< type << " !!";

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

QStringList Database::getListsInXML(QDomElement elem)
{
    QStringList list;
    QDomNode node = elem.firstChild(); // recup first Ingredients
    while(!node.isNull()) {// for each Ingrédients
        list <<  node.toElement().text().simplified();
        node = node.nextSibling();
    }
    return list;
}

