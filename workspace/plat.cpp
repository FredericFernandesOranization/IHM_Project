#include "plat.h"
#include <QDebug>
int Plat::nbPlat = 0;

Plat::Plat()
{
}

Plat::Plat(QString name, QString description, QString imagePath, QString shortDescription,
           float price, QStringList ingredientsList, QStringList possibleAllergiesList, QString type)
{

    this->id = this->nbPlat; //id unique incrementé à chaque création d'un plat
    this->nbPlat++;
    //qDebug() << this->id;
    this->name = name;
    this->type = type;
    this->description = description;
    this->imagePath = imagePath;
    this->shortDescription = shortDescription;
    this->price = price;
    this->ingredientsList = ingredientsList;
    this->possibleAllergiesList = possibleAllergiesList;
}

//getters and setters
QString Plat::getName() const
{
    return name;
}

void Plat::setName(const QString &value)
{
    name = value;
}
QString Plat::getDescription() const
{
    return description;
}

void Plat::setDescription(const QString &value)
{
    description = value;
}

QString Plat::getImagePath() const
{
    return imagePath;
}

void Plat::setImagePath(const QString &value)
{
    imagePath = value;
}
QString Plat::getShortDescription() const
{
    return shortDescription;
}

void Plat::setShortDescription(const QString &value)
{
    shortDescription = value;
}
int Plat::getId() const
{
    return id;
}

void Plat::setId(int value)
{
    id = value;
}
float Plat::getPrice() const
{
    return price;
}

void Plat::setPrice(float value)
{
    price = value;
}
QStringList Plat::getIngredientsList() const
{
    return ingredientsList;
}

void Plat::setIngredientsList(const QStringList &value)
{
    ingredientsList = value;
}
QStringList Plat::getPossibleAllergiesList() const
{
    return possibleAllergiesList;
}

void Plat::setPossibleAllergiesList(const QStringList &value)
{
    possibleAllergiesList = value;
}
QString Plat::getType() const
{
    return type;
}

void Plat::setType(const QString &value)
{
    type = value;
}

QString Plat::toString()
{
    QString  buffer;
    buffer.append("id :" + QString::number(this->id)) ;
    buffer.append("\n");
    buffer.append( "name : " + this->name);
    buffer.append("\n");
    buffer.append( "type : " + this->type);
    buffer.append("\n");
    buffer.append( "description : " + this->description);
    buffer.append("\n");
    buffer.append( "idimagePath : "+ this->imagePath);
    buffer.append("\n");
    buffer.append( "shortDescription : " + this->shortDescription);
    buffer.append("\n");
    buffer.append("price : " + QString::number(this->price));
    buffer.append("\n");
    buffer.append( "ingredientsList");
    buffer.append("\n \t");
    foreach (QString ingredient , ingredientsList)
    {
         buffer.append(ingredient);
    }
    buffer.append("\n");
    buffer.append( "possibleAllergiesList");
    buffer.append("\n \t");
    foreach (QString allergie , possibleAllergiesList)
    {
         buffer.append(allergie);
    }
    return buffer;
}










