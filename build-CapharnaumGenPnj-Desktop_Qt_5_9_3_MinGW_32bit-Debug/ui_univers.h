/********************************************************************************
** Form generated from reading UI file 'univers.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNIVERS_H
#define UI_UNIVERS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Univers
{
public:
    QWidget *centralwidget;
    QWidget *Fond;
    QGridLayout *gridLayout_3;
    QWidget *persoWidget;
    QGridLayout *gridLayout_2;
    QWidget *histoireWidget;
    QVBoxLayout *verticalLayout_3;

    void setupUi(QMainWindow *Univers)
    {
        if (Univers->objectName().isEmpty())
            Univers->setObjectName(QStringLiteral("Univers"));
        Univers->resize(1280, 900);
        Univers->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(Univers);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        Fond = new QWidget(centralwidget);
        Fond->setObjectName(QStringLiteral("Fond"));
        Fond->setGeometry(QRect(0, 0, 1280, 900));
        sizePolicy.setHeightForWidth(Fond->sizePolicy().hasHeightForWidth());
        Fond->setSizePolicy(sizePolicy);
        gridLayout_3 = new QGridLayout(Fond);
        gridLayout_3->setSpacing(0);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        persoWidget = new QWidget(Fond);
        persoWidget->setObjectName(QStringLiteral("persoWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(persoWidget->sizePolicy().hasHeightForWidth());
        persoWidget->setSizePolicy(sizePolicy1);
        persoWidget->setMinimumSize(QSize(150, 900));
        persoWidget->setMaximumSize(QSize(250, 900));
        gridLayout_2 = new QGridLayout(persoWidget);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));

        gridLayout_3->addWidget(persoWidget, 0, 0, 1, 1);

        histoireWidget = new QWidget(Fond);
        histoireWidget->setObjectName(QStringLiteral("histoireWidget"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(histoireWidget->sizePolicy().hasHeightForWidth());
        histoireWidget->setSizePolicy(sizePolicy2);
        histoireWidget->setMinimumSize(QSize(500, 900));
        histoireWidget->setMaximumSize(QSize(1030, 900));
        histoireWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout_3 = new QVBoxLayout(histoireWidget);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);

        gridLayout_3->addWidget(histoireWidget, 0, 1, 1, 1);

        Univers->setCentralWidget(centralwidget);

        retranslateUi(Univers);

        QMetaObject::connectSlotsByName(Univers);
    } // setupUi

    void retranslateUi(QMainWindow *Univers)
    {
        Univers->setWindowTitle(QApplication::translate("Univers", "MainWindow", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Univers: public Ui_Univers {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNIVERS_H
