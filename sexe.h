#ifndef SEXE_H
#define SEXE_H

#include <QString>
#include <QList>


class Sexe
{
public:
    Sexe(QString id);

    QString m_Sexe;

    static QList<QString> SEXES;

    static Sexe Aleatoire();
};

#endif // SEXE_H