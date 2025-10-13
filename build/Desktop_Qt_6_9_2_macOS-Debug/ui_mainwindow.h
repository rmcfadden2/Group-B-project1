/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *titleLabel;
    QLabel *CompanyLabel;
    QPushButton *adminButton;
    QPushButton *guestButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(170, 110, 481, 61));
        QFont font;
        font.setPointSize(25);
        titleLabel->setFont(font);
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        CompanyLabel = new QLabel(centralwidget);
        CompanyLabel->setObjectName("CompanyLabel");
        CompanyLabel->setGeometry(QRect(340, 470, 115, 16));
        CompanyLabel->setLayoutDirection(Qt::LayoutDirection::LeftToRight);
        CompanyLabel->setFrameShape(QFrame::Shape::NoFrame);
        adminButton = new QPushButton(centralwidget);
        adminButton->setObjectName("adminButton");
        adminButton->setGeometry(QRect(320, 270, 161, 41));
        adminButton->setAutoDefault(false);
        guestButton = new QPushButton(centralwidget);
        guestButton->setObjectName("guestButton");
        guestButton->setGeometry(QRect(320, 320, 161, 41));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(220, 190, 361, 20));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        adminButton->setDefault(true);
        guestButton->setDefault(true);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QString());
        titleLabel->setText(QCoreApplication::translate("MainWindow", "Apple Co. European Vacation Travel Planner", nullptr));
        CompanyLabel->setText(QCoreApplication::translate("MainWindow", "Apple Incorporated", nullptr));
        adminButton->setText(QCoreApplication::translate("MainWindow", "Login as Admin", nullptr));
        guestButton->setText(QCoreApplication::translate("MainWindow", "Continue as Guest", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Make your trip as crisp as an apple!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
