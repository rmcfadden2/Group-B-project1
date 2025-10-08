#pragma once

#include <string>
using namespace std;

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
