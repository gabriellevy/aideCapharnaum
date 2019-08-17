#ifndef PEUPLE_H
#define PEUPLE_H

#include <QString>
#include <QList>


class Peuple
{
public:
    Peuple(QString id, QString sousGroupe = "");

    QString m_Peuple;
    QString m_SousGroupe = "";
    QString m_LieuOrigine;

    static QList<QString> PEUPLES;
    static QList<QString> SOUS_GROUPE_ESCARTE;


    static Peuple AleatoireCapharnaum();
    static Peuple AleatoireSudJazirat();

    static Peuple AleatoireEscarte();

    static QString ALFARIQN;
    static QString SAABI;
    static QString AGALANTHEEN;
    static QString SHIRADIM;
    static QString ESCARTE;
    static QString OCCIDENTIN;
    static QString DORKADE;
    static QString ARAGON;

    /**
     * @brief GenererNom
     * @param peuple
     * @param sexe
     * @param sousensemble : si le peuple a des sous-ensembles comme des nations internes ou des clans, les jouter ici
     * @return
     */
    static QString GenererNom(QString peuple, QString sexe, QString sousensemble = "");
    static QVector<QString> NOMS_SAABI;
    static QVector<QString> PRENOMS_SAABI_MALES;
    static QVector<QString> PRENOMS_SAABI_FEMELLES;

    static QVector<QString> PRENOMS_SHIRADIM_MALES;
    static QVector<QString> PRENOMS_SHIRADIM_FEMELLES;

    static QVector<QString> NOMS_ARAGON;
    static QVector<QString> NOMS_DORKADE;
    static QVector<QString> NOMS_OCCIDENTIN;
    static QVector<QString> PRENOMS_OCCIDENTIN_MALES;
    static QVector<QString> PRENOMS_OCCIDENTIN_FEMELLES;
    static QVector<QString> PRENOMS_ARAGON_MALES;
    static QVector<QString> PRENOMS_ARAGON_FEMELLES;
    static QVector<QString> PRENOMS_DORKADE_MALES;
    static QVector<QString> PRENOMS_DORKADE_FEMELLES;
};

#endif // PEUPLE_H
