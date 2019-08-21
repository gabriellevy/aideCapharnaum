#ifndef METIER_H
#define METIER_H

#include <QString>
#include <QList>

class Metier
{
public:
    Metier(QString id);

    QString m_MetierFInal;
    QString m_GroupeMetier;

    static QList<QString> METIERS;

    static QList<QString> METIERS_MALANDRINS;
    static QList<QString> METIERS_ARTISAN;
    static QList<QString> METIERS_GUERRIER;
    static QList<QString> METIERS_ARTISTE;

    static Metier MetierAleatoire();
    static bool EstGuerrier(QString metier);
    static bool EstCavalier(QString metier);
    static bool EstMalandrin(QString metier);

    /**
      * true si le métier en paramètre peut être celui d'une personne très richement habillée
      */
    bool PeutEtreRiche(QString metier);

    static QString COURTISAN; // = noble au sens large, peut être diplomate ou autre mais avant tout riche et influent et de famille considérée
    static QString SOLDAT;
    static QString BANQUIER;
    static QString DIPLOMATE;
    static QString MERCENAIRE;
    static QString NOMADE;
    static QString FORGERON;
    static QString MUSICIEN;
    static QString CHASSEUR;
    static QString ELEVEUR;
    static QString CAVALIER;
    static QString MARCHAND;
    static QString ERUDIT;
    static QString DANSEUR;
    static QString ASSASSIN;
    static QString PRETRE;
    static QString BATISSEUR;
    static QString CIRQUE;
    static QString CHARPENTIER;
    static QString FABRICANT_MEUBLES;
    static QString PAYSAN;
    static QString ARCHER;
    static QString VAGABOND;
    static QString DRESSEUR;
    static QString BUCHERON;
    static QString PECHEUR;
    static QString VOLEUR;
    static QString ESPION;
    static QString BANDIT;
    static QString ESCROC;
};

#endif // METIER_H
