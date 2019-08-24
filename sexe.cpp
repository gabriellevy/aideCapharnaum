#include "sexe.h"
#include "../destinLib/aleatoire.h"
#include <QDebug>
#include "../destinLib/gestionnairecarac.h"
#include "universcapharnaum.h"
#include "metier.h"

QString Sexe::MALE = "Homme";
QString Sexe::FEMELLE = "Femme";

Sexe::Sexe()
{
    // l'aléatoire est inégal car
    // 1. on rencontre beaucoup plus d'hommes que de femmes dont une bonne part ont peu de vie publique
    // 2. certains métiers sont bien plus occupés par un sexe que par l'autre
     int val = Aleatoire::GetAl()->EntierInferieurA(100);

    QString metier = GestionnaireCarac::GetCaracValue(UniversCapharnaum::CARAC_METIER);

    m_Sexe = "";
    if ( ( metier == Metier::BATISSEUR && val < 95) ||
         metier == Metier::BUCHERON ||
            val < 70 )
        m_Sexe = Sexe::MALE;
    else m_Sexe = Sexe::FEMELLE;
}

QList<QString> Sexe::SEXES = {
    Sexe::MALE,
    Sexe::FEMELLE
};


