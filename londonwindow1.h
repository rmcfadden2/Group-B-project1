#ifndef LONDONWINDOW1_H
#define LONDONWINDOW1_H

#include <QMainWindow>

#include <vector>
#include <string>
#include "loadCities.h"

namespace Ui {
class londonWindow1;
}

class londonWindow1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit londonWindow1(City start, vector<City> &cities, QWidget *parent = nullptr);
    ~londonWindow1();
    void populateCityButtons();
    City* findCity(std::vector<City>& cities, const std::string& name);
    std::string findNextClosest(const std::string& currentCityName, const std::vector<City>& allCities, const std::vector<std::string>& visitedCities, double& totalDist);
    std::vector<std::string> findClosestRoute(const std::string& startCityName, std::vector<City>& allCities, double& totalDist);

private slots:
    void on_selectButton_clicked();

    void on_backButton_clicked();

    void on_continueButton_clicked();

private:
    Ui::londonWindow1 *ui;
    vector<City> &citiesData;
    vector<string> plannedRoute;
    City startingCity;
    bool amountSpecified = false;
    double totalDist;
};

#endif // LONDONWINDOW1_H
