#include "guestwplanned1.h"
#include "ui_guestwplanned1.h"

#include "guestmainwindow.h"
#include "pariswindow1.h"
#include "londonwindow1.h"
#include "loadCities.h"

guestWplanned1::guestWplanned1(vector<City> &cities, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::guestWplanned1), citiesData(cities), startCity("Paris")
{
    ui->setupUi(this);
}

guestWplanned1::~guestWplanned1()
{
    delete ui;
}

void guestWplanned1::on_backButton_clicked()
{
    guestMainWindow *window = new guestMainWindow;

    window->setGeometry(this->geometry());

    window->show();
    this->close();
}


void guestWplanned1::on_parisButton_clicked()
{
    vector<City> trip;
    for(auto city : citiesData)
    {
        for(auto c : initialElevenCities)
        {
            if(city.getName() == c)
            {
                trip.push_back(city);
                if(city.getName() == "Paris")
                    startCity = city;
            }
        }
    }

    parisWindow1 *window = new parisWindow1(startCity, trip);

    window->setGeometry(this->geometry());

    window->show();
    this->close();
}


void guestWplanned1::on_londonButton_clicked()
{
    for(auto city : citiesData)
    {
        if(city.getName() == "London")
            startCity = city;
    }

    londonWindow1 *window = new londonWindow1(startCity, citiesData);

    window->setGeometry(this->geometry());

    window->show();
    this->close();
}

