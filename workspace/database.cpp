#include "database.h"
#include <QDomDocument>
#include <QFile>
#include <qdebug.h>
#include <QDomAttr>
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
    qDebug() << "loadDatabase ...";
    QDomDocument doc("plats");
    QFile file(this->databasePath);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "error ";
        return;
    }
    if (!doc.setContent(&file)) {
        file.close();
        qDebug() << "error ";
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
            qDebug() << e.tagName(); // the node really is an element.
            //qDebug() << e.text();
            QDomNode node =  e.firstChild();
            QDomElement elem = node.toElement();
            qDebug() <<"tagName :" <<elem.tagName();
            qDebug() << "texte :" <<elem.text();
        }
                        n = n.nextSibling();
        }

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

