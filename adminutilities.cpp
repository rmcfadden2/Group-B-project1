#include "adminutilities.h"
#include "loadCities.h"

void addCity(string newCity, bool &successful)
{
    vector<City> cities;

    loadCities("distances.txt", cities);

    // Open the CSV files
    // existing data
    ifstream inputFile("new_cities.txt");

    // new data
    ofstream outputFile("distances.txt", ios::app);
    string line;

    // bool to check if city was successfully added
    bool cityAdded = false;

    // Error if file could not be opened
    if (!inputFile.is_open() || !outputFile.is_open()) {
        cout << "Error: Could not open new_cities.txt" << endl;
        return;  // exit function early
    }

    // Read one line at a time in file
    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string city1, city2, distance;
        bool dupeFound = false;

        getline(ss, city1, ',');
        getline(ss, city2, ',');
        getline(ss, distance, ',');

        // check if first or second city matches the new city
        if (newCity == city1)
        {
            // open file each time while looping
            // input file for checking for dupes in distances
            ifstream inputFile2("distances.txt");
            string line2;

            while (getline(inputFile2, line2))
            {
                stringstream ss(line2);
                if (line == line2)
                {
                    // test to look for dupes
                    // cout << "dupe found: " << line2 << endl;
                    dupeFound = true;
                }
            }

            //close file after looping
            inputFile2.close();

            // only enter if dupe is not found
            if (dupeFound == false)
            {
                // write whole line into file
                outputFile << line << endl;

                // test to see what was added
                // cout << line << endl;
                cityAdded = true;
            }

        }
        else if(newCity == city2)
        {
            for(auto c : cities)
            {
                if(c.getName() == city1)
                {
                    // open file each time while looping
                    // input file for checking for dupes in distances
                    ifstream inputFile2("distances.txt");
                    string line2;

                    while (getline(inputFile2, line2))
                    {
                        stringstream ss(line2);
                        if (line == line2)
                        {
                            // test to look for dupes
                            // cout << "dupe found: " << line2 << endl;
                            dupeFound = true;
                        }
                    }

                    //close file after looping
                    inputFile2.close();

                    // only enter if dupe is not found
                    if (dupeFound == false)
                    {
                        // write whole line into file
                        outputFile << line << endl;

                        // test to see what was added
                        // cout << line << endl;
                        cityAdded = true;
                    }
                }
            }
        }

    }

    // close files
    inputFile.close();
    outputFile.close();

    if (cityAdded)
    {
        cout << newCity << " was successfully added" << endl;
        successful = true;
    }
    else
    {
        cout << "Could not add " << newCity << endl;
        successful = false;
    }

    return;
}

void deleteCity(string newCity, bool &successful)
{
    ifstream inputFile("distances.txt");
    ofstream tempFile("temp.txt");

    if (!inputFile.is_open() || !tempFile.is_open()) {
        cerr << "Error: Could not open files!" << endl;
        return;
    }

    string line;
    bool found = false;

    while (getline(inputFile, line))
    {
        stringstream ss(line);
        string city1, city2, distance;

        getline(ss, city1, ',');
        getline(ss, city2, ',');
        getline(ss, distance, ',');

        // If this line defines a new city
        if (city1 != newCity && city2 != newCity)
        {
            tempFile << line << endl;
        }
        // If this is a city line
        else
        {
            found = true;
        }
    }

    inputFile.close();
    tempFile.close();

    remove("distances.txt");
    rename("temp.txt", "distances.txt");

    if (found)
    {
        cout << "deleted " << newCity << endl;
        successful = true;
    }
    else
    {
        cout << "Could not find " << newCity << " in the file." << endl;
        successful = false;
    }

}

void editFoodPrice(string foodItem, double newPrice, bool &successful)
{
    ifstream inputFile("foods.txt");
    ofstream tempFile("temp.txt");

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

    remove("foods.txt");
    rename("temp.txt", "foods.txt");

    if (found)
    {
        cout << "Updated all food prices in " << foodItem << " to $" << newPrice << endl;
        successful = true;
    }

    else
    {
        cout << "Could not find " << foodItem << " in the file." << endl;
        successful = false;
    }

}

void addFood(string newCity, string foodItem, double newPrice, bool &successful)
{
    ifstream inputFile("foods.txt");
    ofstream tempFile("temp.txt");

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

    remove("foods.txt");
    rename("temp.txt", "foods.txt");

    if (found)
    {
        cout << "added " << foodItem << " to " << newCity << " for $" << newPrice << endl;
        successful = true;
    }
    else
    {
        cout << "Could not find " << newCity << " in the file." << endl;
        successful = false;
    }
}

void deleteFood(string foodItem, bool &successful)
{
    ifstream inputFile("foods.txt");
    ofstream tempFile("temp.txt");

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

    remove("foods.txt");
    rename("temp.txt", "foods.txt");

    if (found)
    {
        cout << "deleted " << foodItem << endl;
        successful = true;
    }
    else
    {
        cout << "Could not find " << foodItem << " in the file." << endl;
        successful = false;
    }

}
