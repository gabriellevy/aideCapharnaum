#ifndef PEUPLE_H
#define PEUPLE_H

#include <QString>
#include <QList>


class Peuple
{
public:
    Peuple(QString id);

    QString m_Peuple;
    QString m_LieuOrigine;

    static QList<QString> PEUPLES;


    static Peuple AleatoireCapharnaum();
    static Peuple AleatoireSudJazirat();

    static QString ALFARIQN;
};

#endif // PEUPLE_H
