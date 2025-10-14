/********************************************************************************
** Form generated from reading UI file 'admincitiesedit.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINCITIESEDIT_H
#define UI_ADMINCITIESEDIT_H

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

class Ui_adminCitiesEdit
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *cityNameEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *doneButton;
    QPushButton *clearButton;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QLabel *warningLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *adminCitiesEdit)
    {
        if (adminCitiesEdit->objectName().isEmpty())
            adminCitiesEdit->setObjectName("adminCitiesEdit");
        adminCitiesEdit->resize(800, 600);
        centralwidget = new QWidget(adminCitiesEdit);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(170, 130, 446, 231));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        cityNameEdit = new QLineEdit(verticalLayoutWidget);
        cityNameEdit->setObjectName("cityNameEdit");

        horizontalLayout->addWidget(cityNameEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        doneButton = new QPushButton(verticalLayoutWidget);
        doneButton->setObjectName("doneButton");
        doneButton->setStyleSheet(QString::fromUtf8(""));

        horizontalLayout_2->addWidget(doneButton);

        clearButton = new QPushButton(verticalLayoutWidget);
        clearButton->setObjectName("clearButton");

        horizontalLayout_2->addWidget(clearButton);

        addButton = new QPushButton(verticalLayoutWidget);
        addButton->setObjectName("addButton");

        horizontalLayout_2->addWidget(addButton);

        deleteButton = new QPushButton(verticalLayoutWidget);
        deleteButton->setObjectName("deleteButton");

        horizontalLayout_2->addWidget(deleteButton);


        verticalLayout->addLayout(horizontalLayout_2);

        warningLabel = new QLabel(verticalLayoutWidget);
        warningLabel->setObjectName("warningLabel");
        warningLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(warningLabel);

        adminCitiesEdit->setCentralWidget(centralwidget);
        menubar = new QMenuBar(adminCitiesEdit);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        adminCitiesEdit->setMenuBar(menubar);
        statusbar = new QStatusBar(adminCitiesEdit);
        statusbar->setObjectName("statusbar");
        adminCitiesEdit->setStatusBar(statusbar);

        retranslateUi(adminCitiesEdit);

        QMetaObject::connectSlotsByName(adminCitiesEdit);
    } // setupUi

    void retranslateUi(QMainWindow *adminCitiesEdit)
    {
        adminCitiesEdit->setWindowTitle(QString());
        label->setText(QCoreApplication::translate("adminCitiesEdit", "City name:", nullptr));
        doneButton->setText(QCoreApplication::translate("adminCitiesEdit", "Done", nullptr));
        clearButton->setText(QCoreApplication::translate("adminCitiesEdit", "Clear", nullptr));
        addButton->setText(QCoreApplication::translate("adminCitiesEdit", "Add", nullptr));
        deleteButton->setText(QCoreApplication::translate("adminCitiesEdit", "Delete", nullptr));
        warningLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class adminCitiesEdit: public Ui_adminCitiesEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINCITIESEDIT_H
