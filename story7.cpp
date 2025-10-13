#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

struct newCities
{
    string city;
    int distance;
};

// find the distance between two cities
void addCity(string newCity)
{
    // Open the CSV files
    // existing data
    ifstream inputFile("new_cities.csv");

    // new data
    ofstream outputFile("distances.csv", ios::app);
    string line;

    // Error if file could not be opened
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error: Could not open new_cities.csv" << endl;
        return;  // exit function early
    }

    // Read one line at a time in file
    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string cell;

        // get first city
        if (getline(ss, cell, ','))
        {
            if (newCity == cell)
            {
                // write whole line into file
                outputFile << line << endl;
                cout << line << endl;
            }
        }
    }

    // close files
    inputFile.close();
    outputFile.close();

    return;
}

void editFoodPrice(string foodItem, double newPrice)
{
    ifstream inputFile("foods.csv");
    ofstream tempFile("temp.csv");

    if (!inputFile.is_open() || !tempFile.is_open()) {
        cerr << "Error: Could not open files!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string city, food, price;

        getline(ss, city, ',');
        getline(ss, food, ',');
        getline(ss, price, ',');

        // If this line defines a new city
        if (food != foodItem)
        {
            tempFile << line << endl;
        }
        // If this is a food line
        else
        {
            tempFile << "," << food << ",$" << newPrice << endl;
            found = true;
        }
    }

    inputFile.close();
    tempFile.close();

    remove("foods.csv");
    rename("temp.csv", "foods.csv");

    if (found)
        cout << "Updated all food prices in " << foodItem << " to $" << newPrice << endl;
    else
        cout << "Could not find " << foodItem << " in the file." << endl;

}

void addFood(string newCity, string foodItem, double newPrice)
{
    ifstream inputFile("foods.csv");
    ofstream tempFile("temp.csv");

    if (!inputFile.is_open() || !tempFile.is_open()) {
        cerr << "Error: Could not open files!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string city, food, price;

        getline(ss, city, ',');
        getline(ss, food, ',');
        getline(ss, price, ',');

        // print line to tempFile
        tempFile << line << endl;

        if (city == newCity)
        {
            // city matches
            //print header of city
            tempFile << "," << foodItem << ",$" << newPrice << endl;
            found = true;
        }


    }

    inputFile.close();
    tempFile.close();

    remove("foods.csv");
    rename("temp.csv", "foods.csv");

    if (found)
        cout << "added " << foodItem << " to " << newCity << " for $" << newPrice << endl;
    else
        cout << "Could not find " << newCity << " in the file." << endl;

}

void deleteFood(string foodItem)
{
    ifstream inputFile("foods.csv");
    ofstream tempFile("temp.csv");

    if (!inputFile.is_open() || !tempFile.is_open()) {
        cerr << "Error: Could not open files!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string city, food, price;

        getline(ss, city, ',');
        getline(ss, food, ',');
        getline(ss, price, ',');

        // If this line defines a new city
        if (food != foodItem)
        {
            tempFile << line << endl;
        }
        // If this is a food line
        else
        {
            found = true;
        }
    }

    inputFile.close();
    tempFile.close();

    remove("foods.csv");
    rename("temp.csv", "foods.csv");

    if (found)
        cout << "deleted " << foodItem << endl;
    else
        cout << "Could not find " << foodItem << " in the file." << endl;

}


int main()
{
    //addCity("Vienna");

    //editFoodPrice("Pretzels", 10.01);

    //deleteFood("Pretzels");

    addFood("Berlin", "Cheese", 6.70);

    return 0;
}