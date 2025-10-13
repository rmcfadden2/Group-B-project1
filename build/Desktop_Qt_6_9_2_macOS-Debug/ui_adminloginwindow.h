/********************************************************************************
** Form generated from reading UI file 'adminloginwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINLOGINWINDOW_H
#define UI_ADMINLOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_adminLoginWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *usernameLabel;
    QLineEdit *usernameEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *passwordLabel;
    QLineEdit *passwordEdit;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *cancelButton;
    QPushButton *clearButton;
    QPushButton *loginButton;
    QLabel *warningLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *adminLoginWindow)
    {
        if (adminLoginWindow->objectName().isEmpty())
            adminLoginWindow->setObjectName("adminLoginWindow");
        adminLoginWindow->resize(800, 600);
        centralwidget = new QWidget(adminLoginWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(170, 140, 421, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        usernameLabel = new QLabel(verticalLayoutWidget);
        usernameLabel->setObjectName("usernameLabel");

        horizontalLayout->addWidget(usernameLabel);

        usernameEdit = new QLineEdit(verticalLayoutWidget);
        usernameEdit->setObjectName("usernameEdit");

        horizontalLayout->addWidget(usernameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        passwordLabel = new QLabel(verticalLayoutWidget);
        passwordLabel->setObjectName("passwordLabel");

        horizontalLayout_2->addWidget(passwordLabel);

        passwordEdit = new QLineEdit(verticalLayoutWidget);
        passwordEdit->setObjectName("passwordEdit");
        passwordEdit->setEchoMode(QLineEdit::EchoMode::Password);

        horizontalLayout_2->addWidget(passwordEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        cancelButton = new QPushButton(verticalLayoutWidget);
        cancelButton->setObjectName("cancelButton");

        horizontalLayout_3->addWidget(cancelButton);

        clearButton = new QPushButton(verticalLayoutWidget);
        clearButton->setObjectName("clearButton");

        horizontalLayout_3->addWidget(clearButton);

        loginButton = new QPushButton(verticalLayoutWidget);
        loginButton->setObjectName("loginButton");

        horizontalLayout_3->addWidget(loginButton);


        verticalLayout->addLayout(horizontalLayout_3);

        warningLabel = new QLabel(verticalLayoutWidget);
        warningLabel->setObjectName("warningLabel");
        warningLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(warningLabel);

        adminLoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(adminLoginWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        adminLoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(adminLoginWindow);
        statusbar->setObjectName("statusbar");
        adminLoginWindow->setStatusBar(statusbar);

        retranslateUi(adminLoginWindow);

        QMetaObject::connectSlotsByName(adminLoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *adminLoginWindow)
    {
        adminLoginWindow->setWindowTitle(QString());
        usernameLabel->setText(QCoreApplication::translate("adminLoginWindow", "Username:", nullptr));
        passwordLabel->setText(QCoreApplication::translate("adminLoginWindow", "Password:", nullptr));
        cancelButton->setText(QCoreApplication::translate("adminLoginWindow", "Cancel", nullptr));
        clearButton->setText(QCoreApplication::translate("adminLoginWindow", "Clear", nullptr));
        loginButton->setText(QCoreApplication::translate("adminLoginWindow", "Login", nullptr));
        warningLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class adminLoginWindow: public Ui_adminLoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINLOGINWINDOW_H
