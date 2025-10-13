/********************************************************************************
** Form generated from reading UI file 'guestwcustom3.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUESTWCUSTOM3_H
#define UI_GUESTWCUSTOM3_H

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

class Ui_guestWcustom3
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *citiesScrollArea;
    QWidget *citiesWidget;
    QListWidget *foodListWidget;
    QLabel *label_2;
    QPushButton *checkoutButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpinBox *quantitySpinBox;
    QPushButton *purchaseButton;
    QLabel *purchaseWarningLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *guestWcustom3)
    {
        if (guestWcustom3->objectName().isEmpty())
            guestWcustom3->setObjectName("guestWcustom3");
        guestWcustom3->resize(800, 600);
        centralwidget = new QWidget(guestWcustom3);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(90, -10, 601, 71));
        QFont font;
        font.setPointSize(26);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(190, 60, 411, 281));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        citiesScrollArea = new QScrollArea(verticalLayoutWidget);
        citiesScrollArea->setObjectName("citiesScrollArea");
        citiesScrollArea->setWidgetResizable(true);
        citiesWidget = new QWidget();
        citiesWidget->setObjectName("citiesWidget");
        citiesWidget->setGeometry(QRect(0, 0, 407, 277));
        citiesScrollArea->setWidget(citiesWidget);

        verticalLayout->addWidget(citiesScrollArea);

        foodListWidget = new QListWidget(centralwidget);
        foodListWidget->setObjectName("foodListWidget");
        foodListWidget->setGeometry(QRect(30, 390, 181, 131));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 360, 141, 16));
        checkoutButton = new QPushButton(centralwidget);
        checkoutButton->setObjectName("checkoutButton");
        checkoutButton->setGeometry(QRect(660, 490, 100, 32));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(230, 410, 131, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName("label_3");

        horizontalLayout->addWidget(label_3);

        quantitySpinBox = new QSpinBox(horizontalLayoutWidget);
        quantitySpinBox->setObjectName("quantitySpinBox");

        horizontalLayout->addWidget(quantitySpinBox);

        purchaseButton = new QPushButton(centralwidget);
        purchaseButton->setObjectName("purchaseButton");
        purchaseButton->setGeometry(QRect(240, 470, 100, 32));
        purchaseWarningLabel = new QLabel(centralwidget);
        purchaseWarningLabel->setObjectName("purchaseWarningLabel");
        purchaseWarningLabel->setGeometry(QRect(227, 450, 131, 20));
        guestWcustom3->setCentralWidget(centralwidget);
        menubar = new QMenuBar(guestWcustom3);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        guestWcustom3->setMenuBar(menubar);
        statusbar = new QStatusBar(guestWcustom3);
        statusbar->setObjectName("statusbar");
        guestWcustom3->setStatusBar(statusbar);

        retranslateUi(guestWcustom3);

        QMetaObject::connectSlotsByName(guestWcustom3);
    } // setupUi

    void retranslateUi(QMainWindow *guestWcustom3)
    {
        guestWcustom3->setWindowTitle(QString());
        label->setText(QCoreApplication::translate("guestWcustom3", "Shop for food in your selected cities", nullptr));
        label_2->setText(QCoreApplication::translate("guestWcustom3", "select food:", nullptr));
        checkoutButton->setText(QCoreApplication::translate("guestWcustom3", "Checkout", nullptr));
        label_3->setText(QCoreApplication::translate("guestWcustom3", "Quantity", nullptr));
        purchaseButton->setText(QCoreApplication::translate("guestWcustom3", "Purchase", nullptr));
        purchaseWarningLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class guestWcustom3: public Ui_guestWcustom3 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUESTWCUSTOM3_H
