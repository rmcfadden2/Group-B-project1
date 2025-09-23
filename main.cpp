//implementation for story1
#include "story1.h"

int main()
{
    //initialize the cities
    vector<City> cities;
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


    loadDistances("distance.txt", cities);

    //only output the distance from berlin 
    for (const auto& city : cities) 
    {
        if(city.getName() == "Berlin")//print only distance from Berlin(filter, if want to print all the distance, just remove this if)
        {
            city.printDistances();
            cout << "---------------------------\n";
        }
    }

    loadFoods("foods.txt", cities);

    // Print sample city foods
    for (const auto& c : cities) 
    {
        c.printFoods();
        cout << "---------------------\n";
    }
    
    return 0;

}