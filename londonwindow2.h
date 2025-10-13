#ifndef LONDONWINDOW2_H
#define LONDONWINDOW2_H

#include <QMainWindow>
#include <vector>
#include "loadCities.h"

using namespace std;

namespace Ui {
class londonWindow2;
}

class londonWindow2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit londonWindow2(City start, vector<City> &route, QWidget *parent = nullptr);
    ~londonWindow2();

private:
    Ui::londonWindow2 *ui;
    vector<City> &cities;
    City startCity;
    vector<Purchase> cart;
    City currentCity;
    vector<string> purchasedCities;
    double totalCost = 0.0;

    void populateCityButtons();

private slots:
    void displayFoodsForCity(const City &city);
    void on_purchaseButton_clicked();    // add selected food to cart
    void on_checkoutButton_clicked();
};

#endif // LONDONWINDOW2_H
