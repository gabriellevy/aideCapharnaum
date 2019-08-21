#include "age.h"
#include "../destinLib/aleatoire.h"

Age::Age(QString id):m_Tranche(id)
{
    if ( m_Tranche == TRANCHES[0]) {
        m_Age = 5 + Aleatoire::GetAl()->EntierInferieurA(11);
    }else if ( m_Tranche == TRANCHES[1]) {
        m_Age = 15 + Aleatoire::GetAl()->EntierInferieurA(11);
    }else if ( m_Tranche == TRANCHES[2]) {
        m_Age = 25 + Aleatoire::GetAl()->EntierInferieurA(30);
    } else  {
        m_Age = 55 + Aleatoire::GetAl()->EntierInferieurA(26);
    }
}

QList<QString> Age::TRANCHES = {
    "Enfant",
    "Jeune",
    "Adulte",
    "Vieux"
};

Age Age::AgeAleatoire()
{
    int val = Aleatoire::GetAl()->EntierInferieurA(100);

    QString id = "";
    if ( val < 5 )
        id = Age::TRANCHES[0];
    else if ( val < 25 )
        id = Age::TRANCHES[1];
    else if ( val < 82 )
        id = Age::TRANCHES[2];
    else
        id = Age::TRANCHES[3];

    return Age(id);
}
