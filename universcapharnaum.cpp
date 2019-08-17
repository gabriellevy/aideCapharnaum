#include "universcapharnaum.h"
#include "ui_univers.h"
#include <QTime>
#include "genhistgenpnj.h"

UniversCapharnaum::UniversCapharnaum(ModeAffichage modeAffichage,
                                     QWidget *parent)
                : Univers(parent, modeAffichage)
{
    this->AppliquerTheme(QColor(240, 214, 113));

    QTime time = QTime::currentTime();
    qsrand(static_cast<uint>(time.msec()));
}

QString UniversCapharnaum::CARAC_METIER = "Métier";
QString UniversCapharnaum::CARAC_PARTICULARITES = "Particularités physiques";
QString UniversCapharnaum::CARAC_TAILLE = "Taille";
QString UniversCapharnaum::CARAC_PARTICUL_PSY = "Particularités psychologiques";
QString UniversCapharnaum::CARAC_SEXE = "Sexe";
QString UniversCapharnaum::CARAC_PEUPLE = "Peuple";
QString UniversCapharnaum::CARAC_SOUS_GROUPE = "SousGroupe";
QString UniversCapharnaum::CARAC_AGE = "Âge";

Hist* UniversCapharnaum::ExecuterGenerateurHistoire()
{
    // structure typoqie à copier dans votre fonction surclassée ExecuterGenerateurHistoire :
    m_Histoire = new Hist("titre inconu : vous devriez surclasser 'ExecuterGenerateurHistoire'");
    m_GenHistoire = new GenHistGenPnj(m_Histoire);
    m_GenHistoire->GenererHistoire();
    return m_Histoire;
}
