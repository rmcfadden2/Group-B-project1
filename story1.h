#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#ifndef story1_h
#define story1_h

// Represents the distance to a destination city.
class Distance {
private:
    std::string destinationName;
    double distance;

public:
    Distance(const std::string& n, double d);
    std::string getDestinationName() const;
    double getdistance() const;
};

// Represents a popular food item with its name and price.
class PopularFood {
private:
    std::string name;
    double price;

public:
    PopularFood(const std::string& n, double p);
    std::string getName() const;
    double getPrice() const;
    void setPrice(double newPrice);
};

// Represents a city with its name, distances to other cities, and popular foods.
class City {
private:
    std::string name;
    std::vector<Distance> distances;
    std::vector<PopularFood> foods;

public:
    City(const std::string& n);
    std::string getName() const;
    void addFood(const PopularFood& food);
    void addDistance(const Distance& distance);
    void printDistances() const;
    void printFoods() const;
    const std::vector<Distance>& getDistances() const;
    PopularFood* findFood(const std::string& foodName); // For finding and editing food
    bool deleteFood(const std::string& foodName); // For deleting food
};

// Global Function prototypes for file I/O and trip planning
City* findCity(std::vector<City>& cities, const std::string& name);
void loadDistances(const std::string& filename, std::vector<City>& cities);
void loadFoods(const std::string& filename, std::vector<City>& cities);
void displaySelectableCities(const std::vector<City>& cities);
City* selectCity(const std::vector<City>& cities);
std::vector<std::string> findClosestRoute(const std::string& startCityName, std::vector<City>& allCities);
void displayRoute(const std::vector<std::string>& route);
double calculateTotalDistance(const std::vector<std::string>& route, const std::vector<City>& allCities);

void adminMenu(std::vector<City>& cities);
bool adminLogin();


// City maintenance functions
void adminAddCity(std::vector<City>& cities);

// Food maintenance functions
void adminFoodMaintenance(std::vector<City>& cities);
void adminEditFoodPrice(City* city);
void adminAddFoodToCity(City* city);
void adminDeleteFoodFromCity(City* city);

#endif
