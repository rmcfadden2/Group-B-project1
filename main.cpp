#include "story1.h"
#include <iostream>
#include <vector>

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
    // Ensure "distance.txt" is in the correct directory.
    loadDistances("distance.txt", cities);

    // Display all available cities so the user can choose a starting point.
    displaySelectableCities(cities);

    // Prompt the user to select a starting city and get a pointer to it.
    City* startingCity = selectCity(cities);

    // If a valid city was selected, proceed with trip planning.
    if (startingCity) {
        std::cout << "\nPlanning a trip starting from " << startingCity->getName() << "...\n";

        // Create the most efficient route by recursively finding the closest city.
        std::vector<std::string> plannedRoute = findClosestRoute(startingCity->getName(), cities);

        // Display the final planned route to the user.
        displayRoute(plannedRoute);

        // Calculate and display the total travel distance for the entire route.
        double totalDistance = calculateTotalDistance(plannedRoute, cities);
        std::cout << "\nTotal distance for your trip: " << totalDistance << " km.\n";
    } else {
        std::cout << "Invalid city selection. The program will now exit.\n";
    }

    return 0;
}