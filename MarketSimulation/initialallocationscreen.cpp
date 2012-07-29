#include "initialallocationscreen.h"
#include "ui_initialallocationscreen.h"

InitialAllocationScreen::InitialAllocationScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InitialAllocationScreen)
{
    ui->setupUi(this);
}

InitialAllocationScreen::~InitialAllocationScreen()
{
    delete ui;
}
