#include "metier.h"
#include <QTime>

Metier::Metier(QString id):m_GroupeMetier(id)
{
    // détermination du métier final parmi els sous métiers possibles à partir du métier déterminé
    if (id == "Artisan") {
        m_MetierFInal = METIERS_ARTISAN[rand() % METIERS_ARTISAN.length()];
    } else if (id == "Soldat") {
        m_MetierFInal = id + " ";
        m_MetierFInal += METIERS_GUERRIER[rand() % METIERS_GUERRIER.length()];
    } else if (id == "Mercenaire") {
        m_MetierFInal = id + " ";
        m_MetierFInal += METIERS_GUERRIER[rand() % METIERS_GUERRIER.length()];
    } else if (id == "Artiste") {
        m_MetierFInal = METIERS_ARTISTE[rand() % METIERS_ARTISTE.length()];
    } else if (id == "Malandrin") {
        m_MetierFInal = METIERS_MALANDRINS[rand() % METIERS_MALANDRINS.length()];
    } else {
        m_MetierFInal = id;
    }
}

QList<QString> Metier::METIERS_GUERRIER = {
    "artilleur",
    "tireur",
    "cavalier",
    "Fantassin lourd",
    "Fantassin léger",
    "Officier"

};

QList<QString> Metier::METIERS_ARTISAN = {
    "forgeron",
    "alchimiste",
    "Fabricant de bijou",
    "Fabricant de meubles",
    "Herboriste"
};

QList<QString> Metier::METIERS_ARTISTE = {
    "musicien",
    "sculpteur",
    "peintre",
    "comédien",
    "artiste de cirque",
    "danseur",
    "poète" ,
    "chanteur"
};

QList<QString> Metier::METIERS_MALANDRINS = {
    "Voleur",
    "Assassin",
    "Espion",
    "bandit",
    "Escroc"
};

QList<QString> Metier::METIERS = {
    "Marchand",
    "Malandrin",
    "Courtisan",
    "Aubergiste",
    "Dresseur/palefrenier",
    "Ingénieur/architecte",
    "Erudit",
    "Diplomate",
    "Artisan",
    "cultivateur",
    "bûcheron",
    "mineur",
    "chasseur",
    "Eleveur",
    "Pêcheur",
    "Soldat",
    "Mercenaire",
    "Banquier/prêteur",
    "Guérisseur/médecin",
    "Prêtre/moine",
    "Vagabond",
    "nomade",
    "Artiste",
    "Précepteur",
    "Marin"
};


Metier Metier::MetierAleatoire()
{
    return Metier(METIERS[rand() % METIERS.length()]);
}
