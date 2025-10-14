#ifndef ADMINCITIESEDIT_H
#define ADMINCITIESEDIT_H

#include <QMainWindow>

namespace Ui {
class adminCitiesEdit;
}

class adminCitiesEdit : public QMainWindow
{
    Q_OBJECT

public:
    explicit adminCitiesEdit(QWidget *parent = nullptr);
    ~adminCitiesEdit();

private slots:
    void on_doneButton_clicked();

    void on_clearButton_clicked();

    void on_addButton_clicked();

    void on_deleteButton_clicked();

private:
    Ui::adminCitiesEdit *ui;
    bool successful;
};

#endif // ADMINCITIESEDIT_H
