#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

struct Purchase {
    QString city;
    QString food;
    int quantity;
    double pricePerUnit;
};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_purchaseButton_clicked();
    void on_checkoutButton_clicked();

private:
    Ui::MainWindow *ui;

    QMap<QString, QStringList> cityFoods;
    QMap<QString, QString> foodToCityMap;
    QMap<QString, double> foodPrices;
    QList<Purchase> cart;
    double totalCost;

    void loadCSV();  // function to read CSV and populate cityFoods
    void populateFoodList();
    void populateCityButtons();

};
#endif // MAINWINDOW_H
