#include "londonwindow2.h"
#include "ui_londonwindow2.h"
#include "checkoutdialog.h"

londonWindow2::londonWindow2(City start, vector<City> &route, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::londonWindow2), startCity(start), cities(route), currentCity("empty")
{
    ui->setupUi(this);

    // Ensure the scroll area widget (citiesWidget) has a layout
    if (!ui->citiesWidget->layout())
        ui->citiesWidget->setLayout(new QVBoxLayout(ui->citiesWidget));

    populateCityButtons();
}

londonWindow2::~londonWindow2()
{
    delete ui;
}

// Create scrollable buttons for each city
void londonWindow2::populateCityButtons()
{
    // Scroll area container
    QScrollArea *scrollArea = ui->citiesScrollArea; // Your QScrollArea in UI
    QWidget *container = new QWidget;
    QVBoxLayout *layout = new QVBoxLayout(container);
    container->setLayout(layout);
    scrollArea->setWidget(container);
    scrollArea->setWidgetResizable(true);

    for (const auto &city : cities)
    {
        QPushButton *cityButton = new QPushButton(QString::fromStdString(city.getName()), container);
        layout->addWidget(cityButton);

        connect(cityButton, &QPushButton::clicked, this, [&city, this]() {
            currentCity = city;
            qDebug() << "Clicked city:" << QString::fromStdString(city.getName())
                     << "with" << city.getFoods().size() << "foods";
            displayFoodsForCity(city);
        });
    }

    ui->quantitySpinBox->setMinimum(1);
    ui->quantitySpinBox->setMaximum(100);

    layout->addStretch();
}

// Display foods for the selected city in QListWidget
void londonWindow2::displayFoodsForCity(const City &city)
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


void londonWindow2::on_purchaseButton_clicked()
{
    // Get selected food from the list widget
    QListWidgetItem *selectedItem = ui->foodListWidget->currentItem();

    if (!selectedItem) {
        qDebug() << "No food selected!";
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




void londonWindow2::on_checkoutButton_clicked()
{
    checkoutDialog dialog(cart, purchasedCities, totalCost, cities, startCity, this);
    dialog.exec();  // modal dialog
}
