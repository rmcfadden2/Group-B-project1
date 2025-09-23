#include "checkoutdialog.h"
#include "ui_checkoutdialog.h"
#include <QTableWidgetItem>

CheckoutDialog::CheckoutDialog(const QList<Purchase> &cart, double total, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckoutDialog)
{
    ui->setupUi(this);

    // Configure table
    ui->summaryTable->setColumnCount(5);
    QStringList headers = {"Food", "City", "Quantity", "Price", "Total"};
    ui->summaryTable->setHorizontalHeaderLabels(headers);
    ui->summaryTable->setRowCount(cart.size());

    for (int i = 0; i < cart.size(); ++i) {
        const Purchase &p = cart[i];
        ui->summaryTable->setItem(i, 0, new QTableWidgetItem(p.food));
        ui->summaryTable->setItem(i, 1, new QTableWidgetItem(p.city));
        ui->summaryTable->setItem(i, 2, new QTableWidgetItem(QString::number(p.quantity)));
        ui->summaryTable->setItem(i, 3, new QTableWidgetItem(QString::number(p.pricePerUnit, 'f', 2)));
        ui->summaryTable->setItem(i, 4, new QTableWidgetItem(QString::number(p.quantity * p.pricePerUnit, 'f', 2)));
    }

    // Show total
    ui->totalLabel->setText(QString("Grand Total: $%1").arg(total, 0, 'f', 2));
}

CheckoutDialog::~CheckoutDialog()
{
    delete ui;
}

void CheckoutDialog::on_closeButton_clicked()
{
    accept();
}

