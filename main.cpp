#include "story1.h"
#include <iostream>
#include <vector>

void userTripPlanning(std::vector<City>& cities) {
    // Existing trip planning logic from main() goes here
    displaySelectableCities(cities);
    City* startingCity = selectCity(cities);

    if (startingCity) {
        std::cout << "\nPlanning a trip starting from " << startingCity->getName() << "...\n";
        std::vector<std::string> plannedRoute = findClosestRoute(startingCity->getName(), cities);
        displayRoute(plannedRoute);
        double totalDistance = calculateTotalDistance(plannedRoute, cities);
        std::cout << "\nTotal distance for your trip: " << totalDistance << " km.\n";
    } else {
        std::cout << "Invalid city selection. Returning to main menu.\n";
    }
}

int main()
{
    // Initialize a list of all European cities.
    std::vector<City> cities;
    cities.emplace_back("Amsterdam");
    cities.emplace_back("Berlin");
    cities.emplace_back("Budapest");
    cities.emplace_back("Brussels");
    cities.emplace_back("Hamburg");
    cities.emplace_back("Lisbon");
    cities.emplace_back("London");
    cities.emplace_back("Madrid");
    cities.emplace_back("Paris");
    cities.emplace_back("Prague");
    cities.emplace_back("Rome");
    cities.emplace_back("Vienna");
    cities.emplace_back("Stockholm");

    // Load distances between cities from the text file.
    loadDistances("distance.txt", cities);

    // Load foods from file (ensure you have a foods.txt or similar)
    loadFoods("foods.txt", cities);

    int choice;
    do {
        std::cout << "\n==================================\n";
        std::cout << "WELCOME TO VACATION PLANNING SYSTEM\n";
        std::cout << "==================================\n";
        std::cout << "1. Plan Your Trip (User View)\n";
        std::cout << "2. Administrator Login\n";
        std::cout << "3. Exit Program\n";
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
            case 1:
                userTripPlanning(cities);
                break;
            case 2:
                if (adminLogin()) { // Prompt a user to input admin password
                    adminMenu(cities); // Only show admin menu if login is successful
                }
                break;
            case 3:
                std::cout << "Exiting program. Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 3);

    return 0;
}
