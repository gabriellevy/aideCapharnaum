#ifndef SEXE_H
#define SEXE_H

#include <QString>
#include <QList>


class Sexe
{
public:
    Sexe();

    QString m_Sexe;

    static QList<QString> SEXES;

    static QString MALE;
    static QString FEMELLE;

    // random system :
    //std::default_random_engine generator;
    //std::uniform_int_distribution<int> distribution;
};

#endif // SEXE_H
