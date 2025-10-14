#ifndef ADMINUTILITIES_H
#define ADMINUTILITIES_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

struct newCities
{
    string city;
    int distance;
};

// find the distance between two cities
void addCity(string newCity, bool &successful);

void editFoodPrice(string foodItem, double newPrice, bool &successful);

void addFood(string newCity, string foodItem, double newPrice, bool &successful);

void deleteFood(string foodItem, bool &successful);

void deleteCity(string newCity, bool &successful);


#endif // ADMINUTILITIES_H
