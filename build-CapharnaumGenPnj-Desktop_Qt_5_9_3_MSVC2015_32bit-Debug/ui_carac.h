/********************************************************************************
** Form generated from reading UI file 'carac.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARAC_H
#define UI_CARAC_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "aspectratiolabel.h"

QT_BEGIN_NAMESPACE

class Ui_Carac
{
public:
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *caracBox;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_3;
    AspectRatioLabel *imageCarac;
    QVBoxLayout *verticalLayout;
    QLabel *labelValeur;
    QProgressBar *jaugeCarac;

    void setupUi(QWidget *Carac)
    {
        if (Carac->objectName().isEmpty())
            Carac->setObjectName(QStringLiteral("Carac"));
        Carac->resize(250, 93);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Carac->sizePolicy().hasHeightForWidth());
        Carac->setSizePolicy(sizePolicy);
        Carac->setStyleSheet(QStringLiteral("background-color : rgba(211, 215, 207,180)"));
        horizontalLayout = new QHBoxLayout(Carac);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        caracBox = new QGroupBox(Carac);
        caracBox->setObjectName(QStringLiteral("caracBox"));
        caracBox->setAutoFillBackground(false);
        caracBox->setCheckable(false);
        horizontalLayout_4 = new QHBoxLayout(caracBox);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        imageCarac = new AspectRatioLabel(caracBox);
        imageCarac->setObjectName(QStringLiteral("imageCarac"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(imageCarac->sizePolicy().hasHeightForWidth());
        imageCarac->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(imageCarac);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelValeur = new QLabel(caracBox);
        labelValeur->setObjectName(QStringLiteral("labelValeur"));

        verticalLayout->addWidget(labelValeur);

        jaugeCarac = new QProgressBar(caracBox);
        jaugeCarac->setObjectName(QStringLiteral("jaugeCarac"));
        jaugeCarac->setEnabled(true);
        jaugeCarac->setMaximum(100);
        jaugeCarac->setValue(-1);
        jaugeCarac->setTextVisible(false);

        verticalLayout->addWidget(jaugeCarac);


        horizontalLayout_3->addLayout(verticalLayout);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        horizontalLayout_2->addWidget(caracBox);


        horizontalLayout->addLayout(horizontalLayout_2);


        retranslateUi(Carac);

        QMetaObject::connectSlotsByName(Carac);
    } // setupUi

    void retranslateUi(QWidget *Carac)
    {
        Carac->setWindowTitle(QApplication::translate("Carac", "Form", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        caracBox->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        caracBox->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        imageCarac->setToolTip(QApplication::translate("Carac", "youpi je suis une tooltip !!", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        imageCarac->setText(QString());
        labelValeur->setText(QString());
        jaugeCarac->setFormat(QApplication::translate("Carac", "%p", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Carac: public Ui_Carac {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARAC_H
