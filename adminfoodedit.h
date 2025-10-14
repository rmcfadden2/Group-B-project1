#ifndef ADMINFOODEDIT_H
#define ADMINFOODEDIT_H

#include <QMainWindow>

namespace Ui {
class adminFoodEdit;
}

class adminFoodEdit : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminFoodEdit(QWidget *parent = nullptr);
    ~adminFoodEdit();

private slots:
    void on_doneButton_clicked();

    void on_clearButton_clicked();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

    void on_editPriceButton_clicked();

private:
    Ui::adminFoodEdit *ui;
    bool successful;
};

#endif // ADMINFOODEDIT_H
