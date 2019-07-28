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

private:

};

#endif // GENPNJFENETRE_H
