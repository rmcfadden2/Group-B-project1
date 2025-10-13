#include "confirmselectedcities.h"
#include "ui_confirmselectedcities.h"
#include <QDebug>

#include "guestwcustom2.h"
#include "guestwcustom3.h"


confirmSelectedCities::confirmSelectedCities(City start, vector<City> &data, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::confirmSelectedCities), startCity(start), cities(data)
{
    ui->setupUi(this);

    populateCityButtons();
}

confirmSelectedCities::~confirmSelectedCities()
{
    delete ui;
}

void confirmSelectedCities::populateCityButtons()
{
    // Make sure the scroll area’s inner widget exists
    QWidget *container = ui->scrollArea->widget();
    if (!container) {
        qWarning() << "Scroll area has no widget set!";
        return;
    }

    // Get or create a vertical layout inside the scroll area widget
    QVBoxLayout *layout = qobject_cast<QVBoxLayout*>(container->layout());
    if (!layout) {
        layout = new QVBoxLayout(container);
        container->setLayout(layout);
    }

    // Clear any previous labels
    QLayoutItem *item;
    while ((item = layout->takeAt(0)) != nullptr) {
        delete item->widget();
        delete item;
    }

    // Add one label per selected city
    for (const auto &city : cities)
    {
        QLabel *label = new QLabel(QString::fromStdString(city.getName()), container);
        label->setAlignment(Qt::AlignCenter);
        label->setStyleSheet("font-size: 14px; padding: 6px; border-bottom: 1px solid lightgray;");
        layout->addWidget(label);
    }

    layout->addStretch(); // keep everything pinned to the top
}

void confirmSelectedCities::on_buttonBox_accepted()
{
    qDebug() << "confirmed";

    guestWcustom2 *parent = qobject_cast<guestWcustom2*>(this->parent());
    qDebug() << "Parent pointer:" << parent;

    if (parent)
    {
        QRect oldGeometry = parent->geometry();
        qDebug() << "Old geometry:" << oldGeometry;

        // Open the new window in the same spot and size
        guestWcustom3 *window = new guestWcustom3(startCity, cities);
        window->setGeometry(oldGeometry);
        window->show();

        parent->close(); // close the old window
        qDebug() << "Parent closed, new window shown.";
    }
    else
    {
        qDebug() << "⚠️ Parent is nullptr!";
    }

    this->close();
}


void confirmSelectedCities::on_buttonBox_rejected()
{
    qDebug() << "rejected";
    this->close();
}

