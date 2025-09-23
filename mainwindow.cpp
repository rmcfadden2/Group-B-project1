#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QVBoxLayout>
#include <QListWidget>
#include <QRandomGenerator>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QStringList>
#include <QMap>
#include "checkoutdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    loadCSV();             // read cities and foods
    populateFoodList();       // create foodToCityMap and foodPrices
    populateCityButtons(); // add buttons to the GUI
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadCSV() {
    QFile file("/Users/robertmcfadden/Qtfolders/travelProject/cities.csv");  // make sure path is correct
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Failed to open file!";
        return;
    }

    QTextStream in(&file);

    // Skip header
    if (!in.atEnd()) in.readLine();

    QString currentCity;
    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        if (line.isEmpty()) continue;

        QStringList parts = line.split(",");
        if (!parts[0].trimmed().isEmpty()) {
            currentCity = parts[0].trimmed();
            cityFoods[currentCity] = QStringList();
        }
        if (parts.size() > 2 && !parts[1].trimmed().isEmpty()) {
            QString food = parts[1].trimmed();
            cityFoods[currentCity] << food;
            foodToCityMap[food] = currentCity;

            // Remove "$" if present
            QString priceString = parts[2].trimmed();
            priceString.remove('$');  // removes any $ sign

            // Convert to double
            bool ok = false;
            double price = priceString.toDouble(&ok);
            if (ok) {
                foodPrices[food] = price;
            } else {
                foodPrices[food] = 0.0; // fallback if conversion fails
            }
        }

    }
}

void MainWindow::populateFoodList() {
    for (const QString &food : foodToCityMap.keys()) {
        ui->foodListWidget->addItem(food);
    }
    ui->quantitySpinBox->setMinimum(1);
    ui->quantitySpinBox->setMaximum(100);
}

void MainWindow::on_purchaseButton_clicked() {
    QListWidgetItem* selectedItem = ui->foodListWidget->currentItem();
    if (!selectedItem) return;

    QString food = selectedItem->text();
    QString city = foodToCityMap[food];
    int quantity = ui->quantitySpinBox->value();
    double price = foodPrices[food];

    Purchase p{city, food, quantity, price};
    cart.append(p);
    totalCost += price * quantity;

    qDebug() << quantity << food << "added from" << city << "for $" << price * quantity;
}

void MainWindow::on_checkoutButton_clicked() {
    CheckoutDialog dialog(cart, totalCost, this);
    dialog.exec();  // modal dialog
}

void MainWindow::populateCityButtons()
{
    // Get the vertical layout from citiesWidget
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(ui->citiesWidget->layout());
    if (!layout) {
        layout = new QVBoxLayout(ui->citiesWidget);
        ui->citiesWidget->setLayout(layout);
    }

    for (auto it = cityFoods.begin(); it != cityFoods.end(); ++it) {
        QString city = it.key();
        QStringList foods = it.value();

        QPushButton *btn = new QPushButton(city, this);
        layout->addWidget(btn);

        connect(btn, &QPushButton::clicked, this, [this, foods]() {
            ui->foodListWidget->clear();
            ui->foodListWidget->addItems(foods);
        });
    }
}
