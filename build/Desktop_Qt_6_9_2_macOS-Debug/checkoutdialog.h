#ifndef CHECKOUTDIALOG_H
#define CHECKOUTDIALOG_H

#include <QDialog>
#include <QList>
#include <QString>
#include "mainwindow.h" // for Purchase struct

namespace Ui {
class CheckoutDialog;
}

class CheckoutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit CheckoutDialog(const QList<Purchase> &cart, double total, QWidget *parent = nullptr);
    ~CheckoutDialog();

private slots:
    void on_closeButton_clicked();

private:
    Ui::CheckoutDialog *ui;
};

#endif // CHECKOUTDIALOG_H

