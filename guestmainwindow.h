#ifndef GUESTMAINWINDOW_H
#define GUESTMAINWINDOW_H

#include <QMainWindow>

#include <vector>
#include "loadCities.h"

using namespace std;

namespace Ui {
class guestMainWindow;
}

class guestMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit guestMainWindow(QWidget *parent = nullptr);
    ~guestMainWindow();

private slots:

    void on_backButton_clicked();

    void on_plannedButton_clicked();

    void on_customButton_clicked();

private:
    Ui::guestMainWindow *ui;

    vector<City> cities;
};

#endif // GUESTMAINWINDOW_H
