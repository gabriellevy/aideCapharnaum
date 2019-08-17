#include "pnj.h"
#include <QTime>
#include "../destinLib/carac.h"
#include "../destinLib/gestionnairecarac.h"
#include "universcapharnaum.h"

Pnj::Pnj(QString id, QString nom, QString description, QString CheminImagePortrait)
    :DPerso(id, nom, description, CheminImagePortrait)
{}

void Pnj::InitialiserPerso()
{
    // génération aléatoire du perso :
    //this->m_Nom = GetUniversSkaven()->GenererNomSkaven();

    Carac* caracMetier = new Carac(UniversCapharnaum::CARAC_METIER,
                             UniversCapharnaum::CARAC_METIER,
                             "nom invalide",
                             "",
                             "Métier",
                             MODE_AFFICHAGE::ma_Texte);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracMetier);
    m_CaracsAAfficher.push_back(UniversCapharnaum::CARAC_METIER);

    Carac* caracAge = new Carac(UniversCapharnaum::CARAC_AGE,
                                   UniversCapharnaum::CARAC_AGE,
                                   "nom invalide",
                                   "",
                                   "Âge",
                                   MODE_AFFICHAGE::ma_Nombre);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracAge);
    m_CaracsAAfficher.push_back(UniversCapharnaum::CARAC_AGE);

    Carac* caracSexe = new Carac(UniversCapharnaum::CARAC_SEXE,
                                   UniversCapharnaum::CARAC_SEXE,
                                   "nom invalide",
                                   "",
                                   "Sexe",
                                   MODE_AFFICHAGE::ma_Texte);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracSexe);
    m_CaracsAAfficher.push_back(UniversCapharnaum::CARAC_SEXE);

    Carac* caracPeuple = new Carac(UniversCapharnaum::CARAC_PEUPLE,
                                   UniversCapharnaum::CARAC_PEUPLE,
                                   "nom invalide",
                                   "",
                                   "Peuple",
                                   MODE_AFFICHAGE::ma_Texte);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracPeuple);
    m_CaracsAAfficher.push_back(UniversCapharnaum::CARAC_PEUPLE);

    Carac* caracSousGroupe = new Carac(UniversCapharnaum::CARAC_SOUS_GROUPE,
                                   UniversCapharnaum::CARAC_SOUS_GROUPE,
                                   "pas de sous groupe",
                                   "",
                                   "Nation / Clan",
                                   MODE_AFFICHAGE::ma_Texte);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracSousGroupe);
    m_CaracsAAfficher.push_back(UniversCapharnaum::CARAC_SOUS_GROUPE);

    Carac* caracTaillec = new Carac(UniversCapharnaum::CARAC_TAILLE,
                             UniversCapharnaum::CARAC_TAILLE,
                             "nom invalide",
                             "",
                             "Taille",
                             MODE_AFFICHAGE::ma_Texte);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracTaillec);
    m_CaracsAAfficher.push_back(UniversCapharnaum::CARAC_TAILLE);

    Carac* caracPartic = new Carac(UniversCapharnaum::CARAC_PARTICULARITES,
                             UniversCapharnaum::CARAC_PARTICULARITES,
                             "nom invalide",
                             "",
                             "Particularités physiques",
                             MODE_AFFICHAGE::ma_Texte);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracPartic);
    m_CaracsAAfficher.push_back(UniversCapharnaum::CARAC_PARTICULARITES);

    Carac* caracParticPsy = new Carac(UniversCapharnaum::CARAC_PARTICUL_PSY,
                             UniversCapharnaum::CARAC_PARTICUL_PSY,
                             "nom invalide",
                             "",
                             "Particularités psychologiques",
                             MODE_AFFICHAGE::ma_Texte);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(caracParticPsy);
    m_CaracsAAfficher.push_back(UniversCapharnaum::CARAC_PARTICUL_PSY);
}



UniversCapharnaum* Pnj::GetUniversCapharnaum()
{
    return static_cast<UniversCapharnaum*>(Univers::ME);
}
