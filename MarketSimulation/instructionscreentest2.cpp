#include "instructionscreentest2.h"
#include "ui_instructionscreentest2.h"
#include "plotwidget.h"

InstructionScreenTest2::InstructionScreenTest2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreenTest2)
{
    ui->setupUi(this);
    // Show movement in prices on graph
    PlotWidget *plot = new PlotWidget(this);
    plot->addData(0, 5.0, 5.0);
    plot->addData(10, price1, price2);
    ui->plotWidget->layout()->addWidget(plot);

    ui->investment->toggleDummyBar(true);
    ui->investment->updateAllocation(0.75);
    ui->investment->updatePrices(price1, price2);
    ui->investment->updateWealth(wealth);
    connect(ui->investment, SIGNAL(allocationUpdated(double)), this, SLOT(updateAllocation(double)));
}

InstructionScreenTest2::~InstructionScreenTest2()
{
    delete ui;
}

void InstructionScreenTest2::updateAllocation(double newAllocation)
{
    ui->investment->updateAllocation(newAllocation);
    if (newAllocation == 0.25)
    {
        emit testPassed();
    }
}
