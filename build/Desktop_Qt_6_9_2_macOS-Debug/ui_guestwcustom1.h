/********************************************************************************
** Form generated from reading UI file 'guestwcustom1.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GUESTWCUSTOM1_H
#define UI_GUESTWCUSTOM1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_guestWcustom1
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QPushButton *backButton;
    QLabel *label;
    QPushButton *nextButton;
    QListWidget *distancesWidget;
    QLabel *label_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QLabel *startingCityLabel;
    QLabel *label_4;
    QListWidget *foodsWidget;
    QLabel *warningLabel;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *guestWcustom1)
    {
        if (guestWcustom1->objectName().isEmpty())
            guestWcustom1->setObjectName("guestWcustom1");
        guestWcustom1->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(guestWcustom1->sizePolicy().hasHeightForWidth());
        guestWcustom1->setSizePolicy(sizePolicy);
        centralwidget = new QWidget(guestWcustom1);
        centralwidget->setObjectName("centralwidget");
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(30, 70, 441, 311));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(verticalLayoutWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 437, 307));
        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        backButton = new QPushButton(centralwidget);
        backButton->setObjectName("backButton");
        backButton->setGeometry(QRect(40, 500, 100, 32));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(110, 10, 571, 51));
        QFont font;
        font.setPointSize(29);
        label->setFont(font);
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        nextButton = new QPushButton(centralwidget);
        nextButton->setObjectName("nextButton");
        nextButton->setGeometry(QRect(630, 500, 100, 32));
        distancesWidget = new QListWidget(centralwidget);
        distancesWidget->setObjectName("distancesWidget");
        distancesWidget->setGeometry(QRect(510, 90, 241, 171));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(510, 70, 61, 16));
        horizontalLayoutWidget = new QWidget(centralwidget);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(120, 400, 261, 21));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName("label_2");
        label_2->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        startingCityLabel = new QLabel(horizontalLayoutWidget);
        startingCityLabel->setObjectName("startingCityLabel");
        QFont font1;
        font1.setPointSize(12);
        startingCityLabel->setFont(font1);
        startingCityLabel->setFrameShape(QFrame::Shape::Box);
        startingCityLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        horizontalLayout->addWidget(startingCityLabel);

        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(510, 270, 61, 16));
        foodsWidget = new QListWidget(centralwidget);
        foodsWidget->setObjectName("foodsWidget");
        foodsWidget->setGeometry(QRect(510, 290, 241, 171));
        warningLabel = new QLabel(centralwidget);
        warningLabel->setObjectName("warningLabel");
        warningLabel->setGeometry(QRect(117, 450, 261, 20));
        guestWcustom1->setCentralWidget(centralwidget);
        menubar = new QMenuBar(guestWcustom1);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 24));
        guestWcustom1->setMenuBar(menubar);
        statusbar = new QStatusBar(guestWcustom1);
        statusbar->setObjectName("statusbar");
        guestWcustom1->setStatusBar(statusbar);

        retranslateUi(guestWcustom1);

        QMetaObject::connectSlotsByName(guestWcustom1);
    } // setupUi

    void retranslateUi(QMainWindow *guestWcustom1)
    {
        guestWcustom1->setWindowTitle(QString());
        backButton->setText(QCoreApplication::translate("guestWcustom1", "back", nullptr));
        label->setText(QCoreApplication::translate("guestWcustom1", "Please select starting City", nullptr));
        nextButton->setText(QCoreApplication::translate("guestWcustom1", "Next", nullptr));
        label_3->setText(QCoreApplication::translate("guestWcustom1", "Distances:", nullptr));
        label_2->setText(QCoreApplication::translate("guestWcustom1", "Selected City: ", nullptr));
        startingCityLabel->setText(QString());
        label_4->setText(QCoreApplication::translate("guestWcustom1", "Foods:", nullptr));
        warningLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class guestWcustom1: public Ui_guestWcustom1 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GUESTWCUSTOM1_H
