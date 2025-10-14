#include "adminmainwindow.h"
#include "ui_adminmainwindow.h"
#include "adminloginwindow.h"
#include "admincitiesedit.h"
#include "adminfoodedit.h"

adminMainWindow::adminMainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::adminMainWindow)
{
    ui->setupUi(this);
}

adminMainWindow::~adminMainWindow()
{
    delete ui;
}

void adminMainWindow::on_citiesButton_clicked()
{
    adminCitiesEdit *window = new adminCitiesEdit;
    window->setGeometry(this->geometry());
    window->show();
    this->close();
}


void adminMainWindow::on_foodButton_clicked()
{
    adminFoodEdit *window = new adminFoodEdit;
    window->setGeometry(this->geometry());
    window->show();
    this->close();
}


void adminMainWindow::on_logoutButton_clicked()
{
    adminLoginWindow *window = new adminLoginWindow;
    window->setGeometry(this->geometry());
    window->show();
    this->close();
}

