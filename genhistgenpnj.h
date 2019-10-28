#ifndef GENHISTGENPNJ_H
#define GENHISTGENPNJ_H

#include "../destinLib/genhistoire.h"

class UniversCapharnaum;

class GenHistGenPnj : public GenHistoire
{
public:
    GenHistGenPnj();

    virtual Hist* GenererHistoire();

protected:
    virtual void GenererCaracs();
    virtual void GenererPersos();

private:
    void GenererEvtsAccueil();

    Effet* GenererEffetSelectionMetier(int index);
    Effet* GenererEffetSelectionPeuple(int index);
    Effet* GenererEffetSelectionNationEscarte(int index);
    Effet* GenererEffetSelectionAge();
    Effet* GenererEffetSelectionSexe(int index);

    // chaque lancement de cette fonction génère une suite d'effets qui généreront un personnage complet
    // si on clique "continuer" à la find 'un personnage on passe donc au suivant mais on sera limité par le nom total de lancement original de cette fonction
    // il ne serait pas sorcier de rendre ce lancement infini mais ça immplique de la génération un peu dynamique et j'ai la flemme
    void GenererBoucleGenerationPersonnage(int index);
};

#endif // GENHISTGENPNJ_H
