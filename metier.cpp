#include "metier.h"
#include "../destinLib/aleatoire.h"
#include <QDebug>

Metier::Metier(QString id):m_GroupeMetier(id)
{
    // détermination du métier final parmi els sous métiers possibles à partir du métier déterminé
    if (id == "Artisan") {
        m_MetierFInal = METIERS_ARTISAN[Aleatoire::GetAl()->EntierInferieurA(METIERS_ARTISAN.length())];
    } else if (id == "Soldat") {
        m_MetierFInal = id + " ";
        m_MetierFInal += METIERS_GUERRIER[Aleatoire::GetAl()->EntierInferieurA(METIERS_GUERRIER.length())];
    } else if (id == "Mercenaire") {
        m_MetierFInal = id + " ";
        m_MetierFInal += METIERS_GUERRIER[Aleatoire::GetAl()->EntierInferieurA(METIERS_GUERRIER.length())];
    } else if (id == "Artiste") {
        m_MetierFInal = METIERS_ARTISTE[Aleatoire::GetAl()->EntierInferieurA(METIERS_ARTISTE.length())];
    } else if (id == "Malandrin") {
        m_MetierFInal = METIERS_MALANDRINS[Aleatoire::GetAl()->EntierInferieurA(METIERS_MALANDRINS.length())];
    } else {
        m_MetierFInal = id;
    }
}

QString Metier::DIPLOMATE = "Diplomate";
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
QString Metier::BATISSEUR = "Bâtisseur";
QString Metier::PECHEUR = "Pêcheur";
QString Metier::VOLEUR = "Voleur";
QString Metier::ESPION = "Espion";
QString Metier::BANDIT = "bandit";
QString Metier::ESCROC = "Escroc";
QString Metier::BANQUIER = "Banquier/prêteur";

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
    "Serviteur/esclave",
     Metier::COURTISAN,
    "Aubergiste",
    Metier::DRESSEUR,
    Metier::BATISSEUR,
    Metier::ERUDIT,
    Metier::DIPLOMATE,
    "Artisan",
    Metier::PAYSAN,
    Metier::BUCHERON,
    "mineur",
    Metier::CHASSEUR,
    Metier::ELEVEUR,
    Metier::PECHEUR,
    Metier::SOLDAT,
    Metier::MERCENAIRE,
    Metier::BANQUIER,
    "Guérisseur/médecin",
    Metier::PRETRE,
    Metier::VAGABOND,
    Metier::NOMADE,
    "Artiste",
    "Précepteur",
    "Marin"
};

bool Metier::PeutEtreRiche(QString metier)
{
    return (metier == Metier::DIPLOMATE ||
           metier == Metier::COURTISAN ||
            metier == Metier::BANQUIER ||
            metier == Metier::MARCHAND);
}

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
    int val = Aleatoire::GetAl()->EntierInferieurA(METIERS.length());
    return Metier(METIERS[val]);
}
