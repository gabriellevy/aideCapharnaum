#include "peuple.h"
#include <QTime>
#include "sexe.h"

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


QString Peuple::GenererNom(QString peuple, QString sexe)
{
    if ( peuple == Peuple::SAABI) {
        return ( (sexe == Sexe::MALE) ?
                 Peuple::PRENOMS_SAABI_MALES[rand() % Peuple::PRENOMS_SAABI_MALES.length()] :
                 Peuple::PRENOMS_SAABI_FEMELLES[rand() % Peuple::PRENOMS_SAABI_FEMELLES.length()] )
                + " " +
                Peuple::NOMS_SAABI[rand() % Peuple::NOMS_SAABI.length()];
    }

    return "pas de nom";
}

QVector<QString> Peuple::NOMS_SAABI = {"Aabdi", "Abdi"};

QVector<QString> Peuple::PRENOMS_SAABI_MALES = {
    "Aarab", "Abbas", "Abbes", "Abd Al-Ali", "Abd Al-Hafid", "Abd Al-Hakim", "Abd Al-Halim",
    "Abd Al-Hamid", "Abd Al-Haqq", "Abd Allâh ", "Abd Ash-Shahid", "Abd Ash-Shakour ", "Abd Al-Kader", "Abd Al-Karim",
    "Abd Ul-Latif", "Abd Al-Mouqit ", "Abdel", "Abdelmajid", "Abdelmoudjib", "Abdelmouneim", "Abd Al-Wahab",
    "Abd Al-Wahid", "Abd An-Nour", "Azmar", "Bassel", "Khmaies", "Youssef", "Abd Al-Wahab",
};
QVector<QString> Peuple::PRENOMS_SAABI_FEMELLES = {"Atiqua"};

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
