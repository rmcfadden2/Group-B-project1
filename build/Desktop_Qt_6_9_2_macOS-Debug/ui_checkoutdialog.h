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
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>

QT_BEGIN_NAMESPACE

class Ui_CheckoutDialog
{
public:
    QTableWidget *summaryTable;
    QLabel *totalLabel;
    QPushButton *closeButton;

    void setupUi(QDialog *CheckoutDialog)
    {
        if (CheckoutDialog->objectName().isEmpty())
            CheckoutDialog->setObjectName("CheckoutDialog");
        CheckoutDialog->resize(574, 413);
        summaryTable = new QTableWidget(CheckoutDialog);
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
        summaryTable->setGeometry(QRect(30, 60, 501, 192));
        totalLabel = new QLabel(CheckoutDialog);
        totalLabel->setObjectName("totalLabel");
        totalLabel->setGeometry(QRect(37, 290, 501, 20));
        totalLabel->setAlignment(Qt::AlignmentFlag::AlignCenter);
        closeButton = new QPushButton(CheckoutDialog);
        closeButton->setObjectName("closeButton");
        closeButton->setGeometry(QRect(440, 360, 100, 32));

        retranslateUi(CheckoutDialog);

        QMetaObject::connectSlotsByName(CheckoutDialog);
    } // setupUi

    void retranslateUi(QDialog *CheckoutDialog)
    {
        CheckoutDialog->setWindowTitle(QCoreApplication::translate("CheckoutDialog", "Dialog", nullptr));
        QTableWidgetItem *___qtablewidgetitem = summaryTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("CheckoutDialog", "Food", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = summaryTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("CheckoutDialog", "City", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = summaryTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("CheckoutDialog", "Amount", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = summaryTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("CheckoutDialog", "Price", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = summaryTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("CheckoutDialog", "Total", nullptr));
        totalLabel->setText(QCoreApplication::translate("CheckoutDialog", "TextLabel", nullptr));
        closeButton->setText(QCoreApplication::translate("CheckoutDialog", "Close", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CheckoutDialog: public Ui_CheckoutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHECKOUTDIALOG_H
