#ifndef CHECKOUTDIALOG_H
#define CHECKOUTDIALOG_H

#include <QDialog>
#include <Qstring>
#include "loadCities.h"

#include <vector>
#include <string>

namespace Ui {
class checkoutDialog;
}

class checkoutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit checkoutDialog(const vector<Purchase> &cart, const vector<string> purchasedCity, double t, vector<City> data, City start, QWidget *parent = nullptr);
    ~checkoutDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::checkoutDialog *ui;
    vector<City> cities;
    City startCity;
    const vector<Purchase> &cart;
    const vector<string> purchasedCities;
    double total;

};

#endif // CHECKOUTDIALOG_H
