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
    if ( sexe == Sexe::SEXES[0])/* hommes*/ {
        // homme
        // tous les peuples
        if ( age > 20 ) {
            if (age < 50 ) {
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/c133738f676b3af58f7690c5f68fc655.jpg");
                if ( metier == Metier::CHASSEUR) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/c9d1d88a696586ca92506826257835ad.jpg");
                }
            }
        }

        if ( peuple == Peuple::ALFARIQN) { // Alfariqn
            if ( age > 12 ) {
                if ( age > 20 ) {
                    if (age < 60 ) {
                        if ( age < 35 ) {
                            if ( age < 25 ) {
                                ToutesLesImagesPossibles.push_back(":/images/Alfariqn/fd3760efaa50fe851bc5c7d5cd405c4a.jpg");
                            }
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/b932664d9bd81994b263e5825d4d93dc.jpg");
                        }
                        ToutesLesImagesPossibles.push_back(":/images/Alfariqn/0cc88d2d98926fbba4a7ed568ffc7c43.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Alfariqn/430a4f0991cd12d5ef3b05abb60d6c7b.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Alfariqn/58ef2fe13375765cb44d54bbcce77507.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Alfariqn/7885484f3d8cb3231d3794138f514e49.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Alfariqn/7937c4f5790b27f225974d35c5ce6b5a.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Alfariqn/c315e241f45ecc8341b276ac0f4da97f.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Alfariqn/ea0ae51882e088331a5e3c333b81b861.jpg");
                        if ( Metier::EstGuerrier(metier)) {
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/278b24f0f60525ed3aaab30dfc351c21.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/97c222051fbb6da3fa447edef2ff6778.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/e25a9700b77f11b6cd35b2b36502255c.jpg");
                        } else if ( metier == Metier::COURTISAN) {
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/2e87c412a04f333a43c2d9e1beb6e75c.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/6a9c461a70873fd9bf7140a6dcdfc510.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/73606fc49a2870773e97222c4657ec52.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/7d77dbf9c06b7ff73937bac3a3b83c1b.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/f8324d4bf7612d5c55c3e1fd0a8aca27.jpg");
                        } else if ( metier == Metier::PRETRE) {
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/6c36ec57f6c9a5541727545d5d100044.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Alfariqn/f745f6a28f537bac5ad371d392561b4c.jpg");
                        }
                    }
                }
            }
        }
        if ( peuple == Peuple::PEUPLES[0]) { // Saabi
            if ( metier == Metier::NOMADE) {
                if ( age < 25 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/8e0d0ef586c3edf951fcc1a51a024c43.jpg");
                }
            } else if ( Metier::EstGuerrier(metier)) {
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/f3e5769ecd9bb9717dcdfe0deaf72f31.jpg");
            }

            if ( age > 16) {
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/6e329b69b1b6de105cce57c87e25218c.jpg");
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/75aec4f5200c1255ac6287380a946a36.jpg");

                if ( Metier::EstGuerrier(metier)) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/6f4ca791bede07c98c8336ddf5af6162.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/74ea82a2ffc8bbb474c9cd8d50a01099.jpg");
                    if ( age < 40) {
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/61d573a7ebd905d8c4d748a942c68b0b.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/94cad1aae692c8a303d7242637b559d5.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/9958d889992ae887b292b2f955c24219.jpg");
                    }
                    if ( Metier::EstCavalier(metier)) {
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/c9e876999e7552a4c6079c9478c7795e.jpg");
                    }
                } else if ( metier == Metier::COURTISAN) {

                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/798a074e8cd00f5d61dd1b331228b51f.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/9b1cc7aff22a3375cc17480cbb8bc5fe.jpg");
                } else if ( metier == Metier::CHASSEUR ) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/c579641fd341d7ea737417a32676ad59.jpg");
                }
            }
        }

        if ( peuple == Peuple::PEUPLES[1]) // Shiradim
        {
            if (age > 55 ) {
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/6fe2457a0e47202be57fcfd3f72f554f.jpg");
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/78a2f1f90db5bd56f7dbabf9aedf63a3.jpg");
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/e394514a46b707d4e2d5e4c260376f2c.jpg");
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/f14e9cf58e49ca0c48b83e1ce1ba30f1.jpg");
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
            } else if ( metier == Metier::FORGERON) {
                if ( age > 20) {
                    if ( age < 60 ) {
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/adbaab0e4c4131be4232e3d4eeb31098.jpg");
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
                        if ( metier == Metier::MARCHAND) {
                            ToutesLesImagesPossibles.push_back(":/images/Saabi1/d3f40f2f4362c362935cd54534b836a5.jpg");
                        }
                    } else { // vieils hommes sabi / shiradim
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/00f4e226c847a2a36c83303dcd99920e.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/04b8bdb2cb6ac6bc988684358e48ae36.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/43ff44b67a58ab8e8e23f4607d5b4687.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/6bca6564370cf66e74414d2d4bc5c7c3.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/806d238a90f7c608213f1845e1fcee42.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/8f327ba74f9d78f1806c80ef34b402bc.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/b565287a42183c5347fe1cc0b5b802dc.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/ccb20ba618d03b2e0223040af7b446bd.jpg");
                        ToutesLesImagesPossibles.push_back(":/images/Saabi1/e8117f2f04c84c02155c8866925305b1.jpg");
                        if ( metier == Metier::MUSICIEN) {
                            ToutesLesImagesPossibles.push_back(":/images/Saabi1/bccb982b0e0280cfce8693824ba221fc.jpg");
                        } else if ( metier == Metier::COURTISAN) {
                            ToutesLesImagesPossibles.push_back(":/images/Saabi1/cc25c9bc0a393d46311bf7213ac774f1.jpg");
                        } else if ( metier == Metier::ERUDIT) {
                            ToutesLesImagesPossibles.push_back(":/images/Saabi1/d708d8d2cbc7daf7f4e399e39fe716f8.jpg");
                        } else if ( metier == Metier::MARCHAND) {
                            ToutesLesImagesPossibles.push_back(":/images/Saabi1/e67a67251441f8224f4c9a7a69a4645e.jpg");
                            ToutesLesImagesPossibles.push_back(":/images/Saabi1/f90332b00b26b5aa09594ec1a088914d.jpg");
                        }

                    }
                }
                if ( age < 55 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/3a727b713e68aec59c612f5760e5133a.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/ac395fd9393e738777ff0835fe1bafc5.jpg");
                }
            }
        }

    } else if (sexe == Sexe::SEXES[1])/* femmes*/ {
        // femmes
        // tous les peuples
        if ( age > 15) {
            ToutesLesImagesPossibles.push_back(":/images/Saabi1/9cf7370699c72eecbe18bd80a8d34725.jpg");
            if ( age < 40 ) {
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/bc8b9345061a628a80f2f8df86a817c7.jpg");
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/ce05271435ccac3e83e984682e55d4f1.jpg");
                ToutesLesImagesPossibles.push_back(":/images/Saabi1/f55b22471912bcf746d0767dc95af45d.jpg");
                if ( metier == Metier::COURTISAN) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/2389ecfa77c450d7b529473d3c6f62a4.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/6c0e7528d8626443dbe17dd0a34d9b3b.jpg");
                } else if (metier == Metier::ASSASSIN ) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/f91f78ac4b2dc8b451b56b1c763a54d4.jpg");
                }
            }
        } else {
            // petites filles
            ToutesLesImagesPossibles.push_back(":/images/Saabi1/67efe71502e501bb60c3da6cc29559e9.jpg");

        }
        if ( peuple == Peuple::PEUPLES[0] || peuple == Peuple::PEUPLES[1]) // Saabi ou Shiradim
        {
            if ( metier == Metier::MUSICIEN) {
                if ( age < 50 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/b9ea148adc06b739a1ec01c7d561158a.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/ff25cfb4b1ed4615aca8276efbdc8bab.jpg");
                }
            } else if ( metier == Metier::DANSEUR) {
                if ( age < 35 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/f4aa631dc92576174b797594599b2fcc.jpg");
                }
            }
            if ( age > 15) {
                if ( Metier::EstGuerrier(metier)) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/37495a30404751846515af3be96f4765.jpg");
                }
                if ( age > 25 ) {
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
        } else if ( peuple == Peuple::PEUPLES[3]) // Agalanthéenne
        {
            if ( age > 15) {
                if ( age < 40 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/23525f4be95ebb4a5bc128d001380ed3.jpg");
                    ToutesLesImagesPossibles.push_back(":/images/Saabi1/556dc4ce75f6c8cdfbdd1eb9b4d9944b.jpg");

                }
            }
        } else if ( peuple == Peuple::ALFARIQN) { // Alfariqn
            if ( age > 14 ) {
                if (age < 40 ) {
                    ToutesLesImagesPossibles.push_back(":/images/Alfariqn/ba95559eddf39af8000e8c85a24554d1.jpg");
                }
            }

        }
    }

    //ToutesLesImagesPossibles.push_back(":/images/Alfariqn/fd3760efaa50fe851bc5c7d5cd405c4a.jpg");

    if ( false) {
        // gardé pour plus tard
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
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/94a9edddd34edcecdeac33611702a21f.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/a998bb83a831301588a77e62cd95d022.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/aac88c70480ca0a50f83c02ef01ebea5.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/b13270e47bdacd407905b320faeb5105.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/ba77241a2766ee4980fd604e549261b3.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/c20dffeb26a423583bf8aed3358a991b.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/db92117d9c23e353768b18616d84a25e.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/e38a8a9a5678cbefde2a8195ef794a56.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/f87e681acca1afe7fb42c77c17d84b04.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/faed1f2cf308518875fcf020697833b3.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/fb427748876194449c11d3f61f2b654a.jpg");
        ToutesLesImagesPossibles.push_back(":/images/Saabi1/ffe8b0f1b7f5882fc8ff738b18a20dd5.jpg");
    }

    QString portrait = ToutesLesImagesPossibles[rand() % ToutesLesImagesPossibles.length()];

    Univers::ME->GetExecHistoire()->GetExecEffetActuel(false)->ChargerImage(portrait);
    Univers::ME->GetExecHistoire()->GetExecEffetActuel(false)->GetEffet()->m_Text += " " + portrait;
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
