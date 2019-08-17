#ifndef PARTICULARITESPSY_H
#define PARTICULARITESPSY_H

#include <QString>
#include <QList>

class ParticularitesPsy
{
public:
    ParticularitesPsy();
    QList<QString> m_Particularites;
    QString ToQString();

    static QList<QString> PARTICULARITES;
};

#endif // PARTICULARITESPSY_H
