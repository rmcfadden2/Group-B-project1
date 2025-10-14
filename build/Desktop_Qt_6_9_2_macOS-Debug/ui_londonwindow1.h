/********************************************************************************
** Form generated from reading UI file 'londonwindow1.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LONDONWINDOW1_H
#define UI_LONDONWINDOW1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_londonWindow1
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpinBox *quantitySpinBox;
    QPushButton *selectButton;
    QPushButton *backButton;
    QPushButton *continueButton;
    QLabel *label_2;
    QLabel *warningLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *londonWindow1)
    {
        if (londonWindow1->objectName().isEmpty())
            londonWindow1->setObjectName("londonWindow1");
        londonWindow1->resize(800, 600);
        centralwidget = new QWidget(londonWindow1);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(150, 80, 461, 321));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(verticalLayoutWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 457, 317));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(120, 420, 521, 33));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        quantitySpinBox = new QSpinBox(horizontalLayoutWidget);
        quantitySpinBox->setObjectName("quantitySpinBox");

        horizontalLayout->addWidget(quantitySpinBox);

        selectButton = new QPushButton(horizontalLayoutWidget);
        selectButton->setObjectName("selectButton");

        horizontalLayout->addWidget(selectButton);

        backButton = new QPushButton(centralwidget);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(40, 500, 100, 32));
        continueButton = new QPushButton(centralwidget);
        continueButton->setObjectName("continueButton");
        continueButton->setGeometry(QRect(650, 500, 100, 32));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(147, 30, 461, 20));
        label_2->setAlignment(Qt::AlignmentFlag::AlignCenter);
        warningLabel = new QLabel(centralwidget);
        warningLabel->setObjectName("warningLabel");
        warningLabel->setGeometry(QRect(130, 470, 481, 20));
        warningLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        londonWindow1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(londonWindow1);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        londonWindow1->setMenuBar(menubar);
        statusbar = new QStatusBar(londonWindow1);
        statusbar->setObjectName("statusbar");
        londonWindow1->setStatusBar(statusbar);

        retranslateUi(londonWindow1);

        QMetaObject::connectSlotsByName(londonWindow1);
    } // setupUi

    void retranslateUi(QMainWindow *londonWindow1)
    {
        londonWindow1->setWindowTitle(QString());
        label->setText(QCoreApplication::translate("londonWindow1", "Please specify the amount of cities you would like to visit:", nullptr));
        selectButton->setText(QCoreApplication::translate("londonWindow1", "Select", nullptr));
        backButton->setText(QCoreApplication::translate("londonWindow1", "Back", nullptr));
        continueButton->setText(QCoreApplication::translate("londonWindow1", "Continue", nullptr));
        label_2->setText(QCoreApplication::translate("londonWindow1", "Your Trip Starting From London", nullptr));
        warningLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class londonWindow1: public Ui_londonWindow1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LONDONWINDOW1_H
