#include "instructionscreentest1.h"
#include "ui_instructionscreentest1.h"

InstructionScreenTest1::InstructionScreenTest1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreenTest1)
{
    ui->setupUi(this);

    updatePrices();
    displayAllocation();
    updateAllocation();
    connect(ui->allocationButton, SIGNAL(clicked()), this, SLOT(updateAllocation()));
    connect(ui->allocationSlider, SIGNAL(valueChanged(int)), this, SLOT(displayAllocation()));
}

InstructionScreenTest1::~InstructionScreenTest1()
{
    delete ui;
}



void InstructionScreenTest1::updatePrices()
{
    double price1 = 5;
    double price2 = 5;
    double wealth = 10;

    ui->price1Label->setText("$" + QString::number(price1,'f',2));
    ui->price2Label->setText("$" + QString::number(price2,'f',2));
    ui->wealthLabel->setText("$" + QString::number(wealth,'f',2));
}

void InstructionScreenTest1::displayAllocation()
{
    double newAllocation = 1 - (ui->allocationSlider->value() / ((double) ui->allocationSlider->maximum()));
    ui->allocation1Label->setText(QString::number(100*newAllocation,'f',0) + "%");
    ui->allocation2Label->setText(QString::number(100*(1-newAllocation),'f',0) + "%");
}

void InstructionScreenTest1::updateAllocation()
{
    double newAllocation = 1 - (ui->allocationSlider->value() / ((double) ui->allocationSlider->maximum()));
    ui->curAllocation1Label->setText(QString::number(100*newAllocation,'f',0) + "%");
    ui->curAllocation2Label->setText(QString::number(100*(1-newAllocation),'f',0) + "%");
    if (QString::number(100*newAllocation,'f',0) == QString::number(75,'f',0)) {
        emit testPassed();
        ui->allocationButton->setEnabled(false);
    }

}
