#include "instructionscreentest1.h"
#include "ui_instructionscreentest1.h"
#include "plotwidget.h"

InstructionScreenTest1::InstructionScreenTest1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreenTest1)
{
    ui->setupUi(this);

    // show empty graph
    PlotWidget *plot = new PlotWidget(this);
    plot->addData(0, price1, price2);
    ui->plotWidget->layout()->addWidget(plot);

    ui->investment->updateAllocation(0.5);
    ui->investment->updatePrices(price1, price2);
    ui->investment->updateWealth(wealth);
    ui->investment->toggleDummyBar(true);
    connect(ui->investment, SIGNAL(allocationUpdated(double)), this, SLOT(updateAllocation(double)));
}

InstructionScreenTest1::~InstructionScreenTest1()
{
    delete ui;
}

void InstructionScreenTest1::updateAllocation(double newAllocation)
{
    ui->investment->updateAllocation(newAllocation);
    if (newAllocation == 0.75)
    {
        emit testPassed();
    }
}
