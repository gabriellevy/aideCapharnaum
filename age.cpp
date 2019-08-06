#include "age.h"
#include <QTime>

Age::Age(QString id):m_Tranche(id)
{
    QTime time = QTime::currentTime();
    qsrand(static_cast<uint>(time.msec()));
    if ( m_Tranche == TRANCHES[0]) {
        m_Age = 5 + rand()%11;
    }else if ( m_Tranche == TRANCHES[1]) {
        m_Age = 15 + rand()%10;
    }else if ( m_Tranche == TRANCHES[3]) {
        m_Age = 25 + rand()%30;
    } else  {
        m_Age = 55 + rand()%25;
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
    int val = rand() % 100;
    QString id = "";
    if ( val < 5 )
        id = Age::TRANCHES[0];
    else if ( val < 25 )
        id = Age::TRANCHES[1];
    else if ( val < 75 )
        id = Age::TRANCHES[2];
    else
        id = Age::TRANCHES[3];

    return Age(id);
}
