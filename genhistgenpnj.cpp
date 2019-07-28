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
        if ( peuple == Peuple::PEUPLES[0]) { // Saabi
            if ( age > 16) {
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/6e329b69b1b6de105cce57c87e25218c.jpg");
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/75aec4f5200c1255ac6287380a946a36.jpg");

                if ( Metier::EstGuerrier(metier)) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/6f4ca791bede07c98c8336ddf5af6162.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/74ea82a2ffc8bbb474c9cd8d50a01099.jpg");
                    if ( age < 40) {
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/61d573a7ebd905d8c4d748a942c68b0b.jpg");
                    }
                } else if ( metier == Metier::COURTISAN) {

                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/798a074e8cd00f5d61dd1b331228b51f.jpg");
                }
            }
        }

        if ( peuple == Peuple::PEUPLES[1]) // Shiradim
        {
            if (age > 55 ) {
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/6fe2457a0e47202be57fcfd3f72f554f.jpg");
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/78a2f1f90db5bd56f7dbabf9aedf63a3.jpg");
            }
        }

        if ( peuple == Peuple::PEUPLES[0] || peuple == Peuple::PEUPLES[1]) // Saabi ou Shiradim
        {
            if ( Metier::EstGuerrier(metier)) {// guerriers :
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/647409fff9c8dfc7255aa03400951431.jpg");
                if ( age > 16) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/7fa0f20b5fbc4edfb2b18ac8d2e55748.jpg");
                    if ( age < 40) {
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/7059d29a6d90a655382956d76702317a.jpg");
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
                    } else if ( Metier::EstGuerrier(metier)) {
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/483147199532bfddaf94951e54a19485.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/4ceae394a058429745eb1da0280c75a8.jpg");
                    }
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/2d825c6bd95d4598d19cf566632e1a1b.jpg");
                    if ( age < 55 ) {
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/8b61811b9aece3ede2361fc7813481b3.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/360cd834aeb3e20a36bdd8ffe12e56c6.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/0d20e9bd8215b319f77f5534fce5f754.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/08729210ba1b31c5b6ea2846994bdd5b.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/0d22007cb3d8ca277746a367fd384424.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/11f2e20d7e38986df1719aab46318667.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/13f0593d85c231948f3fc2ff8616f1db.jpg");
                    } else { // vieils hommes sabi shiradim
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/00f4e226c847a2a36c83303dcd99920e.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/04b8bdb2cb6ac6bc988684358e48ae36.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/43ff44b67a58ab8e8e23f4607d5b4687.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/6bca6564370cf66e74414d2d4bc5c7c3.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/806d238a90f7c608213f1845e1fcee42.jpg");

                    }
                }
                if ( age < 55 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/3a727b713e68aec59c612f5760e5133a.jpg");
                }
            }
        }

    } else if (sexe == Sexe::SEXES[1]) {
        // femmes
        // tous les peuples
        if ( age > 15) {
            if ( age < 40 ) {
                if ( metier == Metier::COURTISAN) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/2389ecfa77c450d7b529473d3c6f62a4.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/6c0e7528d8626443dbe17dd0a34d9b3b.jpg");
                }
            }
        } else {
            // petites filles
            ToutesLesImagesPossibles.push_back(":/images/Saabi1/67efe71502e501bb60c3da6cc29559e9.jpg");

        }
        if ( peuple == Peuple::PEUPLES[0] || peuple == Peuple::PEUPLES[1]) // Saabi ou Shiradim
        {
            if ( age > 15) {
                if ( Metier::EstGuerrier(metier)) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/37495a30404751846515af3be96f4765.jpg");
                }
                if ( age < 30) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/7311a06e4a7b88847e3e7feb32a85748.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/85baeb2e9ce3192d5d8795d89ad14390.jpg");
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

                }
            }
        } else if ( peuple == Peuple::PEUPLES[3]) // Agalenthéenne
        {
            if ( age > 15) {
                if ( age < 40 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/23525f4be95ebb4a5bc128d001380ed3.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/556dc4ce75f6c8cdfbdd1eb9b4d9944b.jpg");

                }
            }
        }
    }

    ToutesLesImagesPossibles.push_back(":/images/Saabi1/8be9db52c847046ec1781dccf7bae260.jpg");

    if ( false) {
        // gardé pour plus tard :(noirs...)
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/07b7f04a04e8932b9d4a2c98a25b42f8.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/0cc88d2d98926fbba4a7ed568ffc7c43.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/278b24f0f60525ed3aaab30dfc351c21.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/2e87c412a04f333a43c2d9e1beb6e75c.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/430a4f0991cd12d5ef3b05abb60d6c7b.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/58ef2fe13375765cb44d54bbcce77507.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/6a9c461a70873fd9bf7140a6dcdfc510.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/6c36ec57f6c9a5541727545d5d100044.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/73606fc49a2870773e97222c4657ec52.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/7885484f3d8cb3231d3794138f514e49.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/7937c4f5790b27f225974d35c5ce6b5a.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/7d77dbf9c06b7ff73937bac3a3b83c1b.jpg");
        // à découper :
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/10a391a3feec5d37bc4eb39622b02512.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/10fccd8c43d42992bc8d93a9eeadd087.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/134f7fc65de72adf463a7af4548fa7eb.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/195f954a0cc64a510432c2c1177e0c30.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/28a652d6ba8da5f75b0ec3d02ea39cbb.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/3602486f02a326920a57cfb81fb9b51f.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/6ab119db33a32f46cf0cf4f1f99a4d15.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/8360db4df800981718d151e9b5167af2.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/866b2bef506b7a7ff76f1bdb20a53795.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/8be9db52c847046ec1781dccf7bae260.jpg");
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
