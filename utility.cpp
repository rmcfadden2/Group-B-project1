#include "story1.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

City* findCity(std::vector<City>& cities, const std::string& name) {
    for (auto& c : cities) {
        if (c.getName() == name) {
            return &c;
        }
    }
    return nullptr;
}

void loadDistances(const std::string& filename, std::vector<City>& cities) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open " << filename << "\n";
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream stream(line);
        std::string startCity, endCity, distStr;
        std::getline(stream, startCity, ',');
        std::getline(stream, endCity, ',');
        std::getline(stream, distStr, ',');
        double dist = 0.0;
        try {
            dist = std::stod(distStr);
        } catch (...) {
            std::cerr << "Invalid distance: " << distStr << "\n";
            continue;
        }
        City* start = findCity(cities, startCity);
        if (start) {
            start->addDistance(Distance(endCity, dist));
        } else {
            std::cerr << "Start city not found: " << startCity << "\n";
        }
    }
    file.close();
}

void loadFoods(const std::string& filename, std::vector<City>& cities) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open " << filename << "\n";
        return;
    }
    std::string line;
    std::getline(file, line);
    std::string currentCity;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream stream(line);
        std::string firstCol, foodName, costStr;
        std::getline(stream, firstCol, ',');
        std::getline(stream, foodName, ',');
        std::getline(stream, costStr, ',');
        if (!firstCol.empty()) {
            currentCity = firstCol;
        }
        if (currentCity.empty() || foodName.empty()) {
            continue;
        }
        if (!costStr.empty()) {
            costStr.erase(std::remove(costStr.begin(), costStr.end(), '$'), costStr.end());
            costStr.erase(std::remove_if(costStr.begin(), costStr.end(), ::isspace), costStr.end());
        }
        double price = 0.0;
        try {
            if (!costStr.empty())
                price = std::stod(costStr);
        } catch (...) {
            std::cerr << "Invalid price for food " << foodName << ": " << costStr << "\n";
            continue;
        }
        City* c = findCity(cities, currentCity);
        if (c) {
            c->addFood(PopularFood(foodName, price));
        } else {
            std::cerr << "City not found: " << currentCity << "\n";
        }
    }
    file.close();
}

void displaySelectableCities(const std::vector<City>& cities) {
    std::cout << "\nAvailable Cities:\n";
    for (size_t i = 0; i < cities.size(); ++i) {
        std::cout << i + 1 << ". " << cities[i].getName() << "\n";
    }
}

City* selectCity(const std::vector<City>& cities) {
    int choice;
    while (true) {
        std::cout << "Enter the number of your starting city: ";
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > cities.size()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid selection. Please try again.\n";
        } else {
            std::cin.ignore(10000, '\n');
            return findCity(const_cast<std::vector<City>&>(cities), cities[choice - 1].getName());
        }
    }
}

std::string findNextClosest(const std::string& currentCityName, const std::vector<City>& allCities, const std::vector<std::string>& visitedCities) {
    const City* currentCity = findCity(const_cast<std::vector<City>&>(allCities), currentCityName);
    if (!currentCity) return "";
    double minDistance = -1.0;
    std::string closestCityName = "";
    for (const auto& dist : currentCity->getDistances()) {
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
    return closestCityName;
}

std::vector<std::string> findClosestRoute(const std::string& startCityName, std::vector<City>& allCities) {
    std::vector<std::string> route;
    std::string currentCity = startCityName;
    while (!currentCity.empty()) {
        route.push_back(currentCity);
        std::string nextCity = findNextClosest(currentCity, allCities, route);
        currentCity = nextCity;
    }
    return route;
}

void displayRoute(const std::vector<std::string>& route) {
    std::cout << "\nYour planned route:\n";
    for (size_t i = 0; i < route.size(); ++i) {
        std::cout << i + 1 << ". " << route[i];
        if (i < route.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << "\n";
}

double calculateTotalDistance(const std::vector<std::string>& route, const std::vector<City>& allCities) {
    if (route.size() < 2) return 0.0;
    double totalDistance = 0.0;
    for (size_t i = 0; i < route.size() - 1; ++i) {
        const std::string& startName = route[i];
        const std::string& endName = route[i+1];
        City* startCity = findCity(const_cast<std::vector<City>&>(allCities), startName);
        if (startCity) {
            for (const auto& dist : startCity->getDistances()) {
                if (dist.getDestinationName() == endName) {
                    totalDistance += dist.getdistance();
                    break;
                }
            }
        }
    }
    return totalDistance;
}