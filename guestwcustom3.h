#ifndef GUESTWCUSTOM3_H
#define GUESTWCUSTOM3_H

#include <QMainWindow>
#include <vector>
#include <string>
#include "loadCities.h"

using namespace std;

namespace Ui {
class guestWcustom3;
}


class guestWcustom3 : public QMainWindow
{
    Q_OBJECT

public:
    explicit guestWcustom3(City start, vector<City> &data, QWidget *parent = nullptr);
    ~guestWcustom3();

private:
    Ui::guestWcustom3 *ui;
    vector<City> cities;
    City startCity;
    vector<Purchase> cart;
    City currentCity;
    vector<string> purchasedCities;
    double totalCost = 0.0;

    void populateCityButtons();              // buttons for cities in scroll area

private slots:
    void displayFoodsForCity(const City &city);
    void on_purchaseButton_clicked();    // add selected food to cart
    void on_checkoutButton_clicked();
};

#endif // GUESTWCUSTOM3_H

