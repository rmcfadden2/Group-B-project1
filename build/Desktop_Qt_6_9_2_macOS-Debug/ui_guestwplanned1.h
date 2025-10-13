/********************************************************************************
** Form generated from reading UI file 'guestwplanned1.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUESTWPLANNED1_H
#define UI_GUESTWPLANNED1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guestWplanned1
{
public:
    QWidget *centralwidget;
    QPushButton *backButton;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *parisButton;
    QPushButton *londonButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *guestWplanned1)
    {
        if (guestWplanned1->objectName().isEmpty())
            guestWplanned1->setObjectName("guestWplanned1");
        guestWplanned1->resize(800, 600);
        centralwidget = new QWidget(guestWplanned1);
        centralwidget->setObjectName("centralwidget");
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(40, 490, 100, 32));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(170, 140, 421, 241));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(25);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(label);

        parisButton = new QPushButton(verticalLayoutWidget);
        parisButton->setObjectName("parisButton");

        verticalLayout->addWidget(parisButton);

        londonButton = new QPushButton(verticalLayoutWidget);
        londonButton->setObjectName("londonButton");

        verticalLayout->addWidget(londonButton);

        guestWplanned1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(guestWplanned1);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        guestWplanned1->setMenuBar(menubar);
        statusbar = new QStatusBar(guestWplanned1);
        statusbar->setObjectName("statusbar");
        guestWplanned1->setStatusBar(statusbar);

        retranslateUi(guestWplanned1);

        QMetaObject::connectSlotsByName(guestWplanned1);
    } // setupUi

    void retranslateUi(QMainWindow *guestWplanned1)
    {
        guestWplanned1->setWindowTitle(QString());
        backButton->setText(QCoreApplication::translate("guestWplanned1", "Back", nullptr));
        label->setText(QCoreApplication::translate("guestWplanned1", "Pick an option", nullptr));
        parisButton->setText(QCoreApplication::translate("guestWplanned1", "Visit initial 11 cities starting at Paris", nullptr));
        londonButton->setText(QCoreApplication::translate("guestWplanned1", "Shortest Trip Starting From London", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guestWplanned1: public Ui_guestWplanned1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUESTWPLANNED1_H
