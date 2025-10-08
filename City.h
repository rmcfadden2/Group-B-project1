#pragma once

#include "PopularFood.h"
#include "Distance.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <unordered_set>
using namespace std;

class City {
private:
    string name;                    //name of the city
    vector<Distance> distances;     //distance to different destination cities
    vector<PopularFood> foods;      //list of local food and their price

public:
    // constructor
    City(const string& n)           //city constructor
        : name(n) {
    }

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

    // find the city and return the ptr to city
    City* findCity(std::vector<City>& cities, const std::string& name)
    {
        for (auto& c : cities)
        {
            if (c.getName() == name)
            {
                return &c;
            }
        }
        return nullptr; //if not found
    }

    //load all the distance information from input file to database
    void loadDistances(const std::string& filename, std::vector<City>& cities)
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
    void loadFoods(const std::string& filename, std::vector<City>& cities)
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
            }
            catch (...) {
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

    // Helper function to find a City* by name in a vector
    City* getCityPtrByName(const std::vector<City>& cities, const string& name) const
    {
        for (const auto& c : cities)
        {
            if (c.getName() == name)
                return const_cast<City*>(&c);
        }
        return nullptr;
    }

    // Updated getClosestCityName to work with unordered_set<City*>
    string getClosestCityName(const std::vector<City>& allCities, const unordered_set<City*>& prevCities) const
    {
        if (distances.empty()) return "";   // no outgoing links
        const Distance* closest = nullptr;

        for (const auto& d : distances)
        {
            City* destCityPtr = getCityPtrByName(allCities, d.getDestinationName());
            if (destCityPtr && !prevCities.count(destCityPtr))
            {
                if (!closest || d.getdistance() < closest->getdistance())
                {
                    closest = &d;
                }
            }
        }

        return closest ? closest->getDestinationName() : "";
    }

    double getClosestCityDistance() const
    {
        if (distances.empty()) return 0.0;
        double best = distances[0].getdistance();

        for (const auto& d : distances)
        {
            if (d.getdistance() < best)
            {
                best = d.getdistance();
            }
        }

        return best;
    }

    void setName(string newName)
    {
        name = newName;
    }

    double purchaseFoods(City* city)
    {
        string foodOption;
        PopularFood* currentFood;
        double totalSpending = 0;

        city->printFoods();
        cout << endl;
        cout << "Which food would you like to purchase(done to stop)? ";
        getline(cin, foodOption);

        while (foodOption != "done")
        {
            currentFood = findFood(foodOption);

            if (!currentFood)
            {
                cout << "Food not in city.\n";
            }
            else
            {
                cout << "Purchasing: " << currentFood->getName();
                totalSpending += currentFood->getPrice();
            }
            cout << endl << endl;
            cout << "Which food would you like to purchase(done to stop)? ";
            getline(cin, foodOption);
        }
        return totalSpending;
    }

    PopularFood* findFood(string foodName)
    {
        for (int i = 0; i < foods.size(); i++)
        {
            if (foods[i].getName() == foodName) return &foods[i];
        }
        return nullptr;
    }
};

