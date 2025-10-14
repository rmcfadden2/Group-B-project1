/********************************************************************************
** Form generated from reading UI file 'adminfoodedit.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINFOODEDIT_H
#define UI_ADMINFOODEDIT_H

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

class Ui_adminFoodEdit
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *cityNameEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *foodNameEdit;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *newPriceEdit;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *doneButton;
    QPushButton *clearButton;
    QPushButton *addButton;
    QPushButton *deleteButton;
    QPushButton *editPriceButton;
    QLabel *warningLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *adminFoodEdit)
    {
        if (adminFoodEdit->objectName().isEmpty())
            adminFoodEdit->setObjectName("adminFoodEdit");
        adminFoodEdit->resize(800, 600);
        centralwidget = new QWidget(adminFoodEdit);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(180, 110, 446, 311));
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

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName("label_2");

        horizontalLayout_3->addWidget(label_2);

        foodNameEdit = new QLineEdit(verticalLayoutWidget);
        foodNameEdit->setObjectName("foodNameEdit");

        horizontalLayout_3->addWidget(foodNameEdit);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout_4->addWidget(label_3);

        newPriceEdit = new QLineEdit(verticalLayoutWidget);
        newPriceEdit->setObjectName("newPriceEdit");

        horizontalLayout_4->addWidget(newPriceEdit);


        verticalLayout->addLayout(horizontalLayout_4);

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

        editPriceButton = new QPushButton(verticalLayoutWidget);
        editPriceButton->setObjectName("editPriceButton");

        horizontalLayout_2->addWidget(editPriceButton);


        verticalLayout->addLayout(horizontalLayout_2);

        warningLabel = new QLabel(verticalLayoutWidget);
        warningLabel->setObjectName("warningLabel");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(warningLabel->sizePolicy().hasHeightForWidth());
        warningLabel->setSizePolicy(sizePolicy);
        warningLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(warningLabel);

        adminFoodEdit->setCentralWidget(centralwidget);
        menubar = new QMenuBar(adminFoodEdit);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        adminFoodEdit->setMenuBar(menubar);
        statusbar = new QStatusBar(adminFoodEdit);
        statusbar->setObjectName("statusbar");
        adminFoodEdit->setStatusBar(statusbar);

        retranslateUi(adminFoodEdit);

        QMetaObject::connectSlotsByName(adminFoodEdit);
    } // setupUi

    void retranslateUi(QMainWindow *adminFoodEdit)
    {
        adminFoodEdit->setWindowTitle(QCoreApplication::translate("adminFoodEdit", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("adminFoodEdit", "            City:", nullptr));
        label_2->setText(QCoreApplication::translate("adminFoodEdit", "           Food:", nullptr));
        label_3->setText(QCoreApplication::translate("adminFoodEdit", "  New Price:", nullptr));
        doneButton->setText(QCoreApplication::translate("adminFoodEdit", "Done", nullptr));
        clearButton->setText(QCoreApplication::translate("adminFoodEdit", "Clear", nullptr));
        addButton->setText(QCoreApplication::translate("adminFoodEdit", "Add", nullptr));
        deleteButton->setText(QCoreApplication::translate("adminFoodEdit", "Delete", nullptr));
        editPriceButton->setText(QCoreApplication::translate("adminFoodEdit", "Edit Price", nullptr));
        warningLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class adminFoodEdit: public Ui_adminFoodEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINFOODEDIT_H
