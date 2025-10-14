#ifndef ADMINLOGINWINDOW_H
#define ADMINLOGINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "loadCities.h"

using namespace std;

namespace Ui {
class adminLoginWindow;
}

class adminLoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminLoginWindow(QWidget *parent = nullptr);
    ~adminLoginWindow();
    bool loginAccepted(QString, QString);

private slots:
    void on_cancelButton_clicked();

    void on_clearButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::adminLoginWindow *ui;
    vector<Admin> admins;
};

#endif // ADMINLOGINWINDOW_H
