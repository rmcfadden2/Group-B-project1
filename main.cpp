#include "Distance.h"
#include "PopularFood.h"
#include "City.h"

#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
using namespace std;

int main()
{
	const string STARTING_CITY = "London";
	const string DISTANCE_FILE = "distances.txt";
	const string FOOD_FILE = "Foods.txt";

	int numberOfCities;
	double totalDistanceTraveled;
	double totalSpent;
	string nextCityName;
	unordered_set<City*> vistedCities;
	vector<City> cities = {
		City("London"), City("Amsterdam"), City("Berlin"),
		City("Brussels"), City("Budapest"), City("Hamburg"),
		City("Lisbon"), City("Madrid"), City("Paris"),
		City("Prague"), City("Rome"), City("Stockholm"),
		City("Vienna")
	};

	City loader("loader");
	loader.loadDistances(DISTANCE_FILE, cities);
	loader.loadFoods(FOOD_FILE, cities);

	cout << "Please enter number of cities you wish to visit, starting at";
	cout << " London: ";
	cin >> numberOfCities;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	City* currentCity = cities[0].findCity(cities, "London");
	vistedCities.insert(currentCity);

	totalDistanceTraveled = 0;
	totalSpent = 0;
	for (int i = 0; i < numberOfCities; i++)
	{
		cout << "Wecome to " << currentCity->getName() << "!\n\n";

		totalSpent += currentCity->purchaseFoods(currentCity);

		cout << endl;

		nextCityName = currentCity->getClosestCityName(cities, vistedCities);
		totalDistanceTraveled += currentCity->getClosestCityDistance();
		
		currentCity = currentCity->findCity(cities, nextCityName);
		vistedCities.insert(currentCity);
	}
	cout << setprecision(2) << fixed;
	cout << "Total spent on food: $" << totalSpent << endl;
	cout << "Total distance traveled: " << totalDistanceTraveled << endl;
	cout << setprecision(6);
	cout.unsetf(ios::fixed);

	return 0;
}