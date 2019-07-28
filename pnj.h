#ifndef PNJ_H
#define PNJ_H

#include "../destinLib/perso.h"
#include "../destinLib/gestionnairecarac.h"


class UniversCapharnaum;

class Pnj : public DPerso
{

public:
    Pnj(QString id, QString nom, QString description, QString CheminImagePortrait);

    void InitialiserPerso();

    UniversCapharnaum* GetUniversCapharnaum();
};

#endif // PNJ_H
