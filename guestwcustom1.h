#ifndef GUESTWCUSTOM1_H
#define GUESTWCUSTOM1_H

#include <QMainWindow>

#include <vector>
#include "loadCities.h"

using namespace std;

namespace Ui {
class guestWcustom1;
}

class guestWcustom1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit guestWcustom1(vector<City> &cities, QWidget *parent = nullptr);
    ~guestWcustom1();
    void populateCityButtons();
    void displayDistances(const City &city);
    void displayFoods(const City &city);

private slots:
    void on_backButton_clicked();

    void on_nextButton_clicked();

private:
    Ui::guestWcustom1 *ui;

    vector<City> &citiesData;
    City startingCity;
};

#endif // GUESTWCUSTOM1_H
