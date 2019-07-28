#include "genhistgenpnj.h"
#include "../destinLib/gestionnairecarac.h"

GenHistGenPnj::GenHistGenPnj(Hist* histoireGeneree):GenHistoire (histoireGeneree) {}

Hist* GenHistGenPnj::GenererHistoire()
{
    GenererPersos();

    GenererFonctionsCallback();

    GenererCaracs();

    GenererEvtsAccueil();

    return m_HistoireGeneree;
}

void GenHistGenPnj::GenererPersos()
{
    QString nom = "pas encore déterminé";
    DPerso* perso = new DPerso(nom, nom, nom, "");
    IPerso::AjouterPersoJouable(perso);
}

void GenHistGenPnj::GenererCaracs()
{
    //GetUniversSkaven()->GenererTousLesClans();

    /*Carac* carac = new Carac(UniversSkaven::CARAC_FOURRURE,
                             UniversSkaven::CARAC_FOURRURE,
                             "nom invalide",
                             "",
                             "Couleur de fourrure et signes particuliers",
                             MODE_AFFICHAGE::ma_Texte);
    GestionnaireCarac::GetGestionnaireCarac()->AjouterCarac(carac);*/
}

Effet* GenHistGenPnj::GenererEffetSelectionMetier()
{
    Effet* effet = m_GenerateurEvt->AjouterEffetNarration("Quel est le métier de votre pnj ?");
    Choix* choixMarchand = m_GenerateurEvt->AjouterChoixVide();
    choixMarchand->m_Text = "Marchand";

    return effet;
}

void GenHistGenPnj::GenererEvtsAccueil()
{
    /*Evt* Debut = */this->AjouterEvt("Debut", "Génération du eprso par les choix");
    GenererEffetSelectionMetier();
}
