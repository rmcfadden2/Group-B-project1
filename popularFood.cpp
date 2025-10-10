#include "story1.h"

// PopularFood class implementation
PopularFood::PopularFood(const std::string& n, double p) : name(n), price(p) {}
std::string PopularFood::getName() const { return name; }
double PopularFood::getPrice() const { return price; }
// New Admin Setter
void PopularFood::setPrice(double newPrice) {
    price = newPrice;
}
