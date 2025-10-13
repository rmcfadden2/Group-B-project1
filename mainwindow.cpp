#include "mainwindow.h"
#include "adminloginwindow.h"
#include "guestmainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_adminButton_clicked()
{
    adminLoginWindow *loggedIn = new adminLoginWindow();

    loggedIn->setGeometry(this->geometry());

    loggedIn->show();
    this->close();
}


void MainWindow::on_guestButton_clicked()
{
    guestMainWindow *guestWindow = new guestMainWindow();

    guestWindow->setGeometry(this->geometry());

    guestWindow->show();
    this->close();
}

