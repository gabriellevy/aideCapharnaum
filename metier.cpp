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

QList<QString> Metier::METIERS_GUERRIER = {
    "artilleur",
    "tireur",
    Metier::CAVALIER,
    "Fantassin lourd",
    "Fantassin léger",
    "Officier"

};

QList<QString> Metier::METIERS_ARTISAN = {
    Metier::FORGERON,
    "alchimiste",
    "Fabricant de bijou",
    "Fabricant de meubles",
    "Herboriste"
};

QList<QString> Metier::METIERS_ARTISTE = {
    Metier::MUSICIEN,
    "sculpteur",
    "peintre",
    "comédien",
    "artiste de cirque",
    Metier::DANSEUR,
    "poète" ,
    "chanteur"
};

QList<QString> Metier::METIERS_MALANDRINS = {
    "Voleur",
    Metier::ASSASSIN,
    "Espion",
    "bandit",
    "Escroc"
};

QList<QString> Metier::METIERS = {
    Metier::MARCHAND,
    "Malandrin",
     Metier::COURTISAN,
    "Aubergiste",
    "Dresseur/palefrenier",
    "Ingénieur/architecte",
    Metier::ERUDIT,
    "Diplomate",
    "Artisan",
    "cultivateur",
    "bûcheron",
    "mineur",
    Metier::CHASSEUR,
    "Eleveur",
    "Pêcheur",
    Metier::SOLDAT,
    Metier::MERCENAIRE,
    "Banquier/prêteur",
    "Guérisseur/médecin",
    Metier::PRETRE,
    "Vagabond",
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

bool Metier::EstCavalier(QString metier)
{
    return (metier.right(Metier::CAVALIER.length()) == Metier::CAVALIER);
}

Metier Metier::MetierAleatoire()
{
    return Metier(METIERS[rand() % METIERS.length()]);
}
