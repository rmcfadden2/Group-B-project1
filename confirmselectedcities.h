#ifndef CONFIRMSELECTEDCITIES_H
#define CONFIRMSELECTEDCITIES_H

#include <QDialog>
#include <vector>
#include <string>
#include "loadCities.h"

using namespace std;

namespace Ui {
class confirmSelectedCities;
}

class confirmSelectedCities : public QDialog
{
    Q_OBJECT

public:
    explicit confirmSelectedCities(City start, vector<City> &data, QWidget *parent = nullptr);
    ~confirmSelectedCities();
    void populateCityButtons();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::confirmSelectedCities *ui;

    vector<City> &cities;
    City startCity;
    vector<QPushButton*> cityButtons;
};

#endif // CONFIRMSELECTEDCITIES_H
