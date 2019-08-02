#include "sexe.h"

Sexe::Sexe(QString id):m_Sexe(id)
{

}

QString Sexe::MALE = "Homme";
QString Sexe::FEMELLE = "Femme";

QList<QString> Sexe::SEXES = {
    Sexe::MALE,
    Sexe::FEMELLE
};


// inégal car on rencontre beaucoup plus d'hommes que de femmes dont une bonne part ont peu de vie publique...
Sexe Sexe::Aleatoire() {
    int val = rand() % 100;
    QString id = "";
    if ( val < 70 )
        id = Sexe::MALE;
    else id = Sexe::FEMELLE;

    return Sexe(id);
}
