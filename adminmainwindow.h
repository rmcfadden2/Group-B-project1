#ifndef ADMINMAINWINDOW_H
#define ADMINMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class adminMainWindow;
}

class adminMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminMainWindow(QWidget *parent = nullptr);
    ~adminMainWindow();

private slots:
    void on_citiesButton_clicked();

    void on_foodButton_clicked();

    void on_logoutButton_clicked();

private:
    Ui::adminMainWindow *ui;
};

#endif // ADMINMAINWINDOW_H
