#include "genhistgenpnj.h"
#include "../destinLib/gestionnairecarac.h"
#include "universcapharnaum.h"
#include "pnj.h"
#include <chrono>
#include <random>
#include "metier.h"
#include "peuple.h"
#include "sexe.h"
#include "age.h"
#include "../destinLib/perso.h"
#include "../destinLib/gestionnairecarac.h"
#include "../destinLib/execeffet.h"
#include "particularitesphysiques.h"
#include "particularitespsy.h"

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

Effet* GenHistGenPnj::GenererEffetSelectionPeuple()
{
    Effet* effet = m_GenerateurEvt->AjouterEffetNarration("Quel est le peuple de votre pnj ?");

    // mène direct à la fin de la génération en aléatoire complet :
    Peuple peupleAlCaph2(Peuple::AleatoireCapharnaum());
    Choix* choixAleatoireCaph = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                 "FIN DE PERSO ALEATOIRE", UniversCapharnaum::CARAC_PEUPLE, peupleAlCaph2.m_Peuple);
    choixAleatoireCaph->AjouterChangeurDeCarac(UniversCapharnaum::CARAC_SOUS_GROUPE, peupleAlCaph2.m_SousGroupe);
    // sous groupe tout aussi aléatoire :
    choixAleatoireCaph->AjouterChangeurDeCarac( UniversCapharnaum::CARAC_SOUS_GROUPE, peupleAlCaph2.m_SousGroupe);
    // Age aléatoire aussi
    Age AgeAl2(Age::AgeAleatoire());
    choixAleatoireCaph->AjouterChangeurDeCarac( UniversCapharnaum::CARAC_AGE, QString::number(AgeAl2.m_Age));
    //sexe aléatoire aussi :
    Sexe SexeAl2;
    choixAleatoireCaph->AjouterChangeurDeCarac( UniversCapharnaum::CARAC_SEXE, SexeAl2.m_Sexe);
    choixAleatoireCaph->m_GoToEffetId = "FinGeneration";

    Peuple peupleAlCaph(Peuple::AleatoireCapharnaum());
    Choix* choixalCaph = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                 "Aleatoire du Capharnaum", UniversCapharnaum::CARAC_PEUPLE, peupleAlCaph.m_Peuple);
    choixalCaph->AjouterChangeurDeCarac(UniversCapharnaum::CARAC_SOUS_GROUPE, peupleAlCaph.m_SousGroupe);
    Peuple peupleAlSud(Peuple::AleatoireSudJazirat());
    Choix* choixalSud = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                "Aleatoire du sud de Jazirât", UniversCapharnaum::CARAC_PEUPLE, peupleAlSud.m_Peuple);
    choixalSud->AjouterChangeurDeCarac(UniversCapharnaum::CARAC_SOUS_GROUPE, peupleAlCaph.m_SousGroupe);

    for (int i = 0 ; i < Peuple::PEUPLES.length(); ++i) {
        Peuple peuple(Peuple::PEUPLES[i]);
        Choix* choixPeuple = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                    peuple.m_Peuple, UniversCapharnaum::CARAC_PEUPLE, peuple.m_Peuple);

        // ajout de choix de sous nation
        if ( peuple.m_Peuple == Peuple::ESCARTE) {
            choixPeuple->m_GoToEffetId = "ChoixNationEscarte";
        } else {
            choixPeuple->m_GoToEffetId = "ChoixSexe";
        }
    }

    return effet;

}

Effet* GenHistGenPnj::GenererEffetSelectionNationEscarte()
{
    Effet* effet = m_GenerateurEvt->AjouterEffetNarration("De quel sous groupe de ce peuple fait partie votre pnj ?", "", "ChoixNationEscarte");

    // mène direct à la fin de la génération en aléatoire complet :
    Peuple escarteRand2(Peuple::AleatoireEscarte());
    Choix* choixAleatoireCaph = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                 "FIN DE PERSO ALEATOIRE", UniversCapharnaum::CARAC_SOUS_GROUPE, escarteRand2.m_SousGroupe);
    // Age aléatoire aussi
    Age AgeAl2(Age::AgeAleatoire());
    choixAleatoireCaph->AjouterChangeurDeCarac( UniversCapharnaum::CARAC_AGE, QString::number(AgeAl2.m_Age));
    //sexe aléatoire aussi :
    Sexe SexeAl2;
    choixAleatoireCaph->AjouterChangeurDeCarac( UniversCapharnaum::CARAC_SEXE, SexeAl2.m_Sexe);
    choixAleatoireCaph->m_GoToEffetId = "FinGeneration";

    Peuple escarteRand(Peuple::AleatoireEscarte());
    m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                 "Aleatoire", UniversCapharnaum::CARAC_SOUS_GROUPE, escarteRand.m_SousGroupe);

    for (int i = 0 ; i < Peuple::SOUS_GROUPE_ESCARTE.length(); ++i) {

        Choix* choixPeuple = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                    Peuple::SOUS_GROUPE_ESCARTE[i], UniversCapharnaum::CARAC_SOUS_GROUPE, Peuple::SOUS_GROUPE_ESCARTE[i]);

        choixPeuple->m_GoToEffetId = "ChoixSexe";

    }

    return effet;
}

Effet* GenHistGenPnj::GenererEffetSelectionMetier()
{
    Effet* effet = m_GenerateurEvt->AjouterEffetNarration("Quel est le métier de votre pnj ?", "", "EffetSelectionMetier");

    Metier metieAll(Metier::MetierAleatoire());

    // mène direct à la fin de la génération en aléatoire complet :
    Metier metierAleatoire(Metier::MetierAleatoire());
    Choix* choixAleatoireComplet = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                 "FIN DE PERSO ALEATOIRE", UniversCapharnaum::CARAC_METIER, metieAll.m_MetierFInal);
    // peuple aléatoire aussi :
    Peuple peupleAlCaph2(Peuple::AleatoireCapharnaum());
    choixAleatoireComplet->AjouterChangeurDeCarac(UniversCapharnaum::CARAC_PEUPLE, peupleAlCaph2.m_Peuple);
    choixAleatoireComplet->AjouterChangeurDeCarac(UniversCapharnaum::CARAC_SOUS_GROUPE, peupleAlCaph2.m_SousGroupe);
    // Age aléatoire aussi
    Age AgeAl2(Age::AgeAleatoire());
    choixAleatoireComplet->AjouterChangeurDeCarac( UniversCapharnaum::CARAC_AGE, QString::number(AgeAl2.m_Age));
    //sexe aléatoire aussi :
    Sexe SexeAl2;
    choixAleatoireComplet->AjouterChangeurDeCarac( UniversCapharnaum::CARAC_SEXE, SexeAl2.m_Sexe);
    choixAleatoireComplet->m_GoToEffetId = "FinGeneration";

    m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                 "Aleatoire", UniversCapharnaum::CARAC_METIER, metieAll.m_MetierFInal);

    for (int i = 0 ; i < Metier::METIERS.length(); ++i) {
        Metier metier(Metier::METIERS[i]);
        /*Choix* choixCourtisan =*/ m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                    metier.m_GroupeMetier, UniversCapharnaum::CARAC_METIER, metier.m_MetierFInal);

    }


    return effet;
}

Effet* GenHistGenPnj::GenererEffetSelectionAge()
{
    Effet* effet = m_GenerateurEvt->AjouterEffetNarration("Quel est l'âge de votre pnj ?");

    Age AgeAl(Age::AgeAleatoire());
    /*Choix* choixAleatoire =*/ m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                "Aleatoire", UniversCapharnaum::CARAC_AGE, QString::number(AgeAl.m_Age));

    for (int i = 0 ; i < Age::TRANCHES.length(); ++i) {
        Age age(Age::TRANCHES[i]);
        m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                   age.m_Tranche, UniversCapharnaum::CARAC_AGE, ""+ QString::number(age.m_Age));

    }

    return effet;
}

Effet* GenHistGenPnj::GenererEffetSelectionSexe()
{
    Effet* effet = m_GenerateurEvt->AjouterEffetNarration("Quel est le sexe de votre pnj ?", "", "ChoixSexe");

    // mène direct à la fin de la génération en aléatoire complet :
    Sexe SexeAl2;
    Choix* choixAleatoireComplet = m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                 "FIN DE PERSO ALEATOIRE", UniversCapharnaum::CARAC_SEXE, SexeAl2.m_Sexe);
    // Age aléatoire aussi
    Age AgeAl2(Age::AgeAleatoire());
    choixAleatoireComplet->AjouterChangeurDeCarac( UniversCapharnaum::CARAC_AGE, QString::number(AgeAl2.m_Age));
    choixAleatoireComplet->m_GoToEffetId = "FinGeneration";

    Sexe SexeAl;
    m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                 "Aleatoire", UniversCapharnaum::CARAC_SEXE, SexeAl.m_Sexe);

    for (int i = 0 ; i < Sexe::SEXES.length(); ++i) {
        m_GenerateurEvt->AjouterChoixChangeurDeCarac(
                    Sexe::SEXES[i], UniversCapharnaum::CARAC_SEXE, Sexe::SEXES[i]);

    }

    return effet;
}

void DeterminerTailleDepuisCaracs(QString sexe, int age, QString metier, QString peuple, QString sousGroupe)
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, 20);
    int taille = 0;

    if ( peuple == Peuple::SAABI || peuple == Peuple::SHIRADIM) {
        if ( sexe == Sexe::MALE) {
            taille = 160 + distribution(generator);
        } else {
            taille = 148 + distribution(generator);
        }
    } else if ( peuple == Peuple::ESCARTE) {
        if ( sousGroupe == Peuple::ARAGON) {
            if ( sexe == Sexe::MALE) {
                taille = 160 + distribution(generator);
            } else {
                taille = 149 + distribution(generator);
            }
        } else if ( sousGroupe == Peuple::OCCIDENTIN) {
            if ( sexe == Sexe::MALE) {
                taille = 164 + distribution(generator);
            } else {
                taille = 151 + distribution(generator);
            }
        } else if ( sousGroupe == Peuple::DORKADE) {
            if ( sexe == Sexe::MALE) {
                taille = 185 + distribution(generator);
            } else {
                taille = 175 + distribution(generator);
            }
        } else {
            qDebug() << "Pas de sous groupe escarte pour la taille !"<<endl;
        }
    } else if ( peuple == Peuple::AGALANTHEEN || peuple == Peuple::ALFARIQN) {
        if ( sexe == Sexe::MALE) {
            taille = 164 + distribution(generator);
        } else {
            taille = 151 + distribution(generator);
        }
    }

    GestionnaireCarac::SetValeurACaracId(UniversCapharnaum::CARAC_TAILLE, QString::number(taille));
}

void DeterminerImageDepuisCaracs(QString sexe, int age, QString metier, QString peuple, QString sousGroupe)
{
    QList<QString> ToutesLesImagesPossibles = {};

    if ( sexe == Sexe::MALE)/* hommes*/ {
        // homme
        // tous les peuples
        if ( Metier::EstMalandrin(metier)) {
            ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/d489410f69ac935fb57a9d21b5256baa.jpg");
        } else if ( metier == Metier::BATISSEUR && peuple != Peuple::ALFARIQN)/* je ets tous les bâtisseurs ici vu que c'est plus simple d'en trouver du moyen-âge chrétien mais ça pourra changer*/ {
            if ( age > 24) {
                if ( peuple == Peuple::SAABI) {
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/b02945f9449da15f9476c1599295fab5.jpg");
                }
                if ( age < 60) {
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/01645dcc7f2ff30f0e100e88c0090318.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/1fa106a847492f19545bf0293aa0f826.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/4e422dc328dec1a6e2f7f8bac0e6c8ee.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/8bfef3e252ac16cadeec0b91881d4faf.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/8dc4189e02bd46c7ce56313d157ffa04.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/96f3b68f0f220a087a31f996f9523705.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/9c1cee0c1ab3da840cfd8832bf71a773.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/c4d4acf53b660199b9958a9810363a79.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/d0b7acb7e6eb50c0688f9b72f31be4a0.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/dbad227bbfdbe2706cb88c4e77956103.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/dea5bcec585f74d2ed382a93ba5f5c5e.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/e088bcf1c6904d29e564f2664e45f17d.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/f809c56b91f208b8d28fdbe0861b8c29.jpg");

                } else /* vieux bâtisseur */ {
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/22f8b622e9a2efa8fd177a0d9ac3789d.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/2c017f109c503aaca5e9ec67861eac08.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/65495759a70a13491154372d6c941a75.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/a1d0874f1d12075c31e4549dce124f0d.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/c49e1b8d0b9c0f3086b92f566c5837db.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/dce8ff3b4ddd6d3d7b02cd15fa7a3248.jpg");

                }

            } else /* enfant bâtisseur */ {
                ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/46373aa973ff68578457f235180766d9.jpg");
                ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/6629bb1e4c6bac34d62d77377fecc01a.jpg");
                ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/6af65303c4f020188418e6df5d8cb53a.jpg");
                ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/dd224234571209bbeac2d72a7897384d.jpg");
                ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/fdff060c91cf28ca5bd3cdbfca8a7b38.jpg");

            }
        }
        if ( age > 20 ) {
            if (age < 50 ) {
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/c133738f676b3af58f7690c5f68fc655.jpg");
                if ( metier == Metier::CHASSEUR) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/c9d1d88a696586ca92506826257835ad.jpg");
                }
            } else /* vieux...*/ {
                ToutesLesImagesPossibles.push_back(":/images/Divers/866b2bef506b7a7ff76f1bdb20a53795.jpg");
            }
        }

        if ( peuple == Peuple::ALFARIQN) { // Alfariqn
            if ( age > 12 ) {
                if ( age > 20 ) {
                    if (age < 60 ) {
                        ToutesLesImagesPossibles.push_back(":/images/Divers/8be9db52c847046ec1781dccf7bae260 - Copie.jpg");
                        if ( age < 35 ) {
                            if ( age < 25 ) {
                                ToutesLesImagesPossibles.push_back(":/images/Alfariqn/fd3760efaa50fe851bc5c7d5cd405c4a.jpg");
                            }
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/b932664d9bd81994b263e5825d4d93dc.jpg");
                        }
                        ToutesLesImagesPossibles.push_back(":/images/Divers/07b7f04a04e8932b9d4a2c98a25b42f8.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Divers/07b7f04a04e8932b9d4a2c98a25b42f8 - Copie.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Alfariqn/0cc88d2d98926fbba4a7ed568ffc7c43.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Alfariqn/430a4f0991cd12d5ef3b05abb60d6c7b.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Alfariqn/58ef2fe13375765cb44d54bbcce77507.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Alfariqn/7885484f3d8cb3231d3794138f514e49.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Alfariqn/7937c4f5790b27f225974d35c5ce6b5a.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Alfariqn/c315e241f45ecc8341b276ac0f4da97f.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Alfariqn/ea0ae51882e088331a5e3c333b81b861.jpg");
                        if ( Metier::EstGuerrier(metier)) {
                            ToutesLesImagesPossibles.push_back(":/images/Divers/3602486f02a326920a57cfb81fb9b51f.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/278b24f0f60525ed3aaab30dfc351c21.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/97c222051fbb6da3fa447edef2ff6778.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/e25a9700b77f11b6cd35b2b36502255c.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Divers/ffe8b0f1b7f5882fc8ff738b18a20dd5 - Copie.jpg");
                        } else if ( metier == Metier::COURTISAN) {
                            ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/19235620-arabian-musician-medieval-market-oropesa-toledo-spain-21-04-2013.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/2e87c412a04f333a43c2d9e1beb6e75c.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/6a9c461a70873fd9bf7140a6dcdfc510.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/73606fc49a2870773e97222c4657ec52.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/7d77dbf9c06b7ff73937bac3a3b83c1b.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/f8324d4bf7612d5c55c3e1fd0a8aca27.jpg");
                        } else if ( metier == Metier::PRETRE) {
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/6c36ec57f6c9a5541727545d5d100044.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/f745f6a28f537bac5ad371d392561b4c.jpg");
                        } else if ( metier == Metier::DRESSEUR) {
                            ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/2b4689a3d3259c7ff6fc6c6c5d001ad0.jpg");
                        }
                    }
                }
            }
        }
        else if ( peuple == Peuple::SAABI) { // Saabi
            if ( metier == Metier::NOMADE) {
                if ( age < 25 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/8e0d0ef586c3edf951fcc1a51a024c43.jpg");
                }
            } else if ( Metier::EstGuerrier(metier)) {
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/f3e5769ecd9bb9717dcdfe0deaf72f31.jpg");
                ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/523f9eed62a39dda7dba90f58d68ee2a.jpg");
            } else if ( metier == Metier::DRESSEUR ) {
                if ( age > 20 )  {
                    if ( age < 60) {
                        ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/3164cf88178353f9b4a372d16978b8fa.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/569a06349c164fa3aa6f5d466d3265a7.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/a9022d8ab778c926634ffaf0f5e4738c.jpg");
                    }
                }
            }

            if ( age > 16) {
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/6e329b69b1b6de105cce57c87e25218c.jpg");
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/75aec4f5200c1255ac6287380a946a36.jpg");
                if ( age < 55 ) {
                    ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/339c742d3e0da9479b953076e452bdde.jpg");
                }

                if ( Metier::EstGuerrier(metier)) {
                    ToutesLesImagesPossibles.push_back(":/images/Divers/aac88c70480ca0a50f83c02ef01ebea5.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/6f4ca791bede07c98c8336ddf5af6162.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/74ea82a2ffc8bbb474c9cd8d50a01099.jpg");
                    if ( Metier::EstCavalier(metier))  {
                        ToutesLesImagesPossibles.push_back(":/images/Divers/b13270e47bdacd407905b320faeb5105 - Copie.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/c9e876999e7552a4c6079c9478c7795e.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/6e63042c2af68390385841d767d1beaa.jpg");
                    }
                    if ( age < 40) {
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/61d573a7ebd905d8c4d748a942c68b0b.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/94cad1aae692c8a303d7242637b559d5.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/9958d889992ae887b292b2f955c24219.jpg");
                    }
                } else if ( metier == Metier::COURTISAN) {
                    ToutesLesImagesPossibles.push_back(":/images/Divers/fb427748876194449c11d3f61f2b654a.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/798a074e8cd00f5d61dd1b331228b51f.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/9b1cc7aff22a3375cc17480cbb8bc5fe.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Divers/6ab119db33a32f46cf0cf4f1f99a4d15 - Copie.jpg");
                } else if ( metier == Metier::CHASSEUR ) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/c579641fd341d7ea737417a32676ad59.jpg");
                } else if ( metier == Metier::CIRQUE) {
                    ToutesLesImagesPossibles.push_back(":/images/Divers/e38a8a9a5678cbefde2a8195ef794a56.jpg");
                } else if  (metier == Metier::MUSICIEN) {
                   if ( age < 35 ) {
                       ToutesLesImagesPossibles.push_back(":/images/Divers/195f954a0cc64a510432c2c1177e0c30.jpg");
                   }
                } else if ( metier == Metier::DRESSEUR) {
                    ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/837a9471e4714ae993955c4eb7ef4872.jpg");
                }
            }
        } else if ( peuple == Peuple::SHIRADIM) // Shiradim
        {
            if (age > 55 ) {
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/6fe2457a0e47202be57fcfd3f72f554f.jpg");
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/78a2f1f90db5bd56f7dbabf9aedf63a3.jpg");
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/e394514a46b707d4e2d5e4c260376f2c.jpg");
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/f14e9cf58e49ca0c48b83e1ce1ba30f1.jpg");
            }
        }
        else if ( peuple == Peuple::ESCARTE) {
            if ( age > 16 ) {
                ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/41eef8f85eac97410afbb84f88f7b0bb - Copie (2).jpg");
                if ( Metier::EstGuerrier(metier)) {
                    ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/60f8753d3515c1c754234dad2f22cba3.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/5c1996335ae1f4cfa44f2221d720ede1.jpg");
                } else if ( metier==Metier::PRETRE) {
                    ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/e0cb2a041352a651cbddd74fdf2f4d3c.jpg");
                } else if ( metier == Metier::DRESSEUR) {
                    ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/cd21916507e3686221e60deb6a581db6.jpg");
                } else if (metier == Metier::BUCHERON) {
                    ToutesLesImagesPossibles.push_back(":/images/Bucheron/141ed218d3a6b84f2097d6e56ab2ee21.jpg");
                    if ( age < 55 ) /* jeune bûcheron */ {
                        ToutesLesImagesPossibles.push_back(":/images/Bucheron/2a214e6b0ea6f060d455dced808fb944.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Bucheron/59dbd491980adcdc090fd342e2604841.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Bucheron/913f1bcdd0955d8085068559070f3ff1.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Bucheron/d87f716cc804b26c19c43c32b77a28a1.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Bucheron/df4d05203600dda7468058461e1c9b73.jpg");

                    } else /* vieux bûcheron*/ {
                        ToutesLesImagesPossibles.push_back(":/images/Bucheron/9b90a8eed0d1c6d6a4d2a177ef4a4e08.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Bucheron/gettyimages-587492308-1024x1024.jpg");
                    }
                }
                if ( age > 40 ) {
                    if ( age < 70 ){
                        if ( metier == Metier::COURTISAN) {
                            ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/14267318e4e80365aaa26b87b4c25556 - Copie.jpg");
                        } else if (metier == Metier::FABRICANT_MEUBLES) {
                            ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/418442e79a6d0e30f5e9a101872a8d00.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/96f788ed6fe5242fee0e75eb25c8166c - Copie (2).jpg");
                        }
                    }
                }
                if ( age < 55 ) {
                    ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/b9479421c253fcd2a6efa89757544c4c.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/41eef8f85eac97410afbb84f88f7b0bb.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/08ecb51c8918f52f84b1624a9ddec153 - Copie (2).jpg");
                    if ( metier == Metier::ELEVEUR) {
                        ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/1913464_10203133102067826_152445759_o.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/0a5c568123d015944577095c208ea488.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/c538ae6e93af95a55171a841e50d523c.jpg");
                    } else if (metier == Metier::COURTISAN) {
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/14267318e4e80365aaa26b87b4c25556 - Copie (3).jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/14267318e4e80365aaa26b87b4c25556 - Copie (4).jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/14267318e4e80365aaa26b87b4c25556 - Copie (6).jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/2b5eb752aff68f234bf57174ca2c6f26 - Copie (2).jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/41eef8f85eac97410afbb84f88f7b0bb - Copie (7).jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/b9479421c253fcd2a6efa89757544c4c - Copie.jpg");
                        if ( age < 28 ) {
                           ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/b9479421c253fcd2a6efa89757544c4c - Copie (2).jpg");
                        }
                    }else if ( Metier::EstGuerrier(metier)) {
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/41eef8f85eac97410afbb84f88f7b0bb - Copie (3).jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/a5331a57f10d463b9970300bbf9055de.jpg");
                    } else if ( metier == Metier::MARCHAND) {
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/63e58cd14243d61124a8346983961dff - Copie.jpg");
                    } else if ( metier == Metier::PAYSAN) {
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/c7e3f465fc0a6ca618d411de7b6d5c01.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/604494d00fbfd5a6d934ff172dfbed0f - Copie.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/73d9631af3ab0510ab7aa65f0cc63e6e.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/814461c8838652d4ad2b97d9c41b9d04 - Copie.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/ac73ecd5d938967abfeb46d445ce5d04.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/bcf99925e53f1978f6d0dc72de69ad29.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/f8ddedb012827779365f9e942e059039.jpg");
                    } else if ( metier == Metier::ARCHER) {
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/80bf863b6dd27d866a08153d905253c5.jpg");
                    } else if ( metier == Metier::CHARPENTIER) {
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/a41992ad1a5ca99f4292870ac416b6ee.jpg");
                    } else if ( metier == Metier::MUSICIEN) {
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/e0cb2a041352a651cbddd74fdf2f4d3c - Copie.jpg");
                    } else if ( metier==Metier::CHASSEUR) {
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/f8026f778b43f5e49638590098f4fffd - Copie.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/f8026f778b43f5e49638590098f4fffd.jpg");
                    } else if ( metier==Metier::VAGABOND) {
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/fec1f50b944e7e45c0a0cd66681807d5.jpg");
                    }

                }
            } else {
                if ( age < 15) { /* enfants escartes*/
                    ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/08ecb51c8918f52f84b1624a9ddec153.jpg");
                    if (metier == Metier::COURTISAN) {
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/2b5eb752aff68f234bf57174ca2c6f26 - Copie (3).jpg");
                    } else if ( metier == Metier::FABRICANT_MEUBLES) {
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/96f788ed6fe5242fee0e75eb25c8166c.jpg");
                    } else if ( metier == Metier::DRESSEUR) {
                        ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/59d88374973c00d327ee50f925c21704.jpg");
                    }
                }
            }

        }
        else if ( peuple == Peuple::AGALANTHEEN) {
            if ( Metier::EstGuerrier(metier)) {
                ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/84dada1f224d52b7e3170ab941fb1096.jpg");
            }
        }

        if ( peuple == Peuple::SAABI || peuple == Peuple::SHIRADIM) /* Saabi ou Shiradim */
        {
            if ( Metier::EstGuerrier(metier)) {// guerriers :
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/647409fff9c8dfc7255aa03400951431.jpg");
                if ( age > 16) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/7fa0f20b5fbc4edfb2b18ac8d2e55748.jpg");
                    if ( age < 40) {
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/7059d29a6d90a655382956d76702317a.jpg");
                    }
                }
            } else if ( metier == Metier::FORGERON) {
                if ( age > 20) {
                    if ( age < 60 ) {
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/adbaab0e4c4131be4232e3d4eeb31098.jpg");
                    }
                }
            } else if (metier == Metier::MUSICIEN ) {
                if ( age > 20) {
                    if ( age < 60 ) {
                        ToutesLesImagesPossibles.push_back(":/images/Divers/db92117d9c23e353768b18616d84a25e.jpg");
                    }
                }
            } else if ( metier == Metier::DRESSEUR) {
                if ( age > 25 ) {
                    if ( age < 50 ) {
                        ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/04-buquet-fig-4-falconer-VA.jpg");
                    }
                }
            } else if ( metier == Metier::BUCHERON) {
                if ( age > 19 ) {
                    if ( age < 45 ){
                        ToutesLesImagesPossibles.push_back(":/images/Bucheron/61M5-2IyGNL._SX384_BO1,204,203,200_.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Bucheron/maxresdefault.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Bucheron/x1080.jpg");
                    }
                }
            } else if ( metier == Metier::PECHEUR) {
                if ( age > 25 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Pecheur/782ff0b44367bb0d97f4ad6f633a74b4.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Pecheur/adce2582dc9cd1d680002c445271d613.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Pecheur/b5932af55bae132f6b2b78cb3d15436b.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Pecheur/b70800b26c552845c836413800e62791.jpg");
                    if ( age > 50) {
                        ToutesLesImagesPossibles.push_back(":/images/Pecheur/5707708c7134c2b609d15d1f9abaaced.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Pecheur/81c98394f6e069f2fb8805238dea6390.jpg");

                    }
                }
            }

            if ( age > 16) {
                if ( metier == Metier::NOMADE) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/4cf1ae9cbd67747e3faa0ab22929bef7.jpg");
                }
                if ( age < 40) {
                    if ( metier == Metier::COURTISAN) {
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/215fddc7138b2ff9f70fb94eedf2a07e.jpg");
                    }
                }
                if ( age > 30) {
                    if ( metier == Metier::COURTISAN) {
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/149767922064770c0b9378083b75fba8.jpg");
                        if ( age < 50 ) {
                            ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/14e09bb348846084369766ac7c371a7e.jpg");
                        }
                    } else if ( Metier::EstGuerrier(metier)) {
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/13f0593d85c231948f3fc2ff8616f1db.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/483147199532bfddaf94951e54a19485.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/4ceae394a058429745eb1da0280c75a8.jpg");
                    }
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/2d825c6bd95d4598d19cf566632e1a1b.jpg");
                    if ( age < 55 ) /* age moyen */  {
                        ToutesLesImagesPossibles.push_back(":/images/Divers/aac88c70480ca0a50f83c02ef01ebea5 - Copie.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Divers/3602486f02a326920a57cfb81fb9b51f - Copie.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Divers/28a652d6ba8da5f75b0ec3d02ea39cbb.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/8b61811b9aece3ede2361fc7813481b3.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/360cd834aeb3e20a36bdd8ffe12e56c6.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/0d20e9bd8215b319f77f5534fce5f754.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/08729210ba1b31c5b6ea2846994bdd5b.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/0d22007cb3d8ca277746a367fd384424.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/11f2e20d7e38986df1719aab46318667.jpg");
                        if ( metier == Metier::MARCHAND) {
                            ToutesLesImagesPossibles.push_back(":/images/Saabi1/d3f40f2f4362c362935cd54534b836a5.jpg");
                        }
                    } else { // vieils hommes sabi / shiradim
                        ToutesLesImagesPossibles.push_back(":/images/Divers/28a652d6ba8da5f75b0ec3d02ea39cbb - Copie.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Divers/10a391a3feec5d37bc4eb39622b02512 - Copie.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/00f4e226c847a2a36c83303dcd99920e.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/04b8bdb2cb6ac6bc988684358e48ae36.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/43ff44b67a58ab8e8e23f4607d5b4687.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/6bca6564370cf66e74414d2d4bc5c7c3.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/806d238a90f7c608213f1845e1fcee42.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/8f327ba74f9d78f1806c80ef34b402bc.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/b565287a42183c5347fe1cc0b5b802dc.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/ccb20ba618d03b2e0223040af7b446bd.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/e8117f2f04c84c02155c8866925305b1.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Divers/db92117d9c23e353768b18616d84a25e - Copie (2).jpg");
                        if ( metier == Metier::MUSICIEN) {
                            ToutesLesImagesPossibles.push_back(":/images/Saabi1/bccb982b0e0280cfce8693824ba221fc.jpg");
                        } else if ( metier == Metier::COURTISAN) {
                            ToutesLesImagesPossibles.push_back(":/images/Saabi1/cc25c9bc0a393d46311bf7213ac774f1.jpg");
                        } else if ( metier == Metier::ERUDIT) {
                            ToutesLesImagesPossibles.push_back(":/images/Saabi1/d708d8d2cbc7daf7f4e399e39fe716f8.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Divers/faed1f2cf308518875fcf020697833b3 - Copie (2).jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Divers/faed1f2cf308518875fcf020697833b3 - Copie.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Divers/faed1f2cf308518875fcf020697833b3.jpg");
                        } else if ( metier == Metier::MARCHAND) {
                            ToutesLesImagesPossibles.push_back(":/images/Saabi1/e67a67251441f8224f4c9a7a69a4645e.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Saabi1/f90332b00b26b5aa09594ec1a088914d.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Divers/c20dffeb26a423583bf8aed3358a991b - Copie.jpg");
                        }

                    }
                }
                if ( age < 55 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Divers/134f7fc65de72adf463a7af4548fa7eb.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/3a727b713e68aec59c612f5760e5133a.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/ac395fd9393e738777ff0835fe1bafc5.jpg");
                }
            }
        }

    } else if (sexe == Sexe::FEMELLE)/* femmes*/ {
        // femmes
        if ( peuple == Peuple::SAABI || peuple == Peuple::SHIRADIM || peuple == Peuple::AGALANTHEEN) {
            if ( age > 15) {
                if ( age < 60 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/9cf7370699c72eecbe18bd80a8d34725.jpg");
                    if ( age < 40 ) {
                        ToutesLesImagesPossibles.push_back(":/images/Divers/e38a8a9a5678cbefde2a8195ef794a56 - Copie.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Divers/c20dffeb26a423583bf8aed3358a991b - Copie (2).jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Divers/10fccd8c43d42992bc8d93a9eeadd087 - Copie.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Divers/10a391a3feec5d37bc4eb39622b02512.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/bc8b9345061a628a80f2f8df86a817c7.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/ce05271435ccac3e83e984682e55d4f1.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/f55b22471912bcf746d0767dc95af45d.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Divers/10fccd8c43d42992bc8d93a9eeadd087.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Divers/134f7fc65de72adf463a7af4548fa7eb - Copie.jpg");
                        if ( metier == Metier::COURTISAN) {
                            ToutesLesImagesPossibles.push_back(":/images/Divers/6ab119db33a32f46cf0cf4f1f99a4d15.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Saabi1/2389ecfa77c450d7b529473d3c6f62a4.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Saabi1/6c0e7528d8626443dbe17dd0a34d9b3b.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Divers/fb427748876194449c11d3f61f2b654a - Copie.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Divers/ffe8b0f1b7f5882fc8ff738b18a20dd5.jpg");
                        } else if (metier == Metier::ASSASSIN ) {
                            ToutesLesImagesPossibles.push_back(":/images/Saabi1/f91f78ac4b2dc8b451b56b1c763a54d4.jpg");
                        } else if ( metier == Metier::DANSEUR) {
                            ToutesLesImagesPossibles.push_back(":/images/Divers/195f954a0cc64a510432c2c1177e0c30 - Copie.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Divers/8360db4df800981718d151e9b5167af2 - Copie.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Divers/8360db4df800981718d151e9b5167af2.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Divers/f87e681acca1afe7fb42c77c17d84b04.jpg");
                        } else if ( metier == Metier::MUSICIEN) {
                            ToutesLesImagesPossibles.push_back(":/images/Divers/a998bb83a831301588a77e62cd95d022.jpg");
                        }
                    }
                }
            } else {
                // petites filles
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/67efe71502e501bb60c3da6cc29559e9.jpg");
            }
        }
        if ( peuple == Peuple::SAABI || peuple == Peuple::SHIRADIM) // Saabi ou Shiradim
        {
            if ( metier == Metier::MUSICIEN) {
                if ( age < 50 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/b9ea148adc06b739a1ec01c7d561158a.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/ff25cfb4b1ed4615aca8276efbdc8bab.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Divers/866b2bef506b7a7ff76f1bdb20a53795 - Copie.jpg");
                }
            } else if ( metier == Metier::DANSEUR) {
                if ( age < 35 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/f4aa631dc92576174b797594599b2fcc.jpg");
                }
            }
            if ( age > 15) {
                if ( Metier::EstGuerrier(metier)) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/37495a30404751846515af3be96f4765.jpg");
                } else if ( metier == Metier::DRESSEUR) {
                    if ( age < 50 ) {
                        ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/36027e8eb1417cff130a1a8afbd06566.jpg");
                    }
                }
                if ( age > 25 ) {
                    ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/b07d28a31c51986cfffd9e7f0142919a.jpg");
                    if ( age < 50 ) {
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/b05ba59aca2dca95106eabc8c22ffc3c.jpg");
                    }
                }
                if ( age < 30) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/7311a06e4a7b88847e3e7feb32a85748.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/85baeb2e9ce3192d5d8795d89ad14390.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/eecdfd1a2152e72892822c4c5282b656.jpg");
                }

                if ( age < 40 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/017d994d30f3f355efc880fdb2d82b37.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/320649b804b5c6a0ee46f3abe2861f10.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/3a99a81b0ba385c7490d1f988b2698c7.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/3b0d68a856bf507bfd0e2f2e6e626cd9.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/432727dc5a3cd11b3ff92bb4611876a9.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/4744e52cb24aa06ccb05ea4185ef5aaf.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/4dc2ad29938f56ba3ca3caf46ee1d809.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/57cd7bed8f3c9ebf604d34d014fe19f3.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/5ada86d2fa90e5b2f32a76d8e526c070.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/61cbc911c6cb1fd826ab30a66e2e8918.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/ee22f70373444c8024ca7d9b383800a4.jpg");

                }
            }
        }
        if ( peuple == Peuple::AGALANTHEEN) // Agalanthéenne
        {
            if ( age > 15) {
                if ( age < 40 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/23525f4be95ebb4a5bc128d001380ed3.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/556dc4ce75f6c8cdfbdd1eb9b4d9944b.jpg");

                }
            }
        } else if ( peuple == Peuple::ALFARIQN) { // Alfariqn
            if ( age > 14 ) {
                if (age < 60 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Divers/ba77241a2766ee4980fd604e549261b3 - Copie.jpg");
                    if (age < 40 ) {
                        ToutesLesImagesPossibles.push_back(":/images/Alfariqn/ba95559eddf39af8000e8c85a24554d1.jpg");
                    }
                }
            }

        } else if ( peuple == Peuple::SAABI ) {
            if ( metier == Metier::COURTISAN) {
                if ( age < 50 ) {
                    ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/2a9703412c181423cfbccb716a4185f4.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Divers/94a9edddd34edcecdeac33611702a21f - Copie.jpg");
                }
            } else if ( metier == Metier::ERUDIT) {
                if ( age < 50 ){
                    ToutesLesImagesPossibles.push_back(":/images/Divers/a998bb83a831301588a77e62cd95d022 - Copie.jpg");
                }
            }
        } else if ( peuple == Peuple::SHIRADIM) {
            if ( metier == Metier::DANSEUR) {
                if ( age < 40 ) {
                ToutesLesImagesPossibles.push_back(":/images/Divers/f87e681acca1afe7fb42c77c17d84b04 - Copie.jpg");
                }
            }
        }else if ( peuple == Peuple::ESCARTE) {
            if ( age > 16) {
                if ( age > 40 ) {
                    ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/41eef8f85eac97410afbb84f88f7b0bb - Copie (4).jpg");
                    ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/14267318e4e80365aaa26b87b4c25556.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/41eef8f85eac97410afbb84f88f7b0bb - Copie (5).jpg");
                    ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/41eef8f85eac97410afbb84f88f7b0bb - Copie (6).jpg");
                    ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/41eef8f85eac97410afbb84f88f7b0bb - Copie.jpg");
                    if ( age > 60 ) /* vieilles escartes */ {
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/14267318e4e80365aaa26b87b4c25556.jpg");
                        if ( metier == Metier::PAYSAN) {
                            ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/10363586_10203832702397397_6483138334025301259_n.jpg");
                        }
                    }
                }
                if ( age < 60 ) {
                    if ( metier == Metier::PAYSAN) {
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/604494d00fbfd5a6d934ff172dfbed0f.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/73d9631af3ab0510ab7aa65f0cc63e6e - Copie.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/814461c8838652d4ad2b97d9c41b9d04.jpg");
                    } else if ( metier==Metier::FABRICANT_MEUBLES) {
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/96f788ed6fe5242fee0e75eb25c8166c - Copie.jpg");
                    } else if ( Metier::EstGuerrier(metier)) {
                        ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/34b0f21fad633e97857949beac3153a3.jpg");
                    }
                    if ( age < 50) {
                        if ( age < 35 ) {
                            if ( metier == Metier::DRESSEUR) {
                                ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/5a41d919a2ffecf31e31806e7689086d.jpg");
                                ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/c90339443334983d3de03bbd4603a83c.jpg");
                            }
                            ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/ed26955f4f3c615a49fcd6b4dd916d9e.jpg");
                        }
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/08ecb51c8918f52f84b1624a9ddec153 - Copie.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/14267318e4e80365aaa26b87b4c25556 - Copie (2).jpg");
                        if ( metier == Metier::COURTISAN) {
                            ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/2b5eb752aff68f234bf57174ca2c6f26 - Copie (4).jpg");
                            ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/14267318e4e80365aaa26b87b4c25556 - Copie (5).jpg");
                            ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/14267318e4e80365aaa26b87b4c25556 - Copie (7).jpg");
                        } else if ( metier == Metier::MARCHAND) {
                            ToutesLesImagesPossibles.push_back(":/images/PaysanEscarte/63e58cd14243d61124a8346983961dff.jpg");
                        } else if (Metier::EstCavalier(metier)) {
                            ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/5e01f01691ae0050afa05897218ba885.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/e8f23714dce7cbef3b44602a8846f043.jpg");
                        }
                   }
                }
            }
        }
        else if ( peuple == Peuple::AGALANTHEEN) {
            if ( age > 16 ) {
                if ( age < 40 ) {
                    ToutesLesImagesPossibles.push_back(":/images/DresseurSaabi/84dada1f224d52b7e3170ab941fb1096 - Copie.jpg");
                }
            }
        }
    }




    ToutesLesImagesPossibles.push_back(":/images/Bâtisseur/fdff060c91cf28ca5bd3cdbfca8a7b38.jpg");

    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);
    std::uniform_int_distribution<int> distribution(0, ToutesLesImagesPossibles.length()-1);

    QString portrait = ToutesLesImagesPossibles[ distribution(generator) ];

    Univers::ME->GetExecHistoire()->GetExecEffetActuel(false)->ChargerImage(portrait);

    // génération du nom
    QString nom = Peuple::GenererNom(peuple, sexe, sousGroupe);
    IPerso::GetPersoInterface()->GetPersoCourant()->MajNom(nom);
    IPerso::GetPersoInterface()->RafraichirAffichage();

    Univers::ME->GetExecHistoire()->GetExecEffetActuel(false)->GetEffet()->m_Text += (
                " " + portrait + "\n" + nom
                );

}

void FinaliserPerso()
{
   // ajout de compétences/caractéristqiues aléatoires :
   ParticularitesPhysiques particularites;
   QString particularitesStr = particularites.ToQString();
   GestionnaireCarac::SetValeurACaracId(UniversCapharnaum::CARAC_PARTICULARITES, particularitesStr);

   ParticularitesPsy particul;
   QString particulStr = particul.ToQString();
   GestionnaireCarac::SetValeurACaracId(UniversCapharnaum::CARAC_PARTICUL_PSY, particulStr);

   QString sexe = GestionnaireCarac::GetCaracValue(UniversCapharnaum::CARAC_SEXE);
   int age = GestionnaireCarac::GetCaracValueAsInt(UniversCapharnaum::CARAC_AGE);
   QString metier = GestionnaireCarac::GetCaracValue(UniversCapharnaum::CARAC_METIER);
   QString peuple = GestionnaireCarac::GetCaracValue(UniversCapharnaum::CARAC_PEUPLE);
   QString sousGroupe = GestionnaireCarac::GetCaracValue(UniversCapharnaum::CARAC_SOUS_GROUPE);

   DeterminerTailleDepuisCaracs( sexe, age, metier, peuple, sousGroupe);
   DeterminerImageDepuisCaracs( sexe, age, metier, peuple, sousGroupe);
}

void GenHistGenPnj::GenererEvtsAccueil()
{
    /*Evt* Debut = */this->AjouterEvt("Debut", "Génération du eprso par les choix");
    GenererEffetSelectionMetier();
    GenererEffetSelectionPeuple();
    GenererEffetSelectionNationEscarte();
    GenererEffetSelectionSexe();
    GenererEffetSelectionAge();

    m_GenerateurEvt->AjouterEffetCallbackDisplay(
                FinaliserPerso,
                "Choix terminé", "", "FinGeneration" );

    Effet* effetRetourDebut = m_GenerateurEvt->AjouterEffetVide();
    effetRetourDebut->m_Id = "effetRetourDebut";
    effetRetourDebut->m_GoToEffetId = "EffetSelectionMetier";
}
