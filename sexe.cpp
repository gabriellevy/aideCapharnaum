#include "sexe.h"
#include <chrono>
#include <random>
#include <QDebug>

QString Sexe::MALE = "Homme";
QString Sexe::FEMELLE = "Femme";

Sexe::Sexe()
{
    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0,100);

    // inégal car on rencontre beaucoup plus d'hommes que de femmes dont une bonne part ont peu de vie publique...
    int val = distribution(generator);

    m_Sexe = "";
    if ( val < 70 )
        m_Sexe = Sexe::MALE;
    else m_Sexe = Sexe::FEMELLE;
}

QList<QString> Sexe::SEXES = {
    Sexe::MALE,
    Sexe::FEMELLE
};


