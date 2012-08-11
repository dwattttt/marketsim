#include "finalscreen.h"
#include "ui_finalscreen.h"

FinalScreen::FinalScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::finalscreen)
{
    ui->setupUi(this);
}

FinalScreen::~FinalScreen()
{
    delete ui;
}

void FinalScreen::Populate(double investmentValue, int decryptionsCompleted)
{
    double decryptionsValue = decryptionsCompleted * DECRYPTION_VALUE;
    double totalValue = investmentValue + decryptionsValue;

    ui->lblDecryptionsCompleted->setText(QString("%1").arg(decryptionsCompleted));
    ui->lblDecryptionsValue->setText("$" + QString::number(decryptionsValue,'f',2));
    ui->lblInvestmentValue->setText("$" + QString::number(investmentValue,'f',2));
    ui->lblTotalPayment->setText("$" + QString::number(totalValue,'f',2));
}
