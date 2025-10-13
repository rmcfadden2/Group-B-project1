/********************************************************************************
** Form generated from reading UI file 'guestwcustom2.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUESTWCUSTOM2_H
#define UI_GUESTWCUSTOM2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guestWcustom2
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *citiesWidget;
    QPushButton *backButton;
    QPushButton *nextButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *guestWcustom2)
    {
        if (guestWcustom2->objectName().isEmpty())
            guestWcustom2->setObjectName("guestWcustom2");
        guestWcustom2->resize(800, 600);
        centralwidget = new QWidget(guestWcustom2);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(170, 100, 441, 311));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(verticalLayoutWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        citiesWidget = new QWidget();
        citiesWidget->setObjectName("citiesWidget");
        citiesWidget->setGeometry(QRect(0, 0, 437, 307));
        scrollArea->setWidget(citiesWidget);

        verticalLayout->addWidget(scrollArea);

        backButton = new QPushButton(centralwidget);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(40, 500, 100, 32));
        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName("nextButton");
        nextButton->setGeometry(QRect(650, 500, 100, 32));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(160, 50, 441, 41));
        QFont font;
        font.setPointSize(17);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        guestWcustom2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(guestWcustom2);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        guestWcustom2->setMenuBar(menubar);
        statusbar = new QStatusBar(guestWcustom2);
        statusbar->setObjectName("statusbar");
        guestWcustom2->setStatusBar(statusbar);

        retranslateUi(guestWcustom2);

        QMetaObject::connectSlotsByName(guestWcustom2);
    } // setupUi

    void retranslateUi(QMainWindow *guestWcustom2)
    {
        guestWcustom2->setWindowTitle(QString());
        backButton->setText(QCoreApplication::translate("guestWcustom2", "Back", nullptr));
        nextButton->setText(QCoreApplication::translate("guestWcustom2", "Next", nullptr));
        label->setText(QCoreApplication::translate("guestWcustom2", "Please select the cities you would like to go to", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guestWcustom2: public Ui_guestWcustom2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUESTWCUSTOM2_H
