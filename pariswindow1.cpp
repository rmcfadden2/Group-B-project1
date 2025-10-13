#include "pariswindow1.h"
#include "ui_pariswindow1.h"
#include "guestmainwindow.h"
#include <QLabel>
#include <QScrollArea>
#include <QVBoxLayout>
#include <QString>
#include <iomanip>
#include <sstream>
#include <QDebug>

parisWindow1::parisWindow1(City start, vector<City> &data, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::parisWindow1), startCity(start), trip(data)
{
    ui->setupUi(this);

    qDebug() << "Cities:";
    for(auto city : trip)
        qDebug() << city.getName();
    totalDist = 0;
    std::vector<std::string> plannedRoute = findClosestRoute(startCity.getName(), trip, totalDist);
    qDebug() << "Planned Route:";
    for(auto city : plannedRoute)
        qDebug() << city;

    outputTripSummary(plannedRoute, startCity, trip);

}

parisWindow1::~parisWindow1()
{
    delete ui;
}


City* parisWindow1::findCity(std::vector<City>& cities, const std::string& name) {
    for (auto& c : cities) {
        if (c.getName() == name) {
            return &c;
        }
    }
    return nullptr;
}

std::string parisWindow1::findNextClosest(const std::string& currentCityName, const std::vector<City>& allCities, const std::vector<std::string>& visitedCities, double& totalDist) {
    const City* currentCity = findCity(const_cast<std::vector<City>&>(allCities), currentCityName);
    if (!currentCity) return "";
    double minDistance = -1.0;
    std::string closestCityName = "";
    for (const auto& dist : currentCity->getDistances()) {
        bool notInList = true;
        for(auto city : allCities)
        {
            if(city.getName() == dist.getDestinationName())
                notInList = false;
        }
        if(!notInList)
        {
            bool alreadyVisited = false;
            for (const auto& visited : visitedCities) {
                if (visited == dist.getDestinationName()) {
                    alreadyVisited = true;
                    break;
                }
            }
            if (!alreadyVisited) {
                if (minDistance == -1.0 || dist.getdistance() < minDistance) {
                    minDistance = dist.getdistance();
                    closestCityName = dist.getDestinationName();
                }
            }
        }
    }
    for(auto dist : currentCity->getDistances())
    {
        if(closestCityName == dist.getDestinationName())
        {
            totalDist += dist.getdistance();
        }
    }
    return closestCityName;
}

std::vector<std::string> parisWindow1::findClosestRoute(const std::string& startCityName, std::vector<City>& allCities, double& totalDist){
    std::vector<std::string> route;
    std::string currentCity = startCityName;
    while (!currentCity.empty()) {
        route.push_back(currentCity);
        std::string nextCity = findNextClosest(currentCity, allCities, route, totalDist);
        currentCity = nextCity;
    }
    return route;
}

void parisWindow1::outputTripSummary(
    const vector<string>& plannedRoute, const City& startingCity, const vector<City>& allCities)
{
    // Clear previous summary
    QLayout* oldLayout = ui->summaryContainer->layout();
    if (oldLayout) {
        QLayoutItem* item;
        while ((item = oldLayout->takeAt(0)) != nullptr) {
            delete item->widget();
            delete item;
        }
        delete oldLayout;
    }

    QVBoxLayout* layout = new QVBoxLayout;


    // Iterate through the planned route
    int i = 1;
    for (const auto& cityName : plannedRoute) {
        QLabel* cityLabel = new QLabel(QString("\nCity %1: %2").arg(i).arg(QString::fromStdString(cityName)));
        cityLabel->setStyleSheet("font-weight: bold; font-size: 13px; color: white;");
        layout->addWidget(cityLabel);
        i++;
    }


    layout->addStretch(); // push everything to top

    // Put layout in scroll area
    QScrollArea* scroll = new QScrollArea(ui->summaryContainer);
    QWidget* container = new QWidget;
    container->setLayout(layout);
    scroll->setWidget(container);
    scroll->setWidgetResizable(true);

    // Clear any previous widget in the summaryContainer and add scroll
    QLayout* containerLayout = ui->summaryContainer->layout();
    if (!containerLayout) {
        containerLayout = new QVBoxLayout(ui->summaryContainer);
        ui->summaryContainer->setLayout(containerLayout);
    }

    // Remove old widgets
    QLayoutItem* child;
    while ((child = containerLayout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }
    ui->totalDistLabel->setText(QString::number(totalDist) + " km");
    containerLayout->addWidget(scroll);
}

void parisWindow1::on_restartButton_clicked()
{
    guestMainWindow *window = new guestMainWindow;
    window->setGeometry(this->geometry());
    window->show();
    this->hide();
}
