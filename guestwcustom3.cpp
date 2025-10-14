#include "guestwcustom3.h"
#include "ui_guestwcustom3.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>

#include "loadCities.h"
#include "checkoutdialog.h"
#include <vector>
#include <string>
#include <QTimer>

using namespace std;

guestWcustom3::guestWcustom3(City start, vector<City> &data, QWidget *callerWindow, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::guestWcustom3), cities(data), startCity(start), currentCity("empty"), caller(callerWindow)
{
    // Make an explicit local copy immediately
    std::vector<City> localCities = data;

    ui->setupUi(this);

    qDebug() << "Constructor: localCities.size() =" << localCities.size() << " address=" << &localCities;
    if (localCities.size() >= 2) {
        qDebug() << " Constructor: &localCities[0]=" << &localCities[0] << " &localCities[1]=" << &localCities[1];
    }

    // For now use localCities for debugging/population
    // (temporarily call a debug-only populate that only prints)
    qDebug() << "Debug-printing localCities content:";
    for (size_t i = 0; i < localCities.size(); ++i) {
        qDebug() << " City[" << i << "] =" << QString::fromStdString(localCities[i].getName())
        << " foods:" << localCities[i].getFoods().size();
    }

    // assign to member AFTER we've verified local copy (temporary move/copy)
    cities = std::move(localCities);

    // ...rest of ctor (keep existing layout checks etc.)
    if (!ui->citiesWidget->layout())
        ui->citiesWidget->setLayout(new QVBoxLayout(ui->citiesWidget));

    // continue as before
    QTimer::singleShot(0, this, [this]() {
        populateCityButtons();
    });
}

guestWcustom3::~guestWcustom3()
{
    delete ui;
}

// Create scrollable buttons for each city
void guestWcustom3::populateCityButtons()
{
    qDebug() << "populateCityButtons(): cities.size() =" << cities.size() << " address=" << &cities;
    if (cities.size() >= 2) {
        qDebug() << " populate: &cities[0]=" << &cities[0] << " &cities[1]=" << &cities[1];
    }
    qDebug() << "populateCityButtons() starting... total cities:" << cities.size();
    for (size_t i = 0; i < cities.size(); ++i) {
        qDebug() << "  City[" << i << "] =" << QString::fromStdString(cities[i].getName())
        << "foods:" << cities[i].getFoods().size();
    }


    if (!ui->citiesScrollArea) {
        qDebug() << "❌ ui->citiesScrollArea is nullptr!";
        return;
    }

    if (!ui->citiesWidget) {
        qDebug() << "❌ ui->citiesWidget is nullptr!";
        return;
    }

    // Ensure layout exists on citiesWidget
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->citiesWidget->layout());
    if (!layout) {
        layout = new QVBoxLayout(ui->citiesWidget);
        ui->citiesWidget->setLayout(layout);
    }

    // Clear old buttons if any
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    qDebug() << "✅ citiesWidget layout ready. Adding city buttons...";

    for (const auto &city : cities) {
        QString cityName = QString::fromStdString(city.getName());
        QPushButton *cityButton = new QPushButton(cityName, ui->citiesWidget);
        layout->addWidget(cityButton);

        connect(cityButton, &QPushButton::clicked, this, [&city, this]() {
            currentCity = city;
            qDebug() << "Clicked city:" << QString::fromStdString(city.getName())
                     << "with" << city.getFoods().size() << "foods";
            displayFoodsForCity(city);
        });
    }

    layout->addStretch();

    ui->citiesScrollArea->setWidget(ui->citiesWidget);
    ui->citiesScrollArea->setWidgetResizable(true);

    ui->quantitySpinBox->setMinimum(1);
    ui->quantitySpinBox->setMaximum(100);

    qDebug() << "✅ populateCityButtons() completed successfully.";
}


// Display foods for the selected city in QListWidget
void guestWcustom3::displayFoodsForCity(const City &city)
{
    ui->foodListWidget->clear();

    for (const auto &food : city.getFoods())
    {
        QString displayText = QString("%1 - $%2")
        .arg(QString::fromStdString(food.getName()))
            .arg(food.getPrice(), 0, 'f', 2);

        // Create a list item with both display text and hidden data
        QListWidgetItem *item = new QListWidgetItem(displayText);
        item->setData(Qt::UserRole, QString::fromStdString(food.getName())); // store raw name
        ui->foodListWidget->addItem(item);
    }

    ui->foodListWidget->setProperty("currentCity", QString::fromStdString(city.getName()));

    qDebug() << "Added" << city.getFoods().size() << "foods for" << QString::fromStdString(city.getName());
}


void guestWcustom3::on_purchaseButton_clicked()
{
    // Get selected food from the list widget
    QListWidgetItem *selectedItem = ui->foodListWidget->currentItem();
    ui->purchaseWarningLabel->setText("");

    if (!selectedItem) {
        qDebug() << "No food selected!";
        ui->purchaseWarningLabel->setText("No food selected!");
        return;
    }

    QString foodName = selectedItem->data(Qt::UserRole).toString();

    string cityName = currentCity.getName();
    int quantity = ui->quantitySpinBox->value();

    // Find the food in the current city's food list
    double price = 0.0;
    bool found = false;
    for (const auto &food : currentCity.getFoods()) {
        if (QString::fromStdString(food.getName()) == foodName) {
            price = food.getPrice();
            found = true;
            break;
        }
    }

    if (!found) {
        qDebug() << "Error: Food" << foodName << "not found in" << cityName;
        return;
    }

    // Create the purchase record
    Purchase p{cityName, foodName, quantity, price};
    cart.push_back(p);

    totalCost += price * quantity;

    qDebug() << quantity << foodName << "added from" << cityName
             << "for $" << price * quantity;

    // Add city to purchased list if not already there
    bool cityAlreadyAdded = false;
    for (const auto &c : purchasedCities) {
        if (c == cityName) {
            cityAlreadyAdded = true;
            break;
        }
    }

    if (!cityAlreadyAdded) {
        purchasedCities.push_back(cityName);
    }

    qDebug() << "Purchased cities count:" << purchasedCities.size();
    for (const auto &c : purchasedCities) {
        qDebug() << c;
    }
}




void guestWcustom3::on_checkoutButton_clicked()
{
    checkoutDialog dialog(cart, purchasedCities, totalCost, cities, startCity, this);
    dialog.exec();  // modal dialog
}


void guestWcustom3::on_backButton_clicked()
{
    if (caller) {
        caller->show();  // show the original window again
    }
    this->close();
}

