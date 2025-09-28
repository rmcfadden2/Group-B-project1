#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

// find the distance between two cities
int cityDistance(string city1, string city2)
{
	string fileCity1 = "";
	string fileCity2 = "";

	// Open the CSV file
	ifstream file("Distances.csv");
	string line;

	// Error if file could not be opened
	if (!file.is_open()) {
		cout << "Error: Could not open Distances.csv" << endl;
		return 0;  // exit function early
	}

	// Read one line at a time in file
	while (getline(file, line))
	{
		stringstream ss(line);
		string cell;

		//cout << "cheese" << line << endl;

		// get first city
		if (getline(ss, cell, ',')) {
			fileCity1 = cell;
		}

		// get second city
		if (getline(ss, cell, ',')) {
			fileCity2 = cell;
		}

		// check if first and second city matches
		if (city1 == fileCity1 && city2 == fileCity2)
		{

			// get distance
			if (getline(ss, cell, ',')) {
				return stoi(cell);
			}


		}
	}

	// return -1 if two cities don't match
	return -1;
}

// function that gets total distance of cities in vector
int totalDistance(const vector<string>& vCities)
{
	int totalDist = 0;

	for (int i = 0; i < vCities.size() - 1; i++) {

		// sum the distances 
		totalDist = cityDistance(vCities[i], vCities[i + 1]) + totalDist;
		cout << vCities[i] << " + " << vCities[i + 1] << " = " << totalDist << endl;
	}
	return 0;
}

int main()
{
	// declare vector that holds cities in order of when they are visited
	vector<string> vCities;

	//cout << "\n\nTHIS IS THE DISTANCE: " << cityDistance("Amsterdam", "Berlin");

	//get 13 cities including Berlin
	vCities.push_back("Berlin");
	vCities.push_back("Amsterdam");
	vCities.push_back("Brussels");
	vCities.push_back("Budapest");
	vCities.push_back("Hamburg");
	vCities.push_back("Lisbon");
	vCities.push_back("London");
	vCities.push_back("Madrid");
	vCities.push_back("Paris");
	vCities.push_back("Prague");
	vCities.push_back("Rome");
	/*vCities.push_back("Amsterdam");
	vCities.push_back("Amsterdam");*/

	totalDistance(vCities);

	// have option to buy foods


	return 0;
}