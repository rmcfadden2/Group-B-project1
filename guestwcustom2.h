#ifndef GUESTWCUSTOM2_H
#define GUESTWCUSTOM2_H

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QDebug>
#include "loadCities.h"

#include <vector>
#include <string>

using namespace std;

namespace Ui {
class guestWcustom2;
}

class guestWcustom2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit guestWcustom2(City startcity, vector<City> &citylist, QWidget *parent = nullptr);
    ~guestWcustom2();
    void populateCityButtons();


private slots:
    void on_nextButton_clicked();

    void on_backButton_clicked();

private:
    Ui::guestWcustom2 *ui;

    vector<City> &cities;
    vector<City> selectedCities;
    City startingCity;
    vector<QPushButton*> cityButtons;
};

#endif // GUESTWCUSTOM2_H
