#ifndef PARISWINDOW1_H
#define PARISWINDOW1_H

#include <QMainWindow>
#include "loadCities.h"

namespace Ui {
class parisWindow1;
}

class parisWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit parisWindow1(City start, vector<City> &data, QWidget *parent = nullptr);
    ~parisWindow1();
    City* findCity(std::vector<City>& cities, const std::string& name);
    std::string findNextClosest(const std::string& currentCityName, const std::vector<City>& allCities, const std::vector<std::string>& visitedCities, double& totalDist);
    std::vector<std::string> findClosestRoute(const std::string& startCityName, std::vector<City>& allCities, double& totalDist);
    void outputTripSummary(const vector<string>& plannedRoute, const City& startingCity, const vector<City>& allCities);

private slots:
    void on_restartButton_clicked();

private:
    Ui::parisWindow1 *ui;
    vector<City> &trip;
    City startCity;
    double totalDist;
};

#endif // PARISWINDOW1_H
