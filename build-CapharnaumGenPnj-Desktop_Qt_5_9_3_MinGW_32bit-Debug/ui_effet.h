/********************************************************************************
** Form generated from reading UI file 'effet.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EFFET_H
#define UI_EFFET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "aspectratiolabel.h"

QT_BEGIN_NAMESPACE

class Ui_Effet
{
public:
    QVBoxLayout *verticalLayout_2;
    QLabel *titreEffet;
    QHBoxLayout *horizontalLayout;
    AspectRatioLabel *imageLabel;
    QLabel *texteEffet;
    QWidget *layoutBoutons;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *glisseur_layout;
    QLabel *labelGlisseur;
    QSlider *glisseur;
    QPushButton *boutonContinuer;
    QHBoxLayout *horizontalLayoutBoutons;

    void setupUi(QWidget *Effet)
    {
        if (Effet->objectName().isEmpty())
            Effet->setObjectName(QStringLiteral("Effet"));
        Effet->resize(925, 187);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Effet->sizePolicy().hasHeightForWidth());
        Effet->setSizePolicy(sizePolicy);
        Effet->setStyleSheet(QStringLiteral("background-color : rgbargb(238, 238, 236, 200)"));
        verticalLayout_2 = new QVBoxLayout(Effet);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        titreEffet = new QLabel(Effet);
        titreEffet->setObjectName(QStringLiteral("titreEffet"));

        verticalLayout_2->addWidget(titreEffet);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        imageLabel = new AspectRatioLabel(Effet);
        imageLabel->setObjectName(QStringLiteral("imageLabel"));

        horizontalLayout->addWidget(imageLabel);

        texteEffet = new QLabel(Effet);
        texteEffet->setObjectName(QStringLiteral("texteEffet"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(texteEffet->sizePolicy().hasHeightForWidth());
        texteEffet->setSizePolicy(sizePolicy1);
        texteEffet->setFrameShape(QFrame::Panel);
        texteEffet->setFrameShadow(QFrame::Plain);
        texteEffet->setLineWidth(0);
        texteEffet->setWordWrap(true);
        texteEffet->setMargin(15);
        texteEffet->setIndent(5);

        horizontalLayout->addWidget(texteEffet);


        verticalLayout_2->addLayout(horizontalLayout);

        layoutBoutons = new QWidget(Effet);
        layoutBoutons->setObjectName(QStringLiteral("layoutBoutons"));
        sizePolicy.setHeightForWidth(layoutBoutons->sizePolicy().hasHeightForWidth());
        layoutBoutons->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(layoutBoutons);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        glisseur_layout = new QHBoxLayout();
        glisseur_layout->setObjectName(QStringLiteral("glisseur_layout"));
        labelGlisseur = new QLabel(layoutBoutons);
        labelGlisseur->setObjectName(QStringLiteral("labelGlisseur"));

        glisseur_layout->addWidget(labelGlisseur);

        glisseur = new QSlider(layoutBoutons);
        glisseur->setObjectName(QStringLiteral("glisseur"));
        glisseur->setSliderPosition(50);
        glisseur->setOrientation(Qt::Horizontal);
        glisseur->setTickPosition(QSlider::NoTicks);

        glisseur_layout->addWidget(glisseur);


        verticalLayout->addLayout(glisseur_layout);

        boutonContinuer = new QPushButton(layoutBoutons);
        boutonContinuer->setObjectName(QStringLiteral("boutonContinuer"));

        verticalLayout->addWidget(boutonContinuer);


        verticalLayout_2->addWidget(layoutBoutons);

        horizontalLayoutBoutons = new QHBoxLayout();
        horizontalLayoutBoutons->setObjectName(QStringLiteral("horizontalLayoutBoutons"));

        verticalLayout_2->addLayout(horizontalLayoutBoutons);


        retranslateUi(Effet);
        QObject::connect(glisseur, SIGNAL(valueChanged(int)), labelGlisseur, SLOT(setNum(int)));

        QMetaObject::connectSlotsByName(Effet);
    } // setupUi

    void retranslateUi(QWidget *Effet)
    {
        Effet->setWindowTitle(QApplication::translate("Effet", "Form", Q_NULLPTR));
        titreEffet->setText(QApplication::translate("Effet", "Titre effet", Q_NULLPTR));
        imageLabel->setText(QString());
        texteEffet->setText(QApplication::translate("Effet", "Texte effet", Q_NULLPTR));
        labelGlisseur->setText(QApplication::translate("Effet", "Libell\303\251", Q_NULLPTR));
        boutonContinuer->setText(QApplication::translate("Effet", "Continuer", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Effet: public Ui_Effet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EFFET_H
