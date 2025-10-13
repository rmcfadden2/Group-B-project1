/********************************************************************************
** Form generated from reading UI file 'guestmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUESTMAINWINDOW_H
#define UI_GUESTMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guestMainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *plannedButton;
    QPushButton *customButton;
    QPushButton *backButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *guestMainWindow)
    {
        if (guestMainWindow->objectName().isEmpty())
            guestMainWindow->setObjectName("guestMainWindow");
        guestMainWindow->resize(800, 600);
        centralwidget = new QWidget(guestMainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 150, 531, 71));
        QFont font;
        font.setPointSize(26);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        plannedButton = new QPushButton(centralwidget);
        plannedButton->setObjectName("plannedButton");
        plannedButton->setGeometry(QRect(210, 220, 321, 32));
        customButton = new QPushButton(centralwidget);
        customButton->setObjectName("customButton");
        customButton->setGeometry(QRect(210, 260, 321, 32));
        backButton = new QPushButton(centralwidget);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(30, 500, 100, 32));
        guestMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(guestMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        guestMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(guestMainWindow);
        statusbar->setObjectName("statusbar");
        guestMainWindow->setStatusBar(statusbar);

        retranslateUi(guestMainWindow);

        QMetaObject::connectSlotsByName(guestMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *guestMainWindow)
    {
        guestMainWindow->setWindowTitle(QString());
        label->setText(QCoreApplication::translate("guestMainWindow", "How would you like to plan your trip?", nullptr));
        plannedButton->setText(QCoreApplication::translate("guestMainWindow", "Let us do most of the work?", nullptr));
        customButton->setText(QCoreApplication::translate("guestMainWindow", "Do it yourself?", nullptr));
        backButton->setText(QCoreApplication::translate("guestMainWindow", "Back", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guestMainWindow: public Ui_guestMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUESTMAINWINDOW_H
