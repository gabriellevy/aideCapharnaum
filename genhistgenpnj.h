#ifndef GENHISTGENPNJ_H
#define GENHISTGENPNJ_H

#include "../destinLib/genhistoire.h"

class UniversCapharnaum;

class GenHistGenPnj : public GenHistoire
{
public:
    GenHistGenPnj(Hist* histoireGeneree);

    virtual Hist* GenererHistoire();

protected:
    // génère toutes les caracs qui peuvent être visualisées par le joueur (d'autres caracs peuvent être générées et invisibles n'importe quand dans l'aventure)
    virtual void GenererCaracs();
    virtual void GenererPersos();

    Effet* GenererEffetSelectionMetier();
    Effet* GenererEffetSelectionPeuple();
    Effet* GenererEffetSelectionNationEscarte();
    Effet* GenererEffetSelectionAge();
    Effet* GenererEffetSelectionSexe();

    //Effet* GenererEffetSelectionMetier();
private:
    void GenererEvtsAccueil();
};

#endif // GENHISTGENPNJ_H
