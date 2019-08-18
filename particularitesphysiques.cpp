#include "particularitesphysiques.h"
#include <chrono>
#include <random>

QList<QString> ParticularitesPhysiques::PARTICULARITES = {
    "Nain", "Horrible cicatrice sur le visage", "Manchot", "Borgne", "Une seule jambe", "Cul de jatte",
    "Un bras bien plus musclé que l'autre", "très laid", "tatouage religieux", "tatouage tribal",
    "tatouage sentimental (famille, pays)", "piercing", "brûlure"
};

ParticularitesPhysiques::ParticularitesPhysiques()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution6(1, 6);
    int val = distribution6(generator);

    std::uniform_int_distribution<int> distributionPartic(0, ParticularitesPhysiques::PARTICULARITES.size() - 1);

    m_Particularites = {};
    val -= 4;
    while ( val > 0) {
        int index = distributionPartic(generator);
        m_Particularites.push_back(ParticularitesPhysiques::PARTICULARITES[index]);
        val--;
    }
}

QString ParticularitesPhysiques::ToQString()
{
    QString strV = "";
    for ( auto str: this->m_Particularites) {
        if ( strV != "" )
            strV += ", ";
        strV += str;
    }
    return strV;
}
