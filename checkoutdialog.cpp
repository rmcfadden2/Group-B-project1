#include "checkoutdialog.h"
#include "ui_checkoutdialog.h"

#include "guestwcustom4.h"
#include "guestwcustom3.h"

checkoutDialog::checkoutDialog(const vector<Purchase> &c, const vector<string> purchasedCity, double t, vector<City> data, City start, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::checkoutDialog), cart(c), purchasedCities(purchasedCity), total(t), cities(data), startCity(start)
{
    ui->setupUi(this);

    // Configure table
    ui->summaryTable->setColumnCount(5);
    QStringList headers = {"City", "Food", "Quantity", "Price", "Total"};
    ui->summaryTable->setHorizontalHeaderLabels(headers);
    ui->summaryTable->setRowCount(cart.size());


    int row = 0;
    double cityTotal = 0;

    for (int j = 0; j < purchasedCity.size(); j++)
    {
        cityTotal = 0;
        // Insert a new row for the city name
        ui->summaryTable->insertRow(row);
        ui->summaryTable->setItem(row, 0, new QTableWidgetItem(QString::fromStdString(purchasedCity[j])));

        row++;

        // Insert a row for each purchase in this city
        for (int i = 0; i < cart.size(); i++)
        {
            const Purchase &p = cart[i];
            if (p.city == purchasedCity[j])
            {
                ui->summaryTable->insertRow(row);
                ui->summaryTable->setItem(row, 0, new QTableWidgetItem("")); // blank cell
                ui->summaryTable->setItem(row, 1, new QTableWidgetItem(p.food));
                ui->summaryTable->setItem(row, 2, new QTableWidgetItem(QString::number(p.quantity)));
                ui->summaryTable->setItem(row, 3, new QTableWidgetItem(QString::number(p.pricePerUnit, 'f', 2)));
                ui->summaryTable->setItem(row, 4, new QTableWidgetItem(QString::number(p.quantity * p.pricePerUnit, 'f', 2)));

                row++;
                cityTotal += (p.quantity * p.pricePerUnit);
            }
        }
        ui->summaryTable->insertRow(row);
        ui->summaryTable->setItem(row, 0, new QTableWidgetItem("City Total")); // blank cell
        ui->summaryTable->setItem(row, 1, new QTableWidgetItem(""));
        ui->summaryTable->setItem(row, 2, new QTableWidgetItem(""));
        ui->summaryTable->setItem(row, 3, new QTableWidgetItem(""));
        ui->summaryTable->setItem(row, 4, new QTableWidgetItem(QString::number(cityTotal, 'f', 2)));
        row++;
    }

    // Show total
    ui->totalLabel->setText(QString("Grand Total: $%1").arg(total, 0, 'f', 2));

    if(cities.size() != purchasedCity.size())
    {
        ui->warningLabel->setStyleSheet("color: red;");
        ui->warningLabel->setText("You did not purchase from all of the cities");
    }
}

checkoutDialog::~checkoutDialog()
{
    delete ui;
}

void checkoutDialog::on_buttonBox_accepted()
{
    qDebug() << "confirmed";

    guestWcustom3 *parent = qobject_cast<guestWcustom3*>(this->parent());
    qDebug() << "Parent pointer:" << parent;

    if (parent)
    {
        QRect oldGeometry = parent->geometry();
        qDebug() << "Old geometry:" << oldGeometry;

        // Open the new window in the same spot and size
        guestWcustom4 *window = new guestWcustom4(cart, purchasedCities, total, cities, startCity);
        window->setGeometry(oldGeometry);
        window->show();

        parent->close(); // close the old window
        qDebug() << "Parent closed, new window shown.";
    }
    else
    {
        qDebug() << "⚠️ Parent is nullptr!";
    }

    this->close();
}


void checkoutDialog::on_buttonBox_rejected()
{
    this->hide();
}

