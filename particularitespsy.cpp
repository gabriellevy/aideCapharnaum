#include "particularitespsy.h"
#include <chrono>
#include <random>

QList<QString> ParticularitesPsy::PARTICULARITES = {
    "Bienveillant", "Malveillant", "Silencieux", "disert", "Mal élevé", "Peureux", "Courageux", "Simple",
    "Excentrique", "Egoïste", "Altruiste", "Manipulateur", "Fiable", "Rêveur", "attentif", "Discipliné",
    "Indiscipliné", "Pacifique", "Violent", "Autocrate", "Démocrate", "Solitaire", "sociable", "Fier",
    "effacé", "Ardent", "contenu", "Brouillon", "méthodique", "Mystique", "cartésien", "Pieux", "athée",
    "Débrouillard", "empoté", "Diplomate", "franc/brut de décoffrage", "Cruel", "magnanime", "drogué",
    "alcolique", "accroc aux femmes/hommes", "homosexuel", "phobie",
    "Schizophrène (hallucinations, trouble du comportement)", "Paranoïaque", "double personnalité",
    "Hystérique", "Monomaniaque", "Sadique", "Masochiste", "Maniaque", "TOC", "Mythomane"
};

ParticularitesPsy::ParticularitesPsy()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution6(0, 6);
    int val = distribution6(generator);

    std::uniform_int_distribution<int> distributionPartic(0, ParticularitesPsy::PARTICULARITES.size() - 1);

    m_Particularites = {};
    val -= 4;
    while ( val > 0) {
        int index = distributionPartic(generator);
        m_Particularites.push_back(ParticularitesPsy::PARTICULARITES[index]);
        val--;
    }
}

QString ParticularitesPsy::ToQString()
{
    QString strV = "";
    for ( auto str: this->m_Particularites) {
        if ( strV != "" )
            strV += ", ";
        strV += str;
    }
    return strV;
}
