#include "loadCities.h"

void loadAdmin(const std::string &filename, const std::vector<Admin> &admins)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Cannot open " << filename << "\n";
        return;
    }

    string line;
    getline(file, line); // skip the header

    while (std::getline(file, line))
    {
        stringstream stream(line);
        string username, password;

        getline(stream, username, ',');
        getline(stream, password);
        qDebug() << username << password;
    }

    file.close();
}


City* findCity(std::vector<City> &cities, const std::string &name)
{
    for (auto &c : cities)
    {
        if (c.getName() == name)
        {
            return &c;
        }
    }
    return nullptr; //if not found
}

void loadCities(const std::string &filename, std::vector<City> &cities)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Cannot open " << filename << "\n";
        return;
    }

    string line;
    getline(file, line); // skip the header

    while (std::getline(file, line))
    {
        stringstream stream(line);
        string startCity;

        getline(stream, startCity, ',');
        if(findCity(cities, startCity))
        {
            continue;
        }
        else
        {
            cities.push_back(startCity);
        }
    }

    file.close();

    for(auto &c : cities)
    {
        qDebug() << c.getName();
    }
}

//load all the distance information from input file to database
void loadDistances(const std::string &filename, std::vector<City> &cities)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Cannot open " << filename << "\n";
        return;
    }

    string line;
    getline(file, line); // skip the header

    while (std::getline(file, line))
    {
        stringstream stream(line);
        string startCity, endCity, distStr;

        getline(stream, startCity, ',');
        getline(stream, endCity, ',');
        getline(stream, distStr, ',');

        double dist = 0.0;
        try
        {
            dist = stod(distStr);
        }
        catch (...)
        {
            std::cerr << "Invalid distance: " << distStr << "\n";
            continue;
        }

        // find the start city
        City* start = findCity(cities, startCity);
        if (start)
        {
            start->addDistance(Distance(endCity, dist));
        }
        else
        {
            std::cerr << "Start city not found: " << startCity << "\n";
        }
    }

    file.close();
}

// load all the food information from input file to database
void loadFoods(const std::string &filename, std::vector<City> &cities)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cerr << "Error: Cannot open " << filename << "\n";
        return;
    }

    string line;
    getline(file, line); // skip the header row (City,Traditional Food Item,Cost...)

    string currentCity;

    while (getline(file, line))
    {
        if (line.empty()) continue;

        stringstream stream(line);
        string firstCol, foodName, costStr;

        // first column may be city name OR empty
        getline(stream, firstCol, ',');
        getline(stream, foodName, ',');
        getline(stream, costStr, ',');

        // If this row defines a new city, update currentCity
        if (!firstCol.empty())
        {
            currentCity = firstCol;
            continue;  // next lines will contain food for this city
        }

        // If we don't have a city context, skip
        if (currentCity.empty() || foodName.empty())
        {
            continue;
        }

        // Trim $ and spaces
        if (!costStr.empty())
        {
            costStr.erase(remove(costStr.begin(), costStr.end(), '$'), costStr.end());
            costStr.erase(remove_if(costStr.begin(), costStr.end(), ::isspace), costStr.end());
        }

        double price = 0.0;
        try {
            if (!costStr.empty())
                price = stod(costStr);
        } catch (...) {
            cerr << "Invalid price for food " << foodName << ": " << costStr << "\n";
            continue;
        }

        // Find the city object and add the food
        City* c = findCity(cities, currentCity);
        if (c)
        {
            c->addFood(PopularFood(foodName, price));
        }
        else
        {
            cerr << "City not found: " << currentCity << "\n";
        }
    }

    file.close();
}
