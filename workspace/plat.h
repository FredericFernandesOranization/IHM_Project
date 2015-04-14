#ifndef PLAT_H
#define PLAT_H

#include <QString>
#include <QStringList>

class Plat
{

public:
    Plat();
private:
    int id;
    QString name;
    QString description;
    QString imagePath;
    QString shortDescription;
    float price;
    QStringList ingredientsList;
    QStringList possibleAllergiesList;
};

#endif // PLAT_H
