/********************************************************************************
** Form generated from reading UI file 'noeud.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NOEUD_H
#define UI_NOEUD_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Noeud
{
public:

    void setupUi(QWidget *Noeud)
    {
        if (Noeud->objectName().isEmpty())
            Noeud->setObjectName(QStringLiteral("Noeud"));
        Noeud->resize(50, 50);

        retranslateUi(Noeud);

        QMetaObject::connectSlotsByName(Noeud);
    } // setupUi

    void retranslateUi(QWidget *Noeud)
    {
        Noeud->setWindowTitle(QApplication::translate("Noeud", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Noeud: public Ui_Noeud {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NOEUD_H
