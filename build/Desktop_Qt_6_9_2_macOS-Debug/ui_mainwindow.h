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
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *citiesWidget;
    QListWidget *foodListWidget;
    QSpinBox *quantitySpinBox;
    QPushButton *purchaseButton;
    QPushButton *checkoutButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        citiesWidget = new QWidget(centralwidget);
        citiesWidget->setObjectName("citiesWidget");
        citiesWidget->setGeometry(QRect(180, 10, 431, 361));
        foodListWidget = new QListWidget(centralwidget);
        foodListWidget->setObjectName("foodListWidget");
        foodListWidget->setGeometry(QRect(10, 390, 211, 151));
        quantitySpinBox = new QSpinBox(centralwidget);
        quantitySpinBox->setObjectName("quantitySpinBox");
        quantitySpinBox->setGeometry(QRect(240, 410, 42, 22));
        quantitySpinBox->setMaximum(100);
        purchaseButton = new QPushButton(centralwidget);
        purchaseButton->setObjectName("purchaseButton");
        purchaseButton->setGeometry(QRect(230, 440, 100, 32));
        checkoutButton = new QPushButton(centralwidget);
        checkoutButton->setObjectName("checkoutButton");
        checkoutButton->setGeometry(QRect(570, 500, 100, 32));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 390, 71, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 370, 121, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 20, 71, 31));
        QFont font;
        font.setPointSize(25);
        label_3->setFont(font);
        label_3->setFrameShape(QFrame::Shape::NoFrame);
        label_3->setScaledContents(false);
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(410, 510, 58, 16));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        purchaseButton->setText(QCoreApplication::translate("MainWindow", "Purchase", nullptr));
        checkoutButton->setText(QCoreApplication::translate("MainWindow", "Checkout", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Amount:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Select Food:", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "City:", nullptr));
        label_4->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
