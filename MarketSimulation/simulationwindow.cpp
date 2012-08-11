#include "simulationwindow.h"
#include "ui_simulationwindow.h"

SimulationWindow::SimulationWindow(Market* market, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SimulationWindow)
{
    ui->setupUi(this);

    this->market = market;

    updatePrices(0);
    connect(market,SIGNAL(priceChange(double)),this,SLOT(updatePrices(double)));
    connect(ui->investment, SIGNAL(allocationUpdated(double)), this, SLOT(updateAllocation(double)));
}

SimulationWindow::~SimulationWindow()
{
    delete ui;
}

void SimulationWindow::initAllocation()
{
    ui->investment->updateAllocation(market->getAllocation());
    updatePrices(0);
}

void SimulationWindow::updatePrices(double time)
{
    double price1 = market->getPrice1();
    double price2 = market->getPrice2();

    ui->investment->updatePrices(price1, price2);
    ui->plotWidget->addData(time, price1, price2);
}

void SimulationWindow::updateAllocation(double newAllocation)
{
    market->updateAllocation(newAllocation);
    ui->investment->updateAllocation(market->getAllocation());
}
