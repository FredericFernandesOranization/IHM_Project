#include "database.h"

Database *Database::instance = NULL;

Database::Database()
{
    this->pathDish = QString("../workspace/resources/plats.xml"); //on sauvegarde le path des plats
    this->pathAllergies = QString("../workspace/resources/allergies.xml");
    this->pathIngredients = QString("../workspace/resources/ingredients.xml");
    this->pathIMG = QString("../workspace/resources/imagesPlats/");

    this->loadDatabase(); //on charge le database du fichier XML
}



void Database::loadDatabase()
{
    loadDishs();
    loadAllergies();
    loadIngredients();
}
void Database::loadDishs()
{//utilise l'attribut databasePath de la classe Database
    qDebug() << "loading Dishs ...";

    QDomDocument *doc = openXmlFile(this->pathDish);
    QDomElement docElem = doc->documentElement();
    QDomNode n = docElem.firstChild();
    Plat::nbPlat=0;
    dishesMap.clear();
    // QDomNode n = openXmlFile(this->pathDish)
    int nbDishes = 0;

    while(!n.isNull())
    {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        if(!e.isNull())
        {
            nbDishes++;
            QString name = e.firstChildElement("name").text().simplified();
            QString type = e.firstChildElement("type").text().simplified();
            QString desc = e.firstChildElement("description").text().simplified();
            QString shortDesc = e.firstChildElement("shortDescription").text().simplified();
            QString imagePath = e.firstChildElement("imagePath").text().simplified();
            imagePath = filterImgPath(imagePath);
            float price = e.firstChildElement("price").text().toFloat();
            QStringList ingredientsList = getListsInXML(e.firstChildElement("ingredientsList"));
            QStringList possibleAllergiesList = getListsInXML(e.firstChildElement("possibleAllergiesList"));
            Plat *newPlat = new Plat(name,desc,imagePath,shortDesc,price,ingredientsList,possibleAllergiesList,type);
            dishesMap[type].append(newPlat);
        }
        n = n.nextSibling();
    }
    this->nbDishes = nbDishes;

    // just for verification
    //        foreach (QString type , dishesMap.keys()){
    //            qDebug() << "~~~~~~~~~~~~Liste des plats de type : "<< type <<"~~~~~~~~~~~~~~";
    //            QList<Plat*> listPlat = dishesMap[type];
    //            foreach (Plat* plat, listPlat){
    //                qDebug() << plat->toString() << endl;
    //            }
    //        }

    //        foreach (QList<Plat*> listPlat, dishesMap)
    //            foreach (Plat* plat, listPlat)
    //                qDebug() << plat->toString() << endl;
}

void Database::loadAllergies()
{
    qDebug() << "loading Allergies ...";
    QDomDocument *doc = openXmlFile(this->pathAllergies);
    QDomElement docElem = doc->documentElement();
    QDomNode n = docElem.firstChild();
    clientAllergiesList.clear();

    while(!n.isNull()) {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        QString name = e.text().simplified();
        clientAllergiesList<<name;
        n = n.nextSibling();
    }
}

void Database::loadIngredients()
{
    qDebug() << "loading Ingredients ...";
    QDomDocument *doc = openXmlFile(this->pathIngredients);
    QDomElement docElem = doc->documentElement();
    QDomNode n = docElem.firstChild();
    clientIngredientsList.clear();
    while(!n.isNull()) {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        QString name = e.text().simplified();
        clientIngredientsList<<name;
        n = n.nextSibling();
    }
}




void Database::writeXmlFile(QDomDocument doc,QString path )
{
    QFile fichier(path);
    if(!fichier.open(QIODevice::WriteOnly)){
        fichier.close();
        qDebug() << "error I can't open"<< path<<" ! ";
        Q_ASSERT(false); // crash now
    }
    QTextStream stream(&fichier);
    stream << doc.toString();
    fichier.close();
}

QString Database::filterImgPath(const QString path)
{
    QString newpath(path);
    if(!path.contains("/")){
         newpath = pathIMG+path;
    }
    return newpath;
}



QDomDocument* Database::openXmlFile(QString path)
{
    QDomDocument doc("doc");
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly))
    {
        qDebug() << "error I can't open"<< path<<" ! ";
        Q_ASSERT(false); // crash now
    }
    if (!doc.setContent(&file)) {
        file.close();
        qDebug() << "error your .xml file is incorrect !";
        Q_ASSERT(false); // crash now
    }
    file.close();
    // qDebug() << "File XML loaded ! ";

    return new QDomDocument(doc);
}
QString Database::getPathIMG() const
{
    return pathIMG;
}

QStringList Database::getClientIngredientsList() const
{
    return clientIngredientsList;
}

QStringList Database::getClientAllergiesList() const
{
    return clientAllergiesList;
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

QList<Plat *> Database::filterType(QString type)
{
    //renvoie seulement la liste des plats qui match le Type
    Q_ASSERT(dishesMap.contains(type)); // crash if dishesMap doesn't containstype
    return this->dishesMap[type];
    //qCritical() << "WARNING : dishesMap doesn't contains : "<< type << " !!";
}

QList<Plat *> Database::getDrinks()
{
    return filterType("Boissons");
}

QList<Plat *> Database::getStarters()
{
    return filterType("Entrees");
}

QList<Plat *> Database::getDishes()
{
    return filterType("Plats");
}

QList<Plat *> Database::getDesserts()
{
    return filterType("Desserts");
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


void Database::updateAllergies(QStringList listName)
{
    qDebug() << "update Allergy ...";
    QFile file(pathAllergies);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("lesAllergies");
    foreach (QString s , listName){
        xmlWriter.writeTextElement("name",s.simplified());
    }
    xmlWriter.writeEndElement();

    file.close();
}
void Database::updateIngredients(QStringList listName)
{
    qDebug() << "update Ingredients ...";
    QFile file(pathIngredients);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("lesIngredients");
    foreach (QString s , listName){
        xmlWriter.writeTextElement("name",s.simplified());
    }
    xmlWriter.writeEndElement();

    file.close();
}

void Database::updateDishes(QList<Plat> listPlats)
{
    qDebug() << "update Ingredients ...";
    QFile file(pathDish);
    file.open(QIODevice::WriteOnly);
    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();
    xmlWriter.writeStartElement("lesPlats");
    foreach (Plat p, listPlats)
    {
        xmlWriter.writeStartElement("plat");
        xmlWriter.writeTextElement("name",p.getName().simplified());
        xmlWriter.writeTextElement("type",p.getType());
        xmlWriter.writeTextElement("description",p.getDescription());
        xmlWriter.writeTextElement("shortDescription",p.getShortDescription());
        xmlWriter.writeTextElement("imagePath",p.getImagePath());
        xmlWriter.writeTextElement("price",QString::number(p.getPrice()));

        xmlWriter.writeStartElement("ingredientsList");
        foreach (QString ing, p.getIngredientsList()) {
            xmlWriter.writeTextElement("ingredient",ing);
        }
        xmlWriter.writeEndElement();

        xmlWriter.writeStartElement("possibleAllergiesList");
        foreach (QString all, p.getPossibleAllergiesList()) {
            xmlWriter.writeTextElement("possibleAllergie",all);
        }
        xmlWriter.writeEndElement();
        xmlWriter.writeEndElement();
    }
    xmlWriter.writeEndElement();

    file.close();
}

