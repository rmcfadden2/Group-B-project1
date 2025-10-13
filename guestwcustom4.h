#ifndef GUESTWCUSTOM4_H
#define GUESTWCUSTOM4_H

#include <QMainWindow>
#include <QString>
#include "loadCities.h"

#include <vector>
#include <string>

using namespace std;

namespace Ui {
class guestWcustom4;
}

class guestWcustom4 : public QMainWindow
{
    Q_OBJECT

public:
    explicit guestWcustom4(const vector<Purchase> &c, const vector<string> purchasedCity, double totalCost, vector<City> &data, City start, QWidget *parent = nullptr);
    ~guestWcustom4();

    std::string findNextClosest(const std::string& currentCityName, const std::vector<City>& allCities, const std::vector<std::string>& visitedCities, double& totalDist);
    std::vector<std::string> findClosestRoute(const std::string& startCityName, std::vector<City>& allCities, double& totalDist);
    City* findCity(std::vector<City>& cities, const std::string& name);
    void outputTripSummary(const vector<string>& plannedRoute, const vector<string>& purchasedCities, double grandTotal, const City& startingCity, const vector<City>& allCities);

private slots:
    void on_restartButton_clicked();

private:
    Ui::guestWcustom4 *ui;
    const vector<Purchase> &cart;
    const vector<string> purchasedCities;
    double total;
    vector<City> &cities;
    City startingCity;
    double totalDist;
};

#endif // GUESTWCUSTOM4_H
