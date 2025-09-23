#ifndef USERANDFOOD_H
#define USERANDFOOD_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;


class foodPurchased
{
public:
    string getFood();
    string getLocation();
    int getAmount();

    void setFood(string);
    void setLocation(string);
    void addAmount(int);
private:
    string food;
    string location;
    int amount;
};

string foodPurchased::getFood()
{
    return food;
}

string foodPurchased::getLocation()
{
    return location;
}

int foodPurchased::getAmount()
{
    return amount;
}

void foodPurchased::setFood(string input)
{
    food = input;
}

void foodPurchased::setLocation(string input)
{
    location = input;
}

void foodPurchased::addAmount(int input)
{
    amount += input;
}
/***********************End of foodPurchased class*********************************/

class User
{
public:
    double getTotal();
    void addTotal(double);

    string getPurchasedFood(string);
    void setPurchasedFood(string, string, int);

private:
    double totalPrice;
    vector<foodPurchased> purchasedFood;

};

double User::getTotal()
{
    return totalPrice;
}

void User::addTotal(double input)
{
    totalPrice += input;
}

string User::getPurchasedFood(string location)
{
    for(int i = 0; i < purchasedFood.size(); i++)
    {
        if(location == purchasedFood[i].getLocation())
        {
            return purchasedFood[i].getFood();
        }
    }
}



#endif // USERANDFOOD_H
