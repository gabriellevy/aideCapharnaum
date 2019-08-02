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
    static QString SAABI;
    static QString AGALANTHEEN;
    static QString SHIRADIM;
    static QString ESCARTE;

    static QString GenererNom(QString peuple, QString sexe);
    static QVector<QString> NOMS_SAABI;
    static QVector<QString> PRENOMS_SAABI_MALES;
    static QVector<QString> PRENOMS_SAABI_FEMELLES;
};

#endif // PEUPLE_H
