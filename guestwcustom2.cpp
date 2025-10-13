#include "guestwcustom2.h"
#include "ui_guestwcustom2.h"
#include "confirmselectedcities.h"
#include "guestwcustom1.h"

using namespace std;

guestWcustom2::guestWcustom2(City startcity, vector<City> &citylist, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::guestWcustom2), cities(citylist), startingCity(startcity)
{
    ui->setupUi(this);

    populateCityButtons();
}

guestWcustom2::~guestWcustom2()
{
    delete ui;
}

void guestWcustom2::populateCityButtons()
{
    // Get or create layout for the scroll area/widget
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->citiesWidget->layout());
    if (!layout) {
        layout = new QVBoxLayout(ui->citiesWidget);
        ui->citiesWidget->setLayout(layout);
    }

    // Clear existing buttons if needed
    qDeleteAll(ui->citiesWidget->findChildren<QPushButton*>());
    cityButtons.clear();

    // Create new city buttons
    for (const auto &city : cities) {
        if(city.getName() != startingCity.getName())
        {
            QPushButton *btn = new QPushButton(QString::fromStdString(city.getName()), this);
            btn->setCheckable(true);
            layout->addWidget(btn);

            connect(btn, &QPushButton::toggled, [&city, btn](bool checked) {
                if (checked)
                    btn->setStyleSheet("background-color: white;");
                else
                    btn->setStyleSheet("");

                qDebug() << "Clicked city:" << QString::fromStdString(city.getName())
                         << "with" << city.getFoods().size() << "foods";
            });

            cityButtons.push_back(btn);
        }
    }
}

void guestWcustom2::on_nextButton_clicked()
{
    // Clear previous selections
    selectedCities.clear();

    selectedCities.push_back(startingCity);

    // Add all other checked cities (as full City objects)
    for (auto *btn : cityButtons) {
        if (btn->isChecked()) {
            std::string cityName = btn->text().toStdString();

            auto cityIt = std::find_if(cities.begin(), cities.end(),
                                       [&](const City &c) { return c.getName() == cityName; });

            if (cityIt != cities.end()) {
                selectedCities.push_back(*cityIt);
                qDebug() << "Added city:" << QString::fromStdString(cityIt->getName())
                         << "with" << cityIt->getFoods().size() << "foods";
            } else {
                qDebug() << "Warning: City not found for" << QString::fromStdString(cityName);
            }
        }
    }

    // ✅ Now selectedCities is a vector<City> with full food lists
    confirmSelectedCities *confirm = new confirmSelectedCities(startingCity, selectedCities, this);
    confirm->show();
}



void guestWcustom2::on_backButton_clicked()
{
    guestWcustom1 *window = new guestWcustom1(cities);

    window->setGeometry(this->geometry());

    window->show();
    this->close();
}

