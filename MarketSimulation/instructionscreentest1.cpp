#include "instructionscreentest1.h"
#include "ui_instructionscreentest1.h"

InstructionScreenTest1::InstructionScreenTest1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreenTest1)
{
    ui->setupUi(this);
}

InstructionScreenTest1::~InstructionScreenTest1()
{
    delete ui;
}
