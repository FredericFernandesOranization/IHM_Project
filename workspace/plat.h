#ifndef PLAT_H
#define PLAT_H

#include <QString>
#include <QStringList>
#include <QDebug>
#include <qdebug.h>

#include <QMetaType>
class Plat
{

public:
    Plat();
    Plat(const Plat &pOther);
    ~Plat();

    //static Plat& copie(Plat p);
    inline Plat* clone(const Plat p){return new Plat(p);}

   // Plat* clone(const Plat p);
    Plat(QString name, QString description, QString imagePath, QString shortDescription,
         float price, QStringList ingredientsList, QStringList possibleAllergiesList,QString type);
    QString getName() const;
    void setName(const QString &value);

    QString getDescription() const;
    void setDescription(const QString &value);

    QString getImagePath() const;
    void setImagePath(const QString &value);

    QString getShortDescription() const;
    void setShortDescription(const QString &value);

    int getId() const;
    void setId(int value);

    float getPrice() const;
    void setPrice(float value);

    QStringList getIngredientsList() const;
    void setIngredientsList(const QStringList &value);

    QStringList getPossibleAllergiesList() const;
    void setPossibleAllergiesList(const QStringList &value);

    QString getType() const;
    void setType(const QString &value);
    virtual QString toString();

    static int nbPlat;
private:

    int id;
    QString name;
    QString type; //entrees, plats, boissons, desserts -> ce qui il y aura écrit dans le fichier XML!
    QString description;
    QString imagePath;
    QString shortDescription;
    float price;
    QStringList ingredientsList;
    QStringList possibleAllergiesList;
};
Q_DECLARE_METATYPE(Plat)
#endif // PLAT_H
