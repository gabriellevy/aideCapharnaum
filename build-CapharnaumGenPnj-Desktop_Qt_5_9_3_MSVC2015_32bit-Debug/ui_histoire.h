/********************************************************************************
** Form generated from reading UI file 'histoire.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HISTOIRE_H
#define UI_HISTOIRE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Histoire
{
public:
    QWidget *histoireLayout;
    QVBoxLayout *verticalLayout;
    QScrollArea *histoireScrollArea;
    QWidget *scrollAreaWidgetContents;

    void setupUi(QWidget *Histoire)
    {
        if (Histoire->objectName().isEmpty())
            Histoire->setObjectName(QStringLiteral("Histoire"));
        Histoire->resize(1030, 900);
        Histoire->setMaximumSize(QSize(1030, 900));
        Histoire->setStyleSheet(QStringLiteral("background-color : rgba(0,0,0,0)"));
        histoireLayout = new QWidget(Histoire);
        histoireLayout->setObjectName(QStringLiteral("histoireLayout"));
        histoireLayout->setGeometry(QRect(0, 0, 1030, 900));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(histoireLayout->sizePolicy().hasHeightForWidth());
        histoireLayout->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(histoireLayout);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        histoireScrollArea = new QScrollArea(histoireLayout);
        histoireScrollArea->setObjectName(QStringLiteral("histoireScrollArea"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(histoireScrollArea->sizePolicy().hasHeightForWidth());
        histoireScrollArea->setSizePolicy(sizePolicy1);
        histoireScrollArea->setMaximumSize(QSize(1030, 900));
        histoireScrollArea->setFrameShape(QFrame::NoFrame);
        histoireScrollArea->setFrameShadow(QFrame::Plain);
        histoireScrollArea->setLineWidth(0);
        histoireScrollArea->setWidgetResizable(true);
        histoireScrollArea->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1030, 900));
        scrollAreaWidgetContents->setMaximumSize(QSize(1030, 900));
        histoireScrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(histoireScrollArea);


        retranslateUi(Histoire);

        QMetaObject::connectSlotsByName(Histoire);
    } // setupUi

    void retranslateUi(QWidget *Histoire)
    {
        Histoire->setWindowTitle(QApplication::translate("Histoire", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Histoire: public Ui_Histoire {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HISTOIRE_H
