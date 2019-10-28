#ifndef GENPNJFENETRE_H
#define GENPNJFENETRE_H

#include "../destinLib/univers.h"
#include <QMainWindow>

class UniversCapharnaum : public Univers
{
    Q_OBJECT

public:
    UniversCapharnaum(ModeAffichage modeAffichage = ModeAffichage::ema_Jeu,
                QWidget *parent = nullptr);

    Hist* ExecuterGenerateurHistoire();

    static QString GEN_PNJ;

    // capacités de persos
    static QString CARAC_METIER;
    static QString CARAC_PARTICULARITES;
    static QString CARAC_TAILLE;
    static QString CARAC_PARTICUL_PSY;
    static QString CARAC_SEXE;
    static QString CARAC_PEUPLE;
    static QString CARAC_SOUS_GROUPE;
    static QString CARAC_AGE;

private:

};

#endif // GENPNJFENETRE_H
