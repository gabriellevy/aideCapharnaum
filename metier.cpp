#include "metier.h"
#include <chrono>
#include <random>

Metier::Metier(QString id):m_GroupeMetier(id)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    // détermination du métier final parmi els sous métiers possibles à partir du métier déterminé
    if (id == "Artisan") {
        std::uniform_int_distribution<int> distribution(0, METIERS_ARTISAN.length()-1);
        m_MetierFInal = METIERS_ARTISAN[distribution(generator)];
    } else if (id == "Soldat") {
        m_MetierFInal = id + " ";
        std::uniform_int_distribution<int> distribution(0, METIERS_GUERRIER.length()-1);
        m_MetierFInal += METIERS_GUERRIER[distribution(generator)];
    } else if (id == "Mercenaire") {
        m_MetierFInal = id + " ";
        std::uniform_int_distribution<int> distribution(0, METIERS_GUERRIER.length()-1);
        m_MetierFInal += METIERS_GUERRIER[distribution(generator)];
    } else if (id == "Artiste") {
        std::uniform_int_distribution<int> distribution(0, METIERS_ARTISTE.length()-1);
        m_MetierFInal = METIERS_ARTISTE[distribution(generator)];
    } else if (id == "Malandrin") {
        std::uniform_int_distribution<int> distribution(0, METIERS_MALANDRINS.length()-1);
        m_MetierFInal = METIERS_MALANDRINS[distribution(generator)];
    } else {
        m_MetierFInal = id;
    }
}

QString Metier::COURTISAN = "Courtisan";
QString Metier::SOLDAT = "Soldat";
QString Metier::MERCENAIRE = "Mercenaire";
QString Metier::NOMADE = "Nomade";
QString Metier::FORGERON = "Forgeron";
QString Metier::MUSICIEN = "Musicien";
QString Metier::CHASSEUR = "Chasseur";
QString Metier::CAVALIER = "Cavalier";
QString Metier::MARCHAND = "Marchand";
QString Metier::ERUDIT = "Érudit";
QString Metier::DANSEUR = "Danseur";
QString Metier::ASSASSIN = "Assassin";
QString Metier::PRETRE = "Pretre";
QString Metier::CIRQUE = "Artiste de cirque";
QString Metier::ELEVEUR = "Éleveur";
QString Metier::CHARPENTIER = "Charpentier";
QString Metier::FABRICANT_MEUBLES = "Fabricant de meubles";
QString Metier::PAYSAN = "Paysan";
QString Metier::ARCHER = "Archer";
QString Metier::VAGABOND = "Vagabond";
QString Metier::DRESSEUR = "Dresseur/palefrenier";
QString Metier::BUCHERON = "Bûcheron";
QString Metier::PECHEUR = "Pêcheur";
QString Metier::VOLEUR = "Voleur";
QString Metier::ESPION = "Espion";
QString Metier::BANDIT = "bandit";
QString Metier::ESCROC = "Escroc";

QList<QString> Metier::METIERS_GUERRIER = {
    "artilleur",
    Metier::ARCHER,
    Metier::CAVALIER,
    "Fantassin lourd",
    "Fantassin léger",
    "Officier"
};

QList<QString> Metier::METIERS_ARTISAN = {
    Metier::FORGERON,
    Metier::CHARPENTIER,
    "alchimiste",
    "Fabricant de bijou",
    Metier::FABRICANT_MEUBLES,
    "Herboriste"
};

QList<QString> Metier::METIERS_ARTISTE = {
    Metier::MUSICIEN,
    "sculpteur",
    "peintre",
    "comédien",
    Metier::CIRQUE,
    Metier::DANSEUR,
    "poète" ,
    "chanteur"
};

QList<QString> Metier::METIERS_MALANDRINS = {
    Metier::ASSASSIN,
    Metier::VOLEUR,
    Metier::ESPION,
    Metier::BANDIT,
    Metier::ESCROC
};

QList<QString> Metier::METIERS = {
    Metier::MARCHAND,
    "Malandrin",
     Metier::COURTISAN,
    "Aubergiste",
    Metier::DRESSEUR,
    "Ingénieur/architecte",
    Metier::ERUDIT,
    "Diplomate",
    "Artisan",
    Metier::PAYSAN,
    Metier::BUCHERON,
    "mineur",
    Metier::CHASSEUR,
    Metier::ELEVEUR,
    Metier::PECHEUR,
    Metier::SOLDAT,
    Metier::MERCENAIRE,
    "Banquier/prêteur",
    "Guérisseur/médecin",
    Metier::PRETRE,
    Metier::VAGABOND,
    Metier::NOMADE,
    "Artiste",
    "Précepteur",
    "Marin"
};

bool Metier::EstGuerrier(QString metier)
{
    return ((metier.left(Metier::SOLDAT.length()) == Metier::SOLDAT) ||
            (metier.left(Metier::MERCENAIRE.length()) == Metier::MERCENAIRE));
}

bool Metier::EstMalandrin(QString metier)
{
    for (int i = 0 ; i < METIERS_MALANDRINS.length() ; ++i) {
         if ( metier == METIERS_MALANDRINS[i])
             return true;
    }
    return false;
}

bool Metier::EstCavalier(QString metier)
{
    return (metier.right(Metier::CAVALIER.length()) == Metier::CAVALIER);
}

Metier Metier::MetierAleatoire()
{
    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0,METIERS.length()-1);

    return Metier(METIERS[distribution(generator)]);
}
