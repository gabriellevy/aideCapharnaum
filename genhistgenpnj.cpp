#include "genhistgenpnj.h"
#include "../destinLib/gestionnairecarac.h"
#include "universcapharnaum.h"
#include "pnj.h"

GenHistGenPnj::GenHistGenPnj(Hist* histoireGeneree):GenHistoire (histoireGeneree) {}

Hist* GenHistGenPnj::GenererHistoire()
{
    GenererPersos();

    //GenererFonctionsCallback();

    GenererCaracs();

    GenererEvtsAccueil();

    return m_HistoireGeneree;
}

void GenHistGenPnj::GenererPersos()
{
    QString nom = "pas encore déterminé";
    Pnj* perso = new Pnj(nom, nom, nom, "");
    perso->InitialiserPerso();
    IPerso::AjouterPersoJouable(perso);
}

void GenHistGenPnj::GenererCaracs()
{
    //GetUniversSkaven()->GenererTousLesClans();
    // initilisée via le perso
}

Effet* GenHistGenPnj::GenererEffetSelectionMetier()
{
    Effet* effet = m_GenerateurEvt->AjouterEffetNarration("Quel est le métier de votre pnj ?");

    Choix* choixMarchand = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                "Marchand", UniversCapharnaum::CARAC_METIER, "Marchand");
    Choix* choixCourtisan = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                "Courtisan", UniversCapharnaum::CARAC_METIER, "Courtisan");

    return effet;
}

void GenHistGenPnj::GenererEvtsAccueil()
{
    /*Evt* Debut = */this->AjouterEvt("Debut", "Génération du eprso par les choix");
    GenererEffetSelectionMetier();
    m_GenerateurEvt->AjouterEffetNarration("Choix terminé");
}
