#pragma once STORY1_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;

class Distance {
private:
    string destinationName;
    double distance;

public:
    Distance(const std::string& n, double d) : destinationName(n), distance(d) {}

    string getDestinationName() const { return destinationName; }
    double getdistance() const { return distance; }
};

class PopularFood {
private:
    string name;
    double price;

public:
    PopularFood(const std::string& n, double p) : name(n), price(p) {}

    string getName() const { return name; }
    double getPrice() const { return price; }
};

class City {
private:
    string name;
    vector<Distance> distances;
    vector<PopularFood> foods;

public:
    // constructor
    City(const string& n, double lat, double lon)
        : name(n){}

    // Getter
    std::string getName() const { return name; }

    void addFood(const PopularFood& food) 
    {
        foods.push_back(food);
    }
    void addDistance(const Distance& distance) 
    {
        distances.push_back(distance);
    }
};

// find the city and return the ptr to city
City* findCity(std::vector<City> &cities, const std::string &name) 
{
    for (auto &c : cities) {
        if (c.getName() == name) {
            return &c;
        }
    }
    return nullptr; //if not found
}


void loadDistances(const std::string &filename, std::vector<City> &cities) 
{
    ifstream file(filename);
    if (!file.is_open()) 
    {
        cerr << "Error: Cannot open " << filename << "\n";
        return;
    }

    string line;
    getline(file, line); // skip the header

    while (std::getline(file, line)) 
    {
        stringstream stream(line);
        string startCity, endCity, distStr;

        getline(stream, startCity, ',');
        getline(stream, endCity, ',');
        getline(stream, distStr, ',');

        double dist = 0.0;
        try 
        {
            dist = stod(distStr);
        } 
        catch (...) 
        {
            std::cerr << "Invalid distance: " << distStr << "\n";
            continue;
        }

        // find the start city
        City* start = findCity(cities, startCity);
        if (start) 
        {
            start->addDistance(Distance(endCity, dist));
        } 
        else 
        {
            std::cerr << "Start city not found: " << startCity << "\n";
        }
    }

    file.close();
}

