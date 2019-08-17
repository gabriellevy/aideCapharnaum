#include "age.h"
#include <chrono>
#include <random>

Age::Age(QString id):m_Tranche(id)
{
    // construct a trivial random generator engine from a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    if ( m_Tranche == TRANCHES[0]) {
        std::uniform_int_distribution<int> distribution(0,11);
        m_Age = 5 + distribution(generator);
    }else if ( m_Tranche == TRANCHES[1]) {
        std::uniform_int_distribution<int> distribution(0,10);
        m_Age = 15 + distribution(generator);
    }else if ( m_Tranche == TRANCHES[2]) {
        std::uniform_int_distribution<int> distribution(0,30);
        m_Age = 25 + distribution(generator);
    } else  {
        std::uniform_int_distribution<int> distribution(0,25);
        m_Age = 55 + distribution(generator);
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
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0,100);
    int val = distribution(generator);

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
