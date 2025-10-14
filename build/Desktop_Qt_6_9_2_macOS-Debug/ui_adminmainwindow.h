/********************************************************************************
** Form generated from reading UI file 'adminmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINMAINWINDOW_H
#define UI_ADMINMAINWINDOW_H

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

class Ui_adminMainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QPushButton *citiesButton;
    QPushButton *foodButton;
    QPushButton *logoutButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *adminMainWindow)
    {
        if (adminMainWindow->objectName().isEmpty())
            adminMainWindow->setObjectName("adminMainWindow");
        adminMainWindow->resize(800, 600);
        centralwidget = new QWidget(adminMainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(207, 75, 341, 51));
        QFont font;
        font.setPointSize(27);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(230, 150, 301, 181));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        citiesButton = new QPushButton(verticalLayoutWidget);
        citiesButton->setObjectName("citiesButton");

        verticalLayout->addWidget(citiesButton);

        foodButton = new QPushButton(verticalLayoutWidget);
        foodButton->setObjectName("foodButton");

        verticalLayout->addWidget(foodButton);

        logoutButton = new QPushButton(verticalLayoutWidget);
        logoutButton->setObjectName("logoutButton");

        verticalLayout->addWidget(logoutButton);

        adminMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(adminMainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        adminMainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(adminMainWindow);
        statusbar->setObjectName("statusbar");
        adminMainWindow->setStatusBar(statusbar);

        retranslateUi(adminMainWindow);

        QMetaObject::connectSlotsByName(adminMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *adminMainWindow)
    {
        adminMainWindow->setWindowTitle(QString());
        label->setText(QCoreApplication::translate("adminMainWindow", "Admin View", nullptr));
        citiesButton->setText(QCoreApplication::translate("adminMainWindow", "Add/Delete Cities", nullptr));
        foodButton->setText(QCoreApplication::translate("adminMainWindow", "Maintain Food Database", nullptr));
        logoutButton->setText(QCoreApplication::translate("adminMainWindow", "Logout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class adminMainWindow: public Ui_adminMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINMAINWINDOW_H
