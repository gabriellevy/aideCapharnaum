/********************************************************************************
** Form generated from reading UI file 'evt.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVT_H
#define UI_EVT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Evt
{
public:
    QVBoxLayout *verticalLayout_5;
    QWidget *EvtWidget;
    QVBoxLayout *verticalLayout_4;
    QLabel *titreEvt;
    QLabel *textEvt;
    QSpacerItem *verticalSpacer;
    QWidget *effetsWidget;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *Evt)
    {
        if (Evt->objectName().isEmpty())
            Evt->setObjectName(QStringLiteral("Evt"));
        Evt->resize(1030, 400);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Evt->sizePolicy().hasHeightForWidth());
        Evt->setSizePolicy(sizePolicy);
        Evt->setMaximumSize(QSize(1030, 900));
        verticalLayout_5 = new QVBoxLayout(Evt);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        EvtWidget = new QWidget(Evt);
        EvtWidget->setObjectName(QStringLiteral("EvtWidget"));
        sizePolicy.setHeightForWidth(EvtWidget->sizePolicy().hasHeightForWidth());
        EvtWidget->setSizePolicy(sizePolicy);
        EvtWidget->setMinimumSize(QSize(0, 0));
        EvtWidget->setMaximumSize(QSize(1030, 900));
        EvtWidget->setStyleSheet(QStringLiteral("background-color: rgba(0,0,0,0)"));
        verticalLayout_4 = new QVBoxLayout(EvtWidget);
        verticalLayout_4->setSpacing(0);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        titreEvt = new QLabel(EvtWidget);
        titreEvt->setObjectName(QStringLiteral("titreEvt"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(titreEvt->sizePolicy().hasHeightForWidth());
        titreEvt->setSizePolicy(sizePolicy1);
        titreEvt->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_4->addWidget(titreEvt);

        textEvt = new QLabel(EvtWidget);
        textEvt->setObjectName(QStringLiteral("textEvt"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(textEvt->sizePolicy().hasHeightForWidth());
        textEvt->setSizePolicy(sizePolicy2);

        verticalLayout_4->addWidget(textEvt);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_4->addItem(verticalSpacer);

        effetsWidget = new QWidget(EvtWidget);
        effetsWidget->setObjectName(QStringLiteral("effetsWidget"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(effetsWidget->sizePolicy().hasHeightForWidth());
        effetsWidget->setSizePolicy(sizePolicy3);
        effetsWidget->setMaximumSize(QSize(1030, 800));
        verticalLayout_2 = new QVBoxLayout(effetsWidget);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);

        verticalLayout_4->addWidget(effetsWidget);


        verticalLayout_5->addWidget(EvtWidget);


        retranslateUi(Evt);

        QMetaObject::connectSlotsByName(Evt);
    } // setupUi

    void retranslateUi(QWidget *Evt)
    {
        Evt->setWindowTitle(QApplication::translate("Evt", "Form", Q_NULLPTR));
        titreEvt->setText(QApplication::translate("Evt", "Titre Evt", Q_NULLPTR));
        textEvt->setText(QApplication::translate("Evt", "Texte \303\251v\303\251nement", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Evt: public Ui_Evt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVT_H
