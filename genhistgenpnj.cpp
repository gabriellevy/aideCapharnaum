#include "genhistgenpnj.h"
#include "../destinLib/gestionnairecarac.h"
#include "universcapharnaum.h"
#include "pnj.h"
#include <QTime>
#include "metier.h"
#include "peuple.h"
#include "sexe.h"
#include "age.h"
#include "../destinLib/execeffet.h"

GenHistGenPnj::GenHistGenPnj(Hist* histoireGeneree):GenHistoire (histoireGeneree)
{
    QTime time = QTime::currentTime();
    qsrand(static_cast<uint>(time.msec()));
}

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

Effet* GenHistGenPnj::GenererEffetSelectionPeuple()
{
    Effet* effet = m_GenerateurEvt->AjouterEffetNarration("Quel est le peuple de votre pnj ?");

    Peuple peupleAlCaph(Peuple::AleatoireCapharnaum());
    Choix* choixAleatoire = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                 "Aleatoire du Capharnaum", UniversCapharnaum::CARAC_PEUPLE, peupleAlCaph.m_Peuple);
    Peuple peupleAlSud(Peuple::AleatoireSudJazirat());
    Choix* choixJazirat = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                "Aleatoire sur Jazirât", UniversCapharnaum::CARAC_PEUPLE, peupleAlSud.m_Peuple);

    for (int i = 0 ; i < Peuple::PEUPLES.length(); ++i) {
        Peuple peuple(Peuple::PEUPLES[i]);
        Choix* choixCourtisan = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                    peuple.m_Peuple, UniversCapharnaum::CARAC_PEUPLE, peuple.m_Peuple);

    }

    // mène direct à la fin de la génération en aléatoire complet :
    Peuple peupleAlCaph2(Peuple::AleatoireCapharnaum());
    Choix* choixAleatoireCaph = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                 "ALEATOIRE COMPLET", UniversCapharnaum::CARAC_PEUPLE, peupleAlCaph2.m_Peuple);
    // Age aléatoire aussi
    Age AgeAl2(Age::AgeAleatoire());
    choixAleatoireCaph->AjouterChangeurDeCarac( UniversCapharnaum::CARAC_AGE, QString::number(AgeAl2.m_Age));
    //sexe aléatoire aussi :
    Sexe SexeAl2(Sexe::Aleatoire());
    choixAleatoireCaph->AjouterChangeurDeCarac( UniversCapharnaum::CARAC_SEXE, SexeAl2.m_Sexe);
    choixAleatoireCaph->m_GoToEffetId = "FinGeneration";

    return effet;

}


Effet* GenHistGenPnj::GenererEffetSelectionMetier()
{
    Effet* effet = m_GenerateurEvt->AjouterEffetNarration("Quel est le métier de votre pnj ?");

    Metier metieAll(Metier::MetierAleatoire());
    Choix* choixAleatoire = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                 "Aleatoire", UniversCapharnaum::CARAC_METIER, metieAll.m_MetierFInal);

    for (int i = 0 ; i < Metier::METIERS.length(); ++i) {
        Metier metier(Metier::METIERS[i]);
        Choix* choixCourtisan = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                    metier.m_GroupeMetier, UniversCapharnaum::CARAC_METIER, metier.m_MetierFInal);

    }

    // mène direct à la fin de la génération en aléatoire complet :
    Metier metierAleatoire(Metier::MetierAleatoire());
    Choix* choixAleatoireComplet = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                 "ALEATOIRE COMPLET", UniversCapharnaum::CARAC_METIER, metieAll.m_MetierFInal);
    // peuple aléatoire aussi :
    Peuple peupleAlCaph2(Peuple::AleatoireCapharnaum());
    choixAleatoireComplet->AjouterChangeurDeCarac(UniversCapharnaum::CARAC_PEUPLE, peupleAlCaph2.m_Peuple);
    // Age aléatoire aussi
    Age AgeAl2(Age::AgeAleatoire());
    choixAleatoireComplet->AjouterChangeurDeCarac( UniversCapharnaum::CARAC_AGE, QString::number(AgeAl2.m_Age));
    //sexe aléatoire aussi :
    Sexe SexeAl2(Sexe::Aleatoire());
    choixAleatoireComplet->AjouterChangeurDeCarac( UniversCapharnaum::CARAC_SEXE, SexeAl2.m_Sexe);
    choixAleatoireComplet->m_GoToEffetId = "FinGeneration";

    return effet;
}


Effet* GenHistGenPnj::GenererEffetSelectionAge()
{
    Effet* effet = m_GenerateurEvt->AjouterEffetNarration("Quel est l'âge de votre pnj ?");

    Age AgeAl(Age::AgeAleatoire());
    Choix* choixAleatoire = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                "Aleatoire", UniversCapharnaum::CARAC_AGE, QString::number(AgeAl.m_Age));

    for (int i = 0 ; i < Age::TRANCHES.length(); ++i) {
        Age age(Age::TRANCHES[i]);
        m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                   age.m_Tranche, UniversCapharnaum::CARAC_AGE, ""+age.m_Age);

    }

    // mène direct à la fin de la génération en aléatoire complet :
    Age AgeAl2(Age::AgeAleatoire());
    Choix* choixAleatoireComplet = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                "ALEATOIRE COMPLET", UniversCapharnaum::CARAC_AGE, QString::number(AgeAl2.m_Age));
    //sexe aléatoire aussi :
    Sexe SexeAl2(Sexe::Aleatoire());
    choixAleatoireComplet->AjouterChangeurDeCarac( UniversCapharnaum::CARAC_SEXE, SexeAl2.m_Sexe);
    choixAleatoireComplet->m_GoToEffetId = "FinGeneration";

    return effet;
}

Effet* GenHistGenPnj::GenererEffetSelectionSexe()
{
    Effet* effet = m_GenerateurEvt->AjouterEffetNarration("Quel est le sexe de votre pnj ?");

    Sexe SexeAl(Sexe::Aleatoire());
    Choix* choixAleatoire = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                 "Aleatoire", UniversCapharnaum::CARAC_SEXE, SexeAl.m_Sexe);

    for (int i = 0 ; i < Sexe::SEXES.length(); ++i) {
        Sexe sexe(Sexe::SEXES[i]);
        m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                    sexe.m_Sexe, UniversCapharnaum::CARAC_SEXE, sexe.m_Sexe);

    }

    // mène direct à la fin de la génération en aléatoire complet :
    Sexe SexeAl2(Sexe::Aleatoire());
    Choix* choixAleatoireComplet = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                 "ALEATOIRE COMPLET", UniversCapharnaum::CARAC_SEXE, SexeAl2.m_Sexe);
    choixAleatoireComplet->m_GoToEffetId = "FinGeneration";

    return effet;
}

void DeterminerImageDepuisCaracs()
{
    QString sexe = GestionnaireCarac::GetCaracValue(UniversCapharnaum::CARAC_SEXE);
    int age = GestionnaireCarac::GetCaracValueAsInt(UniversCapharnaum::CARAC_AGE);
    QString metier = GestionnaireCarac::GetCaracValue(UniversCapharnaum::CARAC_METIER);
    QString peuple = GestionnaireCarac::GetCaracValue(UniversCapharnaum::CARAC_PEUPLE);

    QList<QString> ToutesLesImagesPossibles = {};

    qDebug()<<"sexe : "<<sexe<<endl;
    if ( sexe == Sexe::SEXES[0]) {
        // homme
        if ( peuple == Peuple::PEUPLES[0] || peuple == Peuple::PEUPLES[1]) // Saabi ou Shiradim
        {
            if ( age > 30) {
                if ( age < 50 ) {
                    ToutesLesImagesPossibles.push_back(":/images/0d22007cb3d8ca277746a367fd384424.jpg");
                }
            }
        }

    } else if (sexe == Sexe::SEXES[1]) {
        // femmes
        if ( age > 15) {
            if ( age < 40 ) {
                ToutesLesImagesPossibles.push_back(":/images/3b0d68a856bf507bfd0e2f2e6e626cd9.jpg");
            }
        }
    }

    QString portrait = ToutesLesImagesPossibles[rand() % ToutesLesImagesPossibles.length()];

    Univers::ME->GetExecHistoire()->GetExecEffetActuel(false)->ChargerImage(portrait);
}

void GenHistGenPnj::GenererEvtsAccueil()
{
    /*Evt* Debut = */this->AjouterEvt("Debut", "Génération du eprso par les choix");
    GenererEffetSelectionMetier();
    GenererEffetSelectionPeuple();
    GenererEffetSelectionSexe();

    m_GenerateurEvt->AjouterEffetCallbackDisplay(
                DeterminerImageDepuisCaracs,
                "Choix terminé", "", "FinGeneration" );
}
