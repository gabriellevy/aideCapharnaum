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
};

#endif // METIER_H
