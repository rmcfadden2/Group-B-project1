#include "guestwcustom1.h"
#include "ui_guestwcustom1.h"
#include "guestmainwindow.h"
#include "guestwcustom2.h"
#include <vector>
#include "loadCities.h"

#include <QPushButton>
#include <QDebug>

using namespace std;

guestWcustom1::guestWcustom1(vector<City> &cities, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::guestWcustom1), citiesData(cities), startingCity("empty")
{
    ui->setupUi(this);
    populateCityButtons();
}

guestWcustom1::~guestWcustom1()
{
    delete ui;
}

    void guestWcustom1::populateCityButtons()
{
    // Get the container widget inside the scroll area
    QWidget* container = ui->scrollArea->widget();
    QVBoxLayout* layout = qobject_cast<QVBoxLayout*>(container->layout());
    if (!layout) {
        layout = new QVBoxLayout(container);
        container->setLayout(layout);
    }

    // Clear existing buttons if any
    QLayoutItem *child;
    while ((child = layout->takeAt(0)) != nullptr) {
        delete child->widget();
        delete child;
    }

    // Create a button for each city
    for (const auto &city : citiesData) {
        QPushButton* btn = new QPushButton(QString::fromStdString(city.getName()));
        layout->addWidget(btn);

        // Optional: connect button click to a function
        connect(btn, &QPushButton::clicked, [this, city]() {
            startingCity = city;
            ui->startingCityLabel->setText(QString::fromStdString(startingCity.getName()));
            qDebug() << "Clicked city:" << QString::fromStdString(city.getName())
                     << "with" << city.getFoods().size() << "foods";
            displayDistances(city);
            displayFoods(city);
        });
    }

    layout->addStretch(); // pushes buttons to the top
}

void guestWcustom1::displayDistances(const City &city)
{
    ui->distancesWidget->clear();

    for (const auto &distance : city.getDistances())
    {
        QString displayText = QString("%1 - %2 km")
        .arg(QString::fromStdString(distance.getDestinationName()))
            .arg(distance.getdistance());

        // Create a list item with both display text and hidden data
        QListWidgetItem *item = new QListWidgetItem(displayText);
        item->setData(Qt::UserRole, QString::fromStdString(distance.getDestinationName())); // store raw name
        ui->distancesWidget->addItem(item);
    }

    ui->distancesWidget->setProperty("currentCity", QString::fromStdString(city.getName()));

    qDebug() << "Added" << city.getDistances().size() << "distances for" << QString::fromStdString(city.getName());
}

void guestWcustom1::displayFoods(const City &city)
{
    ui->foodsWidget->clear();

    for (const auto &food : city.getFoods())
    {
        QString displayText = QString("%1 - $%2")
        .arg(QString::fromStdString(food.getName()))
            .arg(food.getPrice());

        // Create a list item with both display text and hidden data
        QListWidgetItem *item = new QListWidgetItem(displayText);
        item->setData(Qt::UserRole, QString::fromStdString(food.getName())); // store raw name
        ui->foodsWidget->addItem(item);
    }

    ui->foodsWidget->setProperty("currentCity", QString::fromStdString(city.getName()));

    qDebug() << "Added" << city.getDistances().size() << "distances for" << QString::fromStdString(city.getName());
}

void guestWcustom1::on_backButton_clicked()
{
    guestMainWindow *window = new guestMainWindow;

    window->setGeometry(this->geometry());

    window->show();
    this->close();
}


void guestWcustom1::on_nextButton_clicked()
{
    if(startingCity.getName() == "empty")
    {
        ui->warningLabel->setText("Please select a city before continuing!");
    }
    else
    {
        guestWcustom2 *window = new guestWcustom2(startingCity, citiesData);

        window->setGeometry(this->geometry());

        window->show();
        this->close();
    }

}

