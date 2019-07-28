#include "sexe.h"

Sexe::Sexe(QString id):m_Sexe(id)
{

}


QList<QString> Sexe::SEXES = {
    "Homme",
    "Femme"
};

// inégal car on rencontre beaucoup plus d'hommes que de femmes dont une bonne part ont peu de vie publique...
Sexe Sexe::Aleatoire() {
    int val = rand() % 100;
    QString id = "";
    if ( val < 70 )
        id = Sexe::SEXES[0];
    else id = Sexe::SEXES[1];

    return Sexe(id);
}
