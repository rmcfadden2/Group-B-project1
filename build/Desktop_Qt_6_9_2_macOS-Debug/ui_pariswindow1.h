/********************************************************************************
** Form generated from reading UI file 'pariswindow1.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PARISWINDOW1_H
#define UI_PARISWINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_parisWindow1
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *summaryContainer;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *totalDistLabel;
    QPushButton *restartButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *parisWindow1)
    {
        if (parisWindow1->objectName().isEmpty())
            parisWindow1->setObjectName("parisWindow1");
        parisWindow1->resize(800, 600);
        centralwidget = new QWidget(parisWindow1);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(157, 40, 411, 20));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(139, 89, 481, 321));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        summaryContainer = new QWidget(verticalLayoutWidget);
        summaryContainer->setObjectName("summaryContainer");

        verticalLayout->addWidget(summaryContainer);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(229, 450, 271, 41));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout->addWidget(label_2);

        totalDistLabel = new QLabel(horizontalLayoutWidget);
        totalDistLabel->setObjectName("totalDistLabel");

        horizontalLayout->addWidget(totalDistLabel);

        restartButton = new QPushButton(centralwidget);
        restartButton->setObjectName("restartButton");
        restartButton->setGeometry(QRect(640, 500, 100, 32));
        parisWindow1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(parisWindow1);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        parisWindow1->setMenuBar(menubar);
        statusbar = new QStatusBar(parisWindow1);
        statusbar->setObjectName("statusbar");
        parisWindow1->setStatusBar(statusbar);

        retranslateUi(parisWindow1);

        QMetaObject::connectSlotsByName(parisWindow1);
    } // setupUi

    void retranslateUi(QMainWindow *parisWindow1)
    {
        parisWindow1->setWindowTitle(QString());
        label->setText(QCoreApplication::translate("parisWindow1", "Trip Summary", nullptr));
        label_2->setText(QCoreApplication::translate("parisWindow1", "Total distance Travelled: ", nullptr));
        totalDistLabel->setText(QString());
        restartButton->setText(QCoreApplication::translate("parisWindow1", "Restart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class parisWindow1: public Ui_parisWindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PARISWINDOW1_H
