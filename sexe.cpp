#include "sexe.h"
#include <chrono>
#include <random>
#include <QDebug>
#include "../destinLib/gestionnairecarac.h"
#include "universcapharnaum.h"
#include "metier.h"

QString Sexe::MALE = "Homme";
QString Sexe::FEMELLE = "Femme";

Sexe::Sexe()
{
    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0,100);

    // l'aléatoire est inégal car
    // 1. on rencontre beaucoup plus d'hommes que de femmes dont une bonne part ont peu de vie publique
    // 2. certains métiers sont bien plus occupés par un sexe que par l'autre
    int val = distribution(generator);

    QString metier = GestionnaireCarac::GetCaracValue(UniversCapharnaum::CARAC_METIER);

    m_Sexe = "";
    if ( ( metier == Metier::BATISSEUR && val < 95) ||
            val < 70 )
        m_Sexe = Sexe::MALE;
    else m_Sexe = Sexe::FEMELLE;
}

QList<QString> Sexe::SEXES = {
    Sexe::MALE,
    Sexe::FEMELLE
};


