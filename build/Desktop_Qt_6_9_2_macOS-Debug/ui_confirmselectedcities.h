/********************************************************************************
** Form generated from reading UI file 'confirmselectedcities.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMSELECTEDCITIES_H
#define UI_CONFIRMSELECTEDCITIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_confirmSelectedCities
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QScrollArea *scrollArea;
    QWidget *citiesWidget;

    void setupUi(QDialog *confirmSelectedCities)
    {
        if (confirmSelectedCities->objectName().isEmpty())
            confirmSelectedCities->setObjectName("confirmSelectedCities");
        confirmSelectedCities->resize(400, 300);
        buttonBox = new QDialogButtonBox(confirmSelectedCities);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::No|QDialogButtonBox::StandardButton::Yes);
        label = new QLabel(confirmSelectedCities);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 30, 251, 16));
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);
        verticalLayoutWidget = new QWidget(confirmSelectedCities);
        verticalLayoutWidget->setObjectName("verticalLayoutWidget");
        verticalLayoutWidget->setGeometry(QRect(70, 70, 261, 141));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(verticalLayoutWidget);
        scrollArea->setObjectName("scrollArea");
        scrollArea->setWidgetResizable(true);
        citiesWidget = new QWidget();
        citiesWidget->setObjectName("citiesWidget");
        citiesWidget->setGeometry(QRect(0, 0, 257, 137));
        scrollArea->setWidget(citiesWidget);

        verticalLayout->addWidget(scrollArea);


        retranslateUi(confirmSelectedCities);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, confirmSelectedCities, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, confirmSelectedCities, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(confirmSelectedCities);
    } // setupUi

    void retranslateUi(QDialog *confirmSelectedCities)
    {
        confirmSelectedCities->setWindowTitle(QString());
        label->setText(QCoreApplication::translate("confirmSelectedCities", "Are these the cities you want to visit?", nullptr));
    } // retranslateUi

};

namespace Ui {
    class confirmSelectedCities: public Ui_confirmSelectedCities {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMSELECTEDCITIES_H
