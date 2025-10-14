#include "londonwindow1.h"
#include "ui_londonwindow1.h"
#include "guestwplanned1.h"
#include "londonwindow2.h"
#include "guestwcustom3.h"

londonWindow1::londonWindow1(City start, vector<City> &cities, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::londonWindow1), startingCity(start), citiesData(cities)
{
    ui->setupUi(this);
    for(auto city : citiesData)
    {
        plannedRoute.push_back(city.getName());
    }

    populateCityButtons();
}

londonWindow1::~londonWindow1()
{
    delete ui;
}

void londonWindow1::populateCityButtons()
{
    // Get the container widget inside the scroll area
    QWidget* container = ui->scrollArea->widget();
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(container->layout());
    if (!layout) {
        layout = new QVBoxLayout(container);
        container->setLayout(layout);
    }

    // Clear existing buttons if any
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    // Create a button for each city
    for (const auto &city : plannedRoute) {
        QPushButton* btn = new QPushButton(QString::fromStdString(city));
        layout->addWidget(btn);
    }

    layout->addStretch(); // pushes buttons to the top

    ui->quantitySpinBox->setMinimum(1);
    ui->quantitySpinBox->setMaximum(citiesData.size());
}

City* londonWindow1::findCity(std::vector<City>& cities, const std::string& name) {
    for (auto& c : cities) {
        if (c.getName() == name) {
            return &c;
        }
    }
    return nullptr;
}

std::string londonWindow1::findNextClosest(const std::string& currentCityName, const std::vector<City>& allCities, const std::vector<std::string>& visitedCities, double& totalDist) {
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

std::vector<std::string> londonWindow1::findClosestRoute(const std::string& startCityName, std::vector<City>& allCities, double& totalDist){
    std::vector<std::string> route;
    std::string currentCity = startCityName;
    route.push_back(currentCity);
    for(int i = 1; i < ui->quantitySpinBox->value(); i++){
        std::string nextCity = findNextClosest(currentCity, allCities, route, totalDist);
        currentCity = nextCity;
        route.push_back(currentCity);
    }
    return route;
}

void londonWindow1::on_selectButton_clicked()
{
    totalDist = 0;
    plannedRoute = findClosestRoute(startingCity.getName(), citiesData, totalDist);
    populateCityButtons();
    amountSpecified = true;
}


void londonWindow1::on_backButton_clicked()
{
    guestWplanned1 *window = new guestWplanned1(citiesData);

    window->setGeometry(this->geometry());

    window->show();
    this->close();
}


void londonWindow1::on_continueButton_clicked()
{
    vector<City> plannedCities;
    if(amountSpecified)
    {
        qDebug() << "Continue Button Clicked!!!";
        ui->warningLabel->setText("");
        for(auto plannedCity : plannedRoute)
        {
            for(auto city : citiesData)
            {
                if(plannedCity == city.getName())
                {
                    plannedCities.push_back(city);
                    break;
                }
            }
        }
        for(auto city : plannedCities)
        {
            qDebug() << city.getName();
            for(auto dist : city.getDistances())
            {
                qDebug() << dist.getDestinationName() << dist.getdistance();
            }
            for(auto food : city.getFoods())
            {
                qDebug() << food.getName();
            }
        }

        qDebug() << "Launching guestWcustom3 with" << plannedCities.size() << "cities";

        guestWcustom3 *window = new guestWcustom3(startingCity, plannedCities, this);
        window->setGeometry(this->geometry());

        window->show();
        this->close();
    }
    else
    {
        ui->warningLabel->setText("You did not specify the amount of cities you want to visit!");
    }
}

