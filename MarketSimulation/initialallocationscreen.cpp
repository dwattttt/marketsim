#include "initialallocationscreen.h"
#include "ui_initialallocationscreen.h"
#include "plotwidget.h"

InitialAllocationScreen::InitialAllocationScreen(Market* market, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InitialAllocationScreen)
{
    ui->setupUi(this);

    this->market = market;

    // show empty graph
    PlotWidget *plot = new PlotWidget(this);
    plot->addData(0, 5.0, 5.0);
    ui->plotWidget->layout()->addWidget(plot);

    updatePrices(0);

    // setup investment slider
    ui->investment->updateWealth(market->getWealth());
    connect(ui->investment, SIGNAL(allocationUpdated(double)), this, SLOT(updateAllocation(double)));
}

InitialAllocationScreen::~InitialAllocationScreen()
{
    delete ui;
}

void InitialAllocationScreen::updatePrices(double time)
{
    double price1 = market->getPrice1();
    double price2 = market->getPrice2();

    ui->investment->updatePrices(price1, price2);
}

void InitialAllocationScreen::updateAllocation(double newAllocation)
{
    market->updateAllocation(newAllocation);
    ui->investment->updateAllocation(market->getAllocation());
}
