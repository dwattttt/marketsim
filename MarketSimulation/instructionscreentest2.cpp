#include "instructionscreentest2.h"
#include "ui_instructionscreentest2.h"
#include "plotwidget.h"

InstructionScreenTest2::InstructionScreenTest2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreenTest2)
{
    ui->setupUi(this);
    displayAllocation();
    updateAllocation();
    updatePrices();

    // Show movement in prices on graph
    PlotWidget *plot = new PlotWidget(this);
    plot->addData(0, 5.0, 5.0);
    plot->addData(10, price1, price2);
    ui->plotWidget->layout()->addWidget(plot);

    connect(ui->allocationButton, SIGNAL(clicked()), this, SLOT(updateAllocation()));
    connect(ui->allocationSlider, SIGNAL(valueChanged(int)), this, SLOT(displayAllocation()));
}

InstructionScreenTest2::~InstructionScreenTest2()
{
    delete ui;
}

void InstructionScreenTest2::updatePrices()
{
    ui->price1Label->setText("$" + QString::number(price1,'f',2));
    ui->price2Label->setText("$" + QString::number(price2,'f',2));
    ui->wealthLabel->setText("$" + QString::number(wealth,'f',2));
    ui->curAllocation1Label->setText(QString::number(75,'f',0) + "%");
    ui->curAllocation2Label->setText(QString::number(25,'f',0) + "%");
}

void InstructionScreenTest2::displayAllocation()
{
    double newAllocation = 1 - (ui->allocationSlider->value() / ((double) ui->allocationSlider->maximum()));
    ui->allocation1Label->setText(QString::number(100*newAllocation,'f',0) + "%");
    ui->allocation2Label->setText(QString::number(100*(1-newAllocation),'f',0) + "%");
}

void InstructionScreenTest2::updateAllocation()
{
    double newAllocation = 1 - (ui->allocationSlider->value() / ((double) ui->allocationSlider->maximum()));
    ui->curAllocation1Label->setText(QString::number(100*newAllocation,'f',0) + "%");
    ui->curAllocation2Label->setText(QString::number(100*(1-newAllocation),'f',0) + "%");
    if (QString::number(100*newAllocation,'f',0) == QString::number(25,'f',0)) {
        emit testPassed();
        ui->allocationButton->setEnabled(false);
    }

}
