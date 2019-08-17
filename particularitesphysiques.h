#ifndef PARTICULARITESPHYSIQUES_H
#define PARTICULARITESPHYSIQUES_H

#include <QString>
#include <QList>


class ParticularitesPhysiques
{
public:
    ParticularitesPhysiques();
    QList<QString> m_Particularites;
    QString ToQString();

    static QList<QString> PARTICULARITES;
};

#endif // PARTICULARITESPHYSIQUES_H
