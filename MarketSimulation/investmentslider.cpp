#include "investmentslider.h"
#include "ui_investmentslider.h"

#include <cmath>

investmentSlider::investmentSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::investmentSlider)
{
    ui->setupUi(this);

    ui->dummyBar->setVisible(false);
    connect(ui->allocationSlider,SIGNAL(valueChanged(int)),this, SLOT(allocationChanged()));
    connect(ui->allocationButton, SIGNAL(clicked()),this,SLOT(allocationLockedIn()));

    allocationChanged();
}

investmentSlider::~investmentSlider()
{
    delete ui;
}

void investmentSlider::updateAllocation(double newAllocation)
{
    if (newAllocation != allocation)
    {
        ui->allocationSlider->setValue(round((1 - newAllocation)*((double) ui->allocationSlider->maximum())));
    }
    ui->curAllocation1Label->setText(QString::number(100*newAllocation,'f',0) + "%");
    ui->curAllocation2Label->setText(QString::number(100*(1-newAllocation),'f',0) + "%");

    allocationChanged();
}

void investmentSlider::updatePrices(double price1, double price2)
{
    ui->price1Label->setText("$" + QString::number(price1,'f',2));
    ui->price2Label->setText("$" + QString::number(price2,'f',2));

    // dummy bar display
    double avgPrice = (price1 + price2) / 2;
    double base = 5.0;
    double index = 100 * (avgPrice / base);
    double indexChange = 100 * ((avgPrice - base) / base);
    ui->marketIndex->IndexChanged(index, indexChange);
}

void investmentSlider::updateWealth(double newWealth)
{
    ui->wealthLabel->setText("$" + QString::number(newWealth,'f',2));
}

void investmentSlider::toggleDummyBar(bool toggle)
{
    ui->dummyBar->setVisible(toggle);
}

void investmentSlider::allocationChanged()
{
    allocation = 1 - (ui->allocationSlider->value() / ((double) ui->allocationSlider->maximum()));
    ui->allocation1Label->setText(QString::number(100*allocation,'f',0) + "%");
    ui->allocation2Label->setText(QString::number(100*(1-allocation),'f',0) + "%");
}

void investmentSlider::allocationLockedIn()
{
    updateAllocation(allocation);
    emit allocationUpdated(allocation);
}
