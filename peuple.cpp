#include "peuple.h"

Peuple::Peuple(QString id):m_Peuple(id)
{

}

QString Peuple::ALFARIQN = "Alfariqn";
QString Peuple::SAABI = "Saabi";
QString Peuple::AGALANTHEEN = "Agalanthéen";
QString Peuple::SHIRADIM = "Shiradim";
QString Peuple::ESCARTE = "Escarte";

QList<QString> Peuple::PEUPLES = {
    Peuple::SAABI,
    Peuple::SHIRADIM,
    Peuple::ESCARTE,
    Peuple::AGALANTHEEN,
    Peuple::ALFARIQN
};

Peuple Peuple::AleatoireCapharnaum()
{
    int val = rand() % 100;
    QString id = "";
    if ( val < 35 )
        id = Peuple::SAABI;
    else if ( val < 75 )
        id = Peuple::PEUPLES[1];
    else if ( val < 90 )
        id = Peuple::PEUPLES[3];
    else if (val < 99)
        id = Peuple::PEUPLES[2];
    else {
        id = Peuple::ALFARIQN;
    }

    return Peuple(id);
}

Peuple Peuple::AleatoireSudJazirat()
{
    int val = rand() % 100;
    QString id = "";
    if ( val < 65 )
        id = Peuple::SAABI;
    else if ( val < 85 )
        id = Peuple::PEUPLES[1];
    else if ( val < 95 )
        id = Peuple::PEUPLES[3];
    else if (val < 99)
        id = Peuple::PEUPLES[2];
    else
        id = Peuple::ALFARIQN;

    return Peuple(id);
}
