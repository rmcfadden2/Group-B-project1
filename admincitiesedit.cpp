#include "admincitiesedit.h"
#include "ui_admincitiesedit.h"
#include "adminutilities.h"
#include "adminutilities.h"
#include "adminmainwindow.h"

adminCitiesEdit::adminCitiesEdit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::adminCitiesEdit)
{
    ui->setupUi(this);
}

adminCitiesEdit::~adminCitiesEdit()
{
    delete ui;
}

void adminCitiesEdit::on_doneButton_clicked()
{
    adminMainWindow *window = new adminMainWindow;
    window->setGeometry(this->geometry());
    window->show();
    this->hide();
}


void adminCitiesEdit::on_clearButton_clicked()
{
    ui->cityNameEdit->clear();
}


void adminCitiesEdit::on_addButton_clicked()
{
    if(!ui->cityNameEdit->text().isEmpty())
    {
        QString city = ui->cityNameEdit->text();
        addCity(city.toStdString(), successful);
        qDebug() << "added new city";
        if(successful)
        {
            ui->warningLabel->setStyleSheet("color: green");
            ui->warningLabel->setText("Successfully added new city!");
        }
        else
        {
            ui->warningLabel->setStyleSheet("color: red");
            ui->warningLabel->setText("Please input a valid City");
        }

    }
    else
    {
        ui->warningLabel->setStyleSheet("color: red");
        ui->warningLabel->setText("Please input a valid City");
    }
}


void adminCitiesEdit::on_deleteButton_clicked()
{
    if(!ui->cityNameEdit->text().isEmpty())
    {
        QString city = ui->cityNameEdit->text();
        deleteCity(city.toStdString(), successful);
        qDebug() << "deleted new city";
        if(successful)
        {
            ui->warningLabel->setStyleSheet("color: green");
            ui->warningLabel->setText("Successfully deleted city!");
        }
        else
        {
            ui->warningLabel->setStyleSheet("color: red");
            ui->warningLabel->setText("Please input a valid City");
        }
    }
    else
    {
        ui->warningLabel->setStyleSheet("color: red");
        ui->warningLabel->setText("Please input a valid City");
    }
}

