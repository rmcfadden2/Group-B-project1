#include "story1.h"
#include <iostream>

City::City(const std::string& n) : name(n) {}
std::string City::getName() const { return name; }

void City::addFood(const PopularFood& food) {
    foods.push_back(food);
}

void City::addDistance(const Distance& distance) {
    distances.push_back(distance);
}

void City::printDistances() const {
    std::cout << "Distances from " << name << ":\n";
    if (distances.empty()) {
        std::cout << "  No distances recorded.\n";
        return;
    }
    for (const auto& d : distances) {
        std::cout << "  to  " << d.getDestinationName()
            << ": " << d.getdistance() << " km\n";
    }
}

void City::printFoods() const {
    std::cout << "Foods in " << name << ":\n";
    if (foods.empty()) {
        std::cout << "  No foods recorded.\n";
        return;
    }
    for (const auto& f : foods) {
        std::cout << "  " << f.getName() << " - $" << f.getPrice() << "\n";
    }
}

const std::vector<Distance>& City::getDistances() const {
    return distances;
}

PopularFood* City::findFood(const std::string& foodName) {
    for (auto& f : foods) {
        if (f.getName() == foodName) {
            return &f;
        }
    }
    return nullptr;
}

// Function to delete a food item
bool City::deleteFood(const std::string& foodName) {
    auto it = std::remove_if(foods.begin(), foods.end(),
        [&foodName](const PopularFood& f) { return f.getName() == foodName; });

    if (it != foods.end()) {
        foods.erase(it, foods.end());
        return true; // Food found and deleted
    }
    return false; // Food not found
}
