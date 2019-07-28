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

    static QString COURTISAN; // = noble au sens large, peut être diplomate ou autre mais avant tout riche et influent et de famille considérée
    static QString SOLDAT;
    static QString MERCENAIRE;
    static QString NOMADE;
};

#endif // METIER_H
