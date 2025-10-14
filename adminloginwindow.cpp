#include "adminloginwindow.h"
#include "ui_adminloginwindow.h"
#include "mainwindow.h"
#include "adminmainwindow.h"

adminLoginWindow::adminLoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::adminLoginWindow)
{
    ui->setupUi(this);
    loadAdmin("admin.txt", admins);
    qDebug() << "after loadAdmin()";
    for(auto admin: admins)
    {
        qDebug() << admin.user << admin.passkey;
    }

    connect(ui->usernameEdit, &QLineEdit::returnPressed, this, [=]() {
        on_loginButton_clicked();
    });
    connect(ui->passwordEdit, &QLineEdit::returnPressed, this, [=]() {
        on_loginButton_clicked();
    });
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
        adminMainWindow *window = new adminMainWindow;
        window->setGeometry(this->geometry());
        window->show();
        this->hide();
    }
    else
    {
        ui->warningLabel->setText("Username or Password is incorrect");
        ui->warningLabel->setStyleSheet("QLabel { color : red; }");
    }
}

bool adminLoginWindow::loginAccepted(QString password, QString username)
{
    for(auto admin : admins)
    {
        if(admin.user == username && admin.passkey == password)
        {
            return true;
        }
    }
    return false;
}
