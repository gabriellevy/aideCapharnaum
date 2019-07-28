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

Hist* UniversCapharnaum::ExecuterGenerateurHistoire()
{
    // structure typoqie à copier dans votre fonction surclassée ExecuterGenerateurHistoire :
    m_Histoire = new Hist("titre inconu : vous devriez surclasser 'ExecuterGenerateurHistoire'");
    m_GenHistoire = new GenHistGenPnj(m_Histoire);
    m_GenHistoire->GenererHistoire();
    return m_Histoire;
}
