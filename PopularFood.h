#pragma once

#include <string>
using namespace std;

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
