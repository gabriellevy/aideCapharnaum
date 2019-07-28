/********************************************************************************
** Form generated from reading UI file 'choix.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOIX_H
#define UI_CHOIX_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Choix
{
public:
    QHBoxLayout *horizontalLayout;
    QPushButton *bouton;

    void setupUi(QWidget *Choix)
    {
        if (Choix->objectName().isEmpty())
            Choix->setObjectName(QStringLiteral("Choix"));
        Choix->resize(411, 53);
        Choix->setStyleSheet(QStringLiteral("background-color : rgba(0,0,0,0)"));
        horizontalLayout = new QHBoxLayout(Choix);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        bouton = new QPushButton(Choix);
        bouton->setObjectName(QStringLiteral("bouton"));

        horizontalLayout->addWidget(bouton);


        retranslateUi(Choix);

        QMetaObject::connectSlotsByName(Choix);
    } // setupUi

    void retranslateUi(QWidget *Choix)
    {
        Choix->setWindowTitle(QApplication::translate("Choix", "Form", Q_NULLPTR));
        bouton->setText(QApplication::translate("Choix", "PushButton", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Choix: public Ui_Choix {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOIX_H
