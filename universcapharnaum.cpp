#include "universcapharnaum.h"
#include "ui_univers.h"
#include "genhistgenpnj.h"

QString UniversCapharnaum::CARAC_METIER = "Métier";
QString UniversCapharnaum::CARAC_PARTICULARITES = "Particularités physiques";
QString UniversCapharnaum::CARAC_TAILLE = "Taille";
QString UniversCapharnaum::CARAC_PARTICUL_PSY = "Particularités psychologiques";
QString UniversCapharnaum::CARAC_SEXE = "Sexe";
QString UniversCapharnaum::CARAC_PEUPLE = "Peuple";
QString UniversCapharnaum::CARAC_SOUS_GROUPE = "SousGroupe";
QString UniversCapharnaum::CARAC_AGE = "Âge";

QString UniversCapharnaum::GEN_PNJ = "GenPng";


UniversCapharnaum::UniversCapharnaum(ModeAffichage modeAffichage,
                                     QWidget *parent)
                : Univers(parent, modeAffichage)
{
    this->AppliquerTheme(QColor(240, 214, 113));

    m_GensHistoire[UniversCapharnaum::GEN_PNJ] = new GenHistGenPnj();
}
