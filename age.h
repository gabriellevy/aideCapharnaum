#ifndef AGE_H
#define AGE_H

#include <QString>
#include <QList>


class Age
{
public:
    Age(QString id);

    QString m_Tranche;
    int m_Age;

    static QList<QString> TRANCHES;

    static Age AgeAleatoire();
};

#endif // AGE_H
