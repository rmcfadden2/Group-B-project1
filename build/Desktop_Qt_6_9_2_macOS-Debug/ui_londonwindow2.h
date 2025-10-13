/********************************************************************************
** Form generated from reading UI file 'londonwindow2.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LONDONWINDOW2_H
#define UI_LONDONWINDOW2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_londonWindow2
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *citiesScrollArea;
    QWidget *citiesWidget;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpinBox *quantitySpinBox;
    QListWidget *foodListWidget;
    QLabel *label_2;
    QPushButton *purchaseButton;
    QPushButton *checkoutButton;
    QLabel *label;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *londonWindow2)
    {
        if (londonWindow2->objectName().isEmpty())
            londonWindow2->setObjectName("londonWindow2");
        londonWindow2->resize(800, 600);
        centralwidget = new QWidget(londonWindow2);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(180, 70, 441, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        citiesScrollArea = new QScrollArea(verticalLayoutWidget);
        citiesScrollArea->setObjectName("citiesScrollArea");
        citiesScrollArea->setWidgetResizable(true);
        citiesWidget = new QWidget();
        citiesWidget->setObjectName("citiesWidget");
        citiesWidget->setGeometry(QRect(0, 0, 437, 297));
        citiesScrollArea->setWidget(citiesWidget);

        verticalLayout->addWidget(citiesScrollArea);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(270, 420, 131, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        quantitySpinBox = new QSpinBox(horizontalLayoutWidget);
        quantitySpinBox->setObjectName("quantitySpinBox");

        horizontalLayout->addWidget(quantitySpinBox);

        foodListWidget = new QListWidget(centralwidget);
        foodListWidget->setObjectName("foodListWidget");
        foodListWidget->setGeometry(QRect(70, 410, 181, 131));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(70, 390, 141, 16));
        purchaseButton = new QPushButton(centralwidget);
        purchaseButton->setObjectName("purchaseButton");
        purchaseButton->setGeometry(QRect(270, 460, 100, 32));
        checkoutButton = new QPushButton(centralwidget);
        checkoutButton->setObjectName("checkoutButton");
        checkoutButton->setGeometry(QRect(640, 500, 100, 32));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 0, 601, 71));
        QFont font;
        font.setPointSize(26);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        londonWindow2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(londonWindow2);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        londonWindow2->setMenuBar(menubar);
        statusbar = new QStatusBar(londonWindow2);
        statusbar->setObjectName("statusbar");
        londonWindow2->setStatusBar(statusbar);

        retranslateUi(londonWindow2);

        QMetaObject::connectSlotsByName(londonWindow2);
    } // setupUi

    void retranslateUi(QMainWindow *londonWindow2)
    {
        londonWindow2->setWindowTitle(QCoreApplication::translate("londonWindow2", "MainWindow", nullptr));
        label_3->setText(QCoreApplication::translate("londonWindow2", "Quantity", nullptr));
        label_2->setText(QCoreApplication::translate("londonWindow2", "select food:", nullptr));
        purchaseButton->setText(QCoreApplication::translate("londonWindow2", "Purchase", nullptr));
        checkoutButton->setText(QCoreApplication::translate("londonWindow2", "Checkout", nullptr));
        label->setText(QCoreApplication::translate("londonWindow2", "Shop for food in your selected cities", nullptr));
    } // retranslateUi

};

namespace Ui {
    class londonWindow2: public Ui_londonWindow2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LONDONWINDOW2_H
