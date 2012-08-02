#include "initialallocationscreen.h"
#include "ui_initialallocationscreen.h"

InitialAllocationScreen::InitialAllocationScreen(Market* market, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InitialAllocationScreen)
{
    ui->setupUi(this);

    this->market = market;

    displayAllocation();
    updateAllocation();
    updatePrices();
    connect(ui->allocationButton, SIGNAL(clicked()), this, SLOT(updateAllocation()));
    connect(ui->allocationSlider, SIGNAL(valueChanged(int)), this, SLOT(displayAllocation()));
}

InitialAllocationScreen::~InitialAllocationScreen()
{
    delete ui;
}


void InitialAllocationScreen::updatePrices()
{
    double price1 = market->getPrice1();
    double price2 = market->getPrice2();
    double wealth = market->getWealth();

    ui->price1Label->setText("$" + QString::number(price1,'f',2));
    ui->price2Label->setText("$" + QString::number(price2,'f',2));
    ui->wealthLabel->setText("$" + QString::number(wealth,'f',2));
}

void InitialAllocationScreen::displayAllocation()
{
    double newAllocation = 1 - (ui->allocationSlider->value() / ((double) ui->allocationSlider->maximum()));
    ui->allocation1Label->setText(QString::number(100*newAllocation,'f',0) + "%");
    ui->allocation2Label->setText(QString::number(100*(1-newAllocation),'f',0) + "%");
}

void InitialAllocationScreen::updateAllocation()
{
    double newAllocation = 1 - (ui->allocationSlider->value() / ((double) ui->allocationSlider->maximum()));
    ui->curAllocation1Label->setText(QString::number(100*newAllocation,'f',0) + "%");
    ui->curAllocation2Label->setText(QString::number(100*(1-newAllocation),'f',0) + "%");

    market->updateAllocation(newAllocation);

}
