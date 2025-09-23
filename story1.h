#pragma once STORY1_H

#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <fstream>
#include <sstream>

using namespace std;

//Distance class(should be stored in a city, which should be the start point)
class Distance {
private:
    string destinationName; //the destination city name
    double distance;        //the distance between start point and detination

public:
    Distance(const std::string& n, double d) : destinationName(n), distance(d) {}   //distance constructor

    //Getter
    string getDestinationName() const { return destinationName; }
    double getdistance() const { return distance; }
};

//PopularFood Class
class PopularFood {
private:
    string name;    //name of each popular food
    double price;   //price of the food

public:
    PopularFood(const std::string& n, double p) : name(n), price(p) {}  //PopularFood constructor

    //Getter
    string getName() const { return name; }
    double getPrice() const { return price; }
};

//City class
class City {
private:
    string name;                    //name of the city
    vector<Distance> distances;     //distance to different destination cities
    vector<PopularFood> foods;      //list of local food and their price

public:
    // constructor
    City(const string& n)           //city constructor
        : name(n){}

    // Getter
    string getName() const { return name; }

    //adder
    //add food to city
    void addFood(const PopularFood& food) 
    {
        foods.push_back(food);
    }

    //add distance to certain destination to city
    void addDistance(const Distance& distance) 
    {
        distances.push_back(distance);
    }

    //print distance function
    void printDistances() const 
    {
        cout << "Distances from " << name << ":\n";
        if (distances.empty()) 
        {
            cout << "  No distances recorded.\n";
            return;
        }
        for (const auto& d : distances) 
        {
            cout << "  to  " << d.getDestinationName()
                      << ": " << d.getdistance() << " km\n";
        }
    }

    //print food function
    void printFoods() const 
    {
        cout << "Foods in " << name << ":\n";
        if (foods.empty()) 
        {
            cout << "  No foods recorded.\n";
            return;
        }
        for (const auto& f : foods) 
        {
            cout << "  " << f.getName() << " - $" << f.getPrice() << "\n";
        }
    }

};

// find the city and return the ptr to city
City* findCity(std::vector<City> &cities, const std::string &name) 
{
    for (auto &c : cities) 
    {
        if (c.getName() == name) 
        {
            return &c;
        }
    }
    return nullptr; //if not found
}

//load all the distance information from input file to database
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

// load all the food information from input file to database
void loadFoods(const std::string &filename, std::vector<City> &cities) 
{
    ifstream file(filename);
    if (!file.is_open()) 
    {
        cerr << "Error: Cannot open " << filename << "\n";
        return;
    }

    string line;
    getline(file, line); // skip the header row (City,Traditional Food Item,Cost...)

    string currentCity;

    while (getline(file, line)) 
    {
        if (line.empty()) continue;

        stringstream stream(line);
        string firstCol, foodName, costStr;

        // first column may be city name OR empty
        getline(stream, firstCol, ',');
        getline(stream, foodName, ',');
        getline(stream, costStr, ',');

        // If this row defines a new city, update currentCity
        if (!firstCol.empty()) 
        {
            currentCity = firstCol;
            continue;  // next lines will contain food for this city
        }

        // If we don't have a city context, skip
        if (currentCity.empty() || foodName.empty()) 
        {
            continue;
        }

        // Trim $ and spaces
        if (!costStr.empty()) 
        {
            costStr.erase(remove(costStr.begin(), costStr.end(), '$'), costStr.end());
            costStr.erase(remove_if(costStr.begin(), costStr.end(), ::isspace), costStr.end());
        }

        double price = 0.0;
        try {
            if (!costStr.empty())
                price = stod(costStr);
        } catch (...) {
            cerr << "Invalid price for food " << foodName << ": " << costStr << "\n";
            continue;
        }

        // Find the city object and add the food
        City* c = findCity(cities, currentCity);
        if (c) 
        {
            c->addFood(PopularFood(foodName, price));
        } 
        else 
        {
            cerr << "City not found: " << currentCity << "\n";
        }
    }

    file.close();
}
