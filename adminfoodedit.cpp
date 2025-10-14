#include "adminfoodedit.h"
#include "ui_adminfoodedit.h"
#include "adminmainwindow.h"
#include "adminutilities.h"

adminFoodEdit::adminFoodEdit(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::adminFoodEdit)
{
    ui->setupUi(this);
}

adminFoodEdit::~adminFoodEdit()
{
    delete ui;
}

void adminFoodEdit::on_doneButton_clicked()
{
    adminMainWindow *window = new adminMainWindow;
    window->setGeometry(this->geometry());
    window->show();
    this->hide();
}


void adminFoodEdit::on_clearButton_clicked()
{
    ui->cityNameEdit->clear();
    ui->foodNameEdit->clear();
    ui->newPriceEdit->clear();
}


void adminFoodEdit::on_addButton_clicked()
{
    if(ui->newPriceEdit->text().isEmpty() || ui->cityNameEdit->text().isEmpty() || ui->foodNameEdit->text().isEmpty())
    {
        ui->warningLabel->setStyleSheet("color: red");
        ui->warningLabel->setText("Please make sure you have filled out the city, food, and new price sections.");
    }
    else
    {
        QString city = ui->cityNameEdit->text();
        QString food = ui->foodNameEdit->text();
        QString price = ui->newPriceEdit->text();
        deleteFood(food.toStdString(), successful);
        addFood(city.toStdString(), food.toStdString(), price.toDouble(), successful);
        qDebug() << "added new food";
        if(successful)
        {
            ui->cityNameEdit->clear();
            ui->foodNameEdit->clear();
            ui->newPriceEdit->clear();
            ui->warningLabel->setStyleSheet("color: green");
            ui->warningLabel->setText("Successfully added!");
        }
        else
        {
            ui->warningLabel->setStyleSheet("color: red");
            ui->warningLabel->setText("Please make sure you have filled out all sections correctly.");
        }
    }
}


void adminFoodEdit::on_deleteButton_clicked()
{
    if(ui->foodNameEdit->text().isEmpty())
    {
        ui->warningLabel->setStyleSheet("color: red");
        ui->warningLabel->setText("Please make sure you have filled out the food section.");
    }
    else
    {
        QString city = ui->cityNameEdit->text();
        QString food = ui->foodNameEdit->text();
        QString price = ui->newPriceEdit->text();
        deleteFood(food.toStdString(), successful);
        qDebug() << "deleted food";
        if(successful)
        {
            ui->cityNameEdit->clear();
            ui->foodNameEdit->clear();
            ui->newPriceEdit->clear();
            ui->warningLabel->setStyleSheet("color: green");
            ui->warningLabel->setText("Successfully deleted!");
        }
        else
        {
            ui->warningLabel->setStyleSheet("color: red");
            ui->warningLabel->setText("Please make sure you have filled out the food section correctly.");
        }
    }
}


void adminFoodEdit::on_editPriceButton_clicked()
{
    if(ui->newPriceEdit->text().isEmpty() || ui->foodNameEdit->text().isEmpty())
    {
        ui->warningLabel->setStyleSheet("color: red");
        ui->warningLabel->setText("Please make sure you have filled out the food and new price sections.");
    }
    else
    {
        QString city = ui->cityNameEdit->text();
        QString food = ui->foodNameEdit->text();
        QString price = ui->newPriceEdit->text();
        editFoodPrice(food.toStdString(), price.toDouble(), successful);
        qDebug() << "edited food price";
        if(successful)
        {
            ui->cityNameEdit->clear();
            ui->foodNameEdit->clear();
            ui->newPriceEdit->clear();
            ui->warningLabel->setStyleSheet("color: green");
            ui->warningLabel->setText("Price successfully edited!");
        }
        else
        {
            ui->warningLabel->setStyleSheet("color: red");
            ui->warningLabel->setText("Please make sure you have filled out both sections correctly.");
        }
    }
}

