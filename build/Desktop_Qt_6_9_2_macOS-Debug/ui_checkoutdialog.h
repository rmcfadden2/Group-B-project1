/********************************************************************************
** Form generated from reading UI file 'checkoutdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHECKOUTDIALOG_H
#define UI_CHECKOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_checkoutDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *titleLabel;
    QTableWidget *summaryTable;
    QLabel *totalLabel;
    QLabel *warningLabel;

    void setupUi(QDialog *checkoutDialog)
    {
        if (checkoutDialog->objectName().isEmpty())
            checkoutDialog->setObjectName("checkoutDialog");
        checkoutDialog->resize(530, 399);
        buttonBox = new QDialogButtonBox(checkoutDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(140, 330, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        titleLabel = new QLabel(checkoutDialog);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setGeometry(QRect(100, 60, 291, 20));
        titleLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        summaryTable = new QTableWidget(checkoutDialog);
        if (summaryTable->columnCount() < 5)
            summaryTable->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        summaryTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        summaryTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        summaryTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        summaryTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        summaryTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        summaryTable->setObjectName("summaryTable");
        summaryTable->setGeometry(QRect(10, 90, 501, 192));
        totalLabel = new QLabel(checkoutDialog);
        totalLabel->setObjectName("totalLabel");
        totalLabel->setGeometry(QRect(10, 300, 501, 20));
        totalLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        warningLabel = new QLabel(checkoutDialog);
        warningLabel->setObjectName("warningLabel");
        warningLabel->setGeometry(QRect(37, 370, 421, 20));
        warningLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);

        retranslateUi(checkoutDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, checkoutDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, checkoutDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(checkoutDialog);
    } // setupUi

    void retranslateUi(QDialog *checkoutDialog)
    {
        checkoutDialog->setWindowTitle(QString());
        titleLabel->setText(QCoreApplication::translate("checkoutDialog", "Trip Food Reciept", nullptr));
        QTableWidgetItem *___qtablewidgetitem = summaryTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("checkoutDialog", "Food", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = summaryTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("checkoutDialog", "City", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = summaryTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("checkoutDialog", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = summaryTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("checkoutDialog", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = summaryTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("checkoutDialog", "Total", nullptr));
        totalLabel->setText(QCoreApplication::translate("checkoutDialog", "TextLabel", nullptr));
        warningLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class checkoutDialog: public Ui_checkoutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUTDIALOG_H
