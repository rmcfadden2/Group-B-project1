#include "story1.h"

// Distance class implementation
Distance::Distance(const std::string& n, double d) : destinationName(n), distance(d) {}
std::string Distance::getDestinationName() const { return destinationName; }
double Distance::getdistance() const { return distance; }