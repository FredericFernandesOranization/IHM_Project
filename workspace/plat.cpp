#include "plat.h"

Plat::Plat()
{

}
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








