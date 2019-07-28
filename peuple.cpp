#include "peuple.h"

Peuple::Peuple(QString id):m_Peuple(id)
{

}

QList<QString> Peuple::PEUPLES = {
    "Saabi",
    "Shiradim",
    "Escarte",
    "Agalanthéen"
};

Peuple Peuple::AleatoireCapharnaum()
{
    int val = rand() % 100;
    QString id = "";
    if ( val < 35 )
        id = Peuple::PEUPLES[0];
    else if ( val < 75 )
        id = Peuple::PEUPLES[1];
    else if ( val < 90 )
        id = Peuple::PEUPLES[3];
    else
        id = Peuple::PEUPLES[2];

    return Peuple(id);
}

Peuple Peuple::AleatoireSudJazirat()
{
    int val = rand() % 100;
    QString id = "";
    if ( val < 65 )
        id = Peuple::PEUPLES[0];
    else if ( val < 85 )
        id = Peuple::PEUPLES[1];
    else if ( val < 95 )
        id = Peuple::PEUPLES[3];
    else
        id = Peuple::PEUPLES[2];

    return Peuple(id);
}
