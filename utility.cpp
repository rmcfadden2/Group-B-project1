#include "story1.h"
#include <fstream>
#include <sstream>
#include <algorithm>
#include <cctype>

const std::string ADMIN_USERNAME = "admin";
const std::string ADMIN_PASSWORD = "password123";

City* findCity(std::vector<City>& cities, const std::string& name) {
    for (auto& c : cities) {
        if (c.getName() == name) {
            return &c;
        }
    }
    return nullptr;
}

void loadDistances(const std::string& filename, std::vector<City>& cities) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open " << filename << "\n";
        return;
    }
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line)) {
        std::stringstream stream(line);
        std::string startCity, endCity, distStr;
        std::getline(stream, startCity, ',');
        std::getline(stream, endCity, ',');
        std::getline(stream, distStr, ',');
        double dist = 0.0;
        try {
            dist = std::stod(distStr);
        } catch (...) {
            std::cerr << "Invalid distance: " << distStr << "\n";
            continue;
        }
        City* start = findCity(cities, startCity);
        if (start) {
            start->addDistance(Distance(endCity, dist));
        } else {
            std::cerr << "Start city not found: " << startCity << "\n";
        }
    }
    file.close();
}

void loadFoods(const std::string& filename, std::vector<City>& cities) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Cannot open " << filename << "\n";
        return;
    }
    std::string line;
    std::getline(file, line);
    std::string currentCity;
    while (std::getline(file, line)) {
        if (line.empty()) continue;
        std::stringstream stream(line);
        std::string firstCol, foodName, costStr;
        std::getline(stream, firstCol, ',');
        std::getline(stream, foodName, ',');
        std::getline(stream, costStr, ',');
        if (!firstCol.empty()) {
            currentCity = firstCol;
        }
        if (currentCity.empty() || foodName.empty()) {
            continue;
        }
        if (!costStr.empty()) {
            costStr.erase(std::remove(costStr.begin(), costStr.end(), '$'), costStr.end());
            costStr.erase(std::remove_if(costStr.begin(), costStr.end(), ::isspace), costStr.end());
        }
        double price = 0.0;
        try {
            if (!costStr.empty())
                price = std::stod(costStr);
        } catch (...) {
            std::cerr << "Invalid price for food " << foodName << ": " << costStr << "\n";
            continue;
        }
        City* c = findCity(cities, currentCity);
        if (c) {
            c->addFood(PopularFood(foodName, price));
        } else {
            std::cerr << "City not found: " << currentCity << "\n";
        }
    }
    file.close();
}

void displaySelectableCities(const std::vector<City>& cities) {
    std::cout << "\nAvailable Cities:\n";
    for (size_t i = 0; i < cities.size(); ++i) {
        std::cout << i + 1 << ". " << cities[i].getName() << "\n";
    }
}

City* selectCity(const std::vector<City>& cities) {
    int choice;
    while (true) {
        std::cout << "Enter the number of your starting city: ";
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > cities.size()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid selection. Please try again.\n";
        } else {
            std::cin.ignore(10000, '\n');
            return findCity(const_cast<std::vector<City>&>(cities), cities[choice - 1].getName());
        }
    }
}

std::string findNextClosest(const std::string& currentCityName, const std::vector<City>& allCities, const std::vector<std::string>& visitedCities) {
    const City* currentCity = findCity(const_cast<std::vector<City>&>(allCities), currentCityName);
    if (!currentCity) return "";
    double minDistance = -1.0;
    std::string closestCityName = "";
    for (const auto& dist : currentCity->getDistances()) {
        bool alreadyVisited = false;
        for (const auto& visited : visitedCities) {
            if (visited == dist.getDestinationName()) {
                alreadyVisited = true;
                break;
            }
        }
        if (!alreadyVisited) {
            if (minDistance == -1.0 || dist.getdistance() < minDistance) {
                minDistance = dist.getdistance();
                closestCityName = dist.getDestinationName();
            }
        }
    }
    return closestCityName;
}

std::vector<std::string> findClosestRoute(const std::string& startCityName, std::vector<City>& allCities) {
    std::vector<std::string> route;
    std::string currentCity = startCityName;
    while (!currentCity.empty()) {
        route.push_back(currentCity);
        std::string nextCity = findNextClosest(currentCity, allCities, route);
        currentCity = nextCity;
    }
    return route;
}

void displayRoute(const std::vector<std::string>& route) {
    std::cout << "\nYour planned route:\n";
    for (size_t i = 0; i < route.size(); ++i) {
        std::cout << i + 1 << ". " << route[i];
        if (i < route.size() - 1) {
            std::cout << " -> ";
        }
    }
    std::cout << "\n";
}

double calculateTotalDistance(const std::vector<std::string>& route, const std::vector<City>& allCities) {
    if (route.size() < 2) return 0.0;
    double totalDistance = 0.0;
    for (size_t i = 0; i < route.size() - 1; ++i) {
        const std::string& startName = route[i];
        const std::string& endName = route[i+1];
        City* startCity = findCity(const_cast<std::vector<City>&>(allCities), startName);
        if (startCity) {
            for (const auto& dist : startCity->getDistances()) {
                if (dist.getDestinationName() == endName) {
                    totalDistance += dist.getdistance();
                    break;
                }
            }
        }
    }
    return totalDistance;
}
/**
 * @brief Prompts user for admin credentials and checks against constants.
 * @return true if credentials are correct, false otherwise.
 */
bool adminLogin() {
    std::string user, pass;
    std::cout << "\n--- Admin Login ---\n";
    std::cout << "Enter Username: ";
    std::cin >> user;
    std::cout << "Enter Password: ";
    std::cin >> pass;
    std::cin.ignore(10000, '\n'); // Clear buffer

    // Verify the user inputs the admin user and password is correct and let the user view the admin view, and if incorrect deny access
    if (user == ADMIN_USERNAME && pass == ADMIN_PASSWORD) {
        std::cout << "\nLogin Successful. Welcome, Administrator.\n";
        return true;
    } else {
        std::cout << "\nLogin Failed. Invalid username or password.\n";
        return false; // If the password is wrong, deny access to the user
    }
}

// ---------------------- City Maintenance ----------------------

/**
 * @brief Admin can add new cities
 */
void adminAddCity(std::vector<City>& cities) {
    std::string newCityName;
    std::cout << "\n--- Add New City ---\n";
    std::cout << "Enter the name of the new city: ";
    std::getline(std::cin, newCityName);

    if (findCity(cities, newCityName)) {
        std::cout << "Error: City '" << newCityName << "' already exists.\n";
        return;
    }

    cities.emplace_back(newCityName);
    std::cout << "City '" << newCityName << "' added successfully!\n";
}

// ---------------------- Food Maintenance ----------------------

/**
 * @brief Admin can edit any food prices in specific cities
 */
void adminEditFoodPrice(City* city) {
    city->printFoods();
    std::string foodName;
    double newPrice;
    std::cout << "Enter name of food to edit price for: ";
    std::getline(std::cin, foodName);

    PopularFood* food = city->findFood(foodName);
    if (!food) {
        std::cout << "Food '" << foodName << "' not found in " << city->getName() << ".\n";
        return;
    }

    std::cout << "Enter new price for " << food->getName() << " (Current: $" << food->getPrice() << "): $";
    std::cin >> newPrice;
    if (std::cin.fail() || newPrice < 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid price. Operation aborted.\n";
        return;
    }
    std::cin.ignore(10000, '\n');

    food->setPrice(newPrice);
    std::cout << "Price for " << food->getName() << " updated successfully to $" << newPrice << ".\n";
}

/**
 * @brief Admin can add new foods to specific cities
 */
void adminAddFoodToCity(City* city) {
    std::string foodName;
    double price;
    std::cout << "\n--- Add New Food to " << city->getName() << " ---\n";
    std::cout << "Enter new food name: ";
    std::getline(std::cin, foodName);

    if (city->findFood(foodName)) {
        std::cout << "Food '" << foodName << "' already exists in this city.\n";
        return;
    }

    std::cout << "Enter price: $";
    std::cin >> price;
    if (std::cin.fail() || price < 0) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        std::cout << "Invalid price. Operation aborted.\n";
        return;
    }
    std::cin.ignore(10000, '\n');

    city->addFood(PopularFood(foodName, price));
    std::cout << "Food '" << foodName << "' added to " << city->getName() << " successfully!\n";
}

/**
 * @brief Admin can delete foods from specific cities
 */
void adminDeleteFoodFromCity(City* city) {
    city->printFoods();
    std::string foodName;
    std::cout << "Enter name of food to DELETE: ";
    std::getline(std::cin, foodName);

    if (city->deleteFood(foodName)) {
        std::cout << "Food '" << foodName << "' deleted from " << city->getName() << ".\n";
    } else {
        std::cout << "Food '" << foodName << "' not found in " << city->getName() << ".\n";
    }
}

/**
 * @brief Food maintenance submenu, allows selecting a city first.
 */
void adminFoodMaintenance(std::vector<City>& cities) {
    City* city = selectCity(cities);
    if (!city) {
        std::cout << "City selection failed.\n";
        return;
    }

    int choice;
    do {
        std::cout << "\n--- Food Maintenance for " << city->getName() << " ---\n";
        std::cout << "1. Edit Food Price\n";
        std::cout << "2. Add New Food\n";
        std::cout << "3. Delete Food\n";
        std::cout << "4. Back to Main Admin Menu\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            choice = 0; // Force retry
        } else {
            std::cin.ignore(10000, '\n');
        }

        switch (choice) {
            case 1: adminEditFoodPrice(city); break;
            case 2: adminAddFoodToCity(city); break;
            case 3: adminDeleteFoodFromCity(city); break;
            case 4: std::cout << "Returning...\n"; break;
            default: std::cout << "Invalid choice. Please try again.\n"; break;
        }
    } while (choice != 4);
}

/**
 * @brief Main Admin View, accessible after successful login.
 */
void adminMenu(std::vector<City>& cities) {
    int choice;
    do {
        std::cout << "\n--- Administrator View ---\n";
        std::cout << "1. Add New City\n";
        std::cout << "2. Maintain Food Database (Add/Edit/Delete Food & Price)\n";
        std::cout << "3. Logout\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            choice = 0; // Force retry
        } else {
            std::cin.ignore(10000, '\n');
        }

        switch (choice) {
            case 1: adminAddCity(cities); break;
            case 2: adminFoodMaintenance(cities); break;
            case 3: std::cout << "Logging out...\n"; break;
            default: std::cout << "Invalid choice. Please try again.\n"; break;
        }
    } while (choice != 3);
}
