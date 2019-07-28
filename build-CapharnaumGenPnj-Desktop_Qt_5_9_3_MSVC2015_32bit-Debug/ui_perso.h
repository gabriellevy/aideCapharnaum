/********************************************************************************
** Form generated from reading UI file 'perso.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PERSO_H
#define UI_PERSO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "aspectratiolabel.h"

QT_BEGIN_NAMESPACE

class Ui_Perso
{
public:
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayoutPerso;
    QWidget *portraitWidget;
    QVBoxLayout *portraitLayout;
    AspectRatioLabel *imagePortrait;
    QLabel *portraitLabel;
    QWidget *caracsLayout;
    QVBoxLayout *caracsLayout2;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *Perso)
    {
        if (Perso->objectName().isEmpty())
            Perso->setObjectName(QStringLiteral("Perso"));
        Perso->resize(250, 900);
        verticalLayout_3 = new QVBoxLayout(Perso);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayoutPerso = new QVBoxLayout();
        verticalLayoutPerso->setObjectName(QStringLiteral("verticalLayoutPerso"));
        portraitWidget = new QWidget(Perso);
        portraitWidget->setObjectName(QStringLiteral("portraitWidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(portraitWidget->sizePolicy().hasHeightForWidth());
        portraitWidget->setSizePolicy(sizePolicy);
        portraitWidget->setMaximumSize(QSize(250, 250));
        portraitWidget->setLayoutDirection(Qt::LeftToRight);
        portraitLayout = new QVBoxLayout(portraitWidget);
        portraitLayout->setObjectName(QStringLiteral("portraitLayout"));
        imagePortrait = new AspectRatioLabel(portraitWidget);
        imagePortrait->setObjectName(QStringLiteral("imagePortrait"));
        imagePortrait->setMaximumSize(QSize(250, 200));
        imagePortrait->setAlignment(Qt::AlignCenter);

        portraitLayout->addWidget(imagePortrait);

        portraitLabel = new QLabel(portraitWidget);
        portraitLabel->setObjectName(QStringLiteral("portraitLabel"));
        portraitLabel->setMinimumSize(QSize(0, 0));
        portraitLabel->setMaximumSize(QSize(250, 40));
        QFont font;
        font.setFamily(QStringLiteral("Yu Gothic Medium"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        portraitLabel->setFont(font);
        portraitLabel->setStyleSheet(QStringLiteral("background-color : rgbargb(255, 255, 255, 200)"));
        portraitLabel->setAlignment(Qt::AlignCenter);

        portraitLayout->addWidget(portraitLabel);


        verticalLayoutPerso->addWidget(portraitWidget);

        caracsLayout = new QWidget(Perso);
        caracsLayout->setObjectName(QStringLiteral("caracsLayout"));
        caracsLayout2 = new QVBoxLayout(caracsLayout);
        caracsLayout2->setObjectName(QStringLiteral("caracsLayout2"));
        caracsLayout2->setContentsMargins(0, 0, 0, 0);

        verticalLayoutPerso->addWidget(caracsLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutPerso->addItem(verticalSpacer);


        verticalLayout_3->addLayout(verticalLayoutPerso);


        retranslateUi(Perso);

        QMetaObject::connectSlotsByName(Perso);
    } // setupUi

    void retranslateUi(QWidget *Perso)
    {
        Perso->setWindowTitle(QApplication::translate("Perso", "Form", Q_NULLPTR));
        imagePortrait->setText(QString());
        portraitLabel->setText(QApplication::translate("Perso", "Nom du h\303\251ros", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Perso: public Ui_Perso {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PERSO_H
