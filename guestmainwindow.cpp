#include "guestmainwindow.h"
#include "ui_guestmainwindow.h"

#include "mainwindow.h"
#include "guestwplanned1.h"
#include "guestwcustom1.h"

#include "loadCities.h"

guestMainWindow::guestMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::guestMainWindow)
{
    ui->setupUi(this);


    loadCities("distances.txt", cities);
    loadDistances("distances.txt", cities);
    loadFoods("foods.txt", cities);
    qDebug() << "Cities loaded:";
    for (const auto &city : cities)
    {
        qDebug() << QString::fromStdString(city.getName()) << "has" << city.getFoods().size() << "foods";
    }

    qDebug() << "Loaded" << cities.size() << "cities.";
}

guestMainWindow::~guestMainWindow()
{
    delete ui;
}


void guestMainWindow::on_backButton_clicked()
{
    MainWindow *window = new MainWindow();

    window->setGeometry(this->geometry());

    window->show();
    this->close();
}


void guestMainWindow::on_plannedButton_clicked()
{
    guestWplanned1 *plannedWindow = new guestWplanned1(cities);

    plannedWindow->setGeometry(this->geometry());

    plannedWindow->show();
    this->close();
}


void guestMainWindow::on_customButton_clicked()
{
    guestWcustom1 *customWindow = new guestWcustom1(cities);

    customWindow->setGeometry(this->geometry());

    customWindow->show();
    this->close();
}

