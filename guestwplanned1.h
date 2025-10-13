#ifndef GUESTWPLANNED1_H
#define GUESTWPLANNED1_H

#include <QMainWindow>
#include "loadCities.h"

namespace Ui {
class guestWplanned1;
}

class guestWplanned1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit guestWplanned1(vector<City> &cities, QWidget *parent = nullptr);
    ~guestWplanned1();

private slots:
    void on_backButton_clicked();

    void on_parisButton_clicked();

    void on_londonButton_clicked();

private:
    Ui::guestWplanned1 *ui;
    vector<City> &citiesData;
    const vector<string> initialElevenCities {"Amsterdam", "Berlin", "Brussels", "Budapest",
                                             "Hamburg", "Lisbon", "London", "Madrid", "Paris", "Prague", "Rome"};
    City startCity;
};

#endif // GUESTWPLANNED1_H
