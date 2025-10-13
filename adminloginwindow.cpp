#include "adminloginwindow.h"
#include "ui_adminloginwindow.h"
#include "mainwindow.h"

adminLoginWindow::adminLoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::adminLoginWindow)
{
    ui->setupUi(this);
    loadAdmin("admin.txt", admin);
}

adminLoginWindow::~adminLoginWindow()
{
    delete ui;
}

void adminLoginWindow::on_cancelButton_clicked()
{
    MainWindow *window = new MainWindow;
    window->setGeometry(this->geometry());
    window->show();
    this->hide();
}


void adminLoginWindow::on_clearButton_clicked()
{
    ui->usernameEdit->setText("");
    ui->passwordEdit->setText("");
}


void adminLoginWindow::on_loginButton_clicked()
{
    if(loginAccepted(ui->passwordEdit->text(), ui->usernameEdit->text()))
    {

    }
    else
    {
        ui->warningLabel->setText("Username or Password is incorrect");
        ui->warningLabel->setStyleSheet("QLabel { color : red; }");
    }
}

bool adminLoginWindow::loginAccepted(QString password, QString username)
{
}
