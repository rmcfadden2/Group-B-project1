#ifndef LOADCITIES_H
#define LOADCITIES_H

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

#include <QDebug>

using namespace std;


struct Admin{
    QString user;
    QString passkey;
};

struct Purchase {
    string city;
    QString food;
    int quantity;
    double pricePerUnit;
};

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

    City& operator=(const City& other)
    {
        if (this != &other)  // Protect against self-assignment
        {
            name = other.name;
            foods = other.foods;
            distances = other.distances;
        }
        return *this;  // Return current object to allow chaining
    }

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

    const vector<PopularFood>& getFoods() const { return foods; }
    const vector<Distance>& getDistances() const { return distances; }

};

City* findCity(std::vector<City> &cities, const std::string &name);
void loadCities(const std::string &filename, std::vector<City> &cities);
void loadDistances(const std::string &filename, std::vector<City> &cities);
void loadFoods(const std::string &filename, std::vector<City> &cities);
void loadAdmin(const std::string &filename, const std::vector<Admin> &admins);

#endif // LOADCITIES_H
