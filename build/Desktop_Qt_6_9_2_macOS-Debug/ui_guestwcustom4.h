/********************************************************************************
** Form generated from reading UI file 'guestwcustom4.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUESTWCUSTOM4_H
#define UI_GUESTWCUSTOM4_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guestWcustom4
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QWidget *summaryContainer;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *totalDistLabel;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *grandTotalLabel;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QPushButton *restartButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *guestWcustom4)
    {
        if (guestWcustom4->objectName().isEmpty())
            guestWcustom4->setObjectName("guestWcustom4");
        guestWcustom4->resize(800, 600);
        centralwidget = new QWidget(guestWcustom4);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(100, 60, 571, 401));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        summaryContainer = new QWidget(verticalLayoutWidget);
        summaryContainer->setObjectName("summaryContainer");

        verticalLayout->addWidget(summaryContainer);

        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(280, 510, 221, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName("label");

        horizontalLayout->addWidget(label);

        totalDistLabel = new QLabel(horizontalLayoutWidget);
        totalDistLabel->setObjectName("totalDistLabel");

        horizontalLayout->addWidget(totalDistLabel);

        horizontalLayoutWidget_2 = new QWidget(centralwidget);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(280, 470, 221, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget_2);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        grandTotalLabel = new QLabel(horizontalLayoutWidget_2);
        grandTotalLabel->setObjectName("grandTotalLabel");

        horizontalLayout_2->addWidget(grandTotalLabel);

        horizontalLayoutWidget_3 = new QWidget(centralwidget);
        horizontalLayoutWidget_3->setObjectName("horizontalLayoutWidget_3");
        horizontalLayoutWidget_3->setGeometry(QRect(130, 20, 511, 31));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget_3);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout_3->addWidget(label_3);

        restartButton = new QPushButton(centralwidget);
        restartButton->setObjectName("restartButton");
        restartButton->setGeometry(QRect(650, 510, 100, 32));
        guestWcustom4->setCentralWidget(centralwidget);
        menubar = new QMenuBar(guestWcustom4);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        guestWcustom4->setMenuBar(menubar);
        statusbar = new QStatusBar(guestWcustom4);
        statusbar->setObjectName("statusbar");
        guestWcustom4->setStatusBar(statusbar);

        retranslateUi(guestWcustom4);

        QMetaObject::connectSlotsByName(guestWcustom4);
    } // setupUi

    void retranslateUi(QMainWindow *guestWcustom4)
    {
        guestWcustom4->setWindowTitle(QString());
        label->setText(QCoreApplication::translate("guestWcustom4", "Total Distance Travelled:", nullptr));
        totalDistLabel->setText(QString());
        label_2->setText(QCoreApplication::translate("guestWcustom4", "Grand Total: ", nullptr));
        grandTotalLabel->setText(QString());
        label_3->setText(QCoreApplication::translate("guestWcustom4", "Trip Summary", nullptr));
        restartButton->setText(QCoreApplication::translate("guestWcustom4", "Restart", nullptr));
    } // retranslateUi

};

namespace Ui {
    class guestWcustom4: public Ui_guestWcustom4 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUESTWCUSTOM4_H
