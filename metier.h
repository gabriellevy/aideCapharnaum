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

    static QString COURTISAN; // = noble au sens large, peut être diplomate ou autre mais avant tout riche et influent et de famille considérée
    static QString SOLDAT;
    static QString MERCENAIRE;
    static QString NOMADE;
    static QString FORGERON;
    static QString MUSICIEN;
    static QString CHASSEUR;
    static QString CAVALIER;
    static QString MARCHAND;
    static QString ERUDIT;
    static QString DANSEUR;
    static QString ASSASSIN;
    static QString PRETRE;
    static QString CIRQUE;
};

#endif // METIER_H
