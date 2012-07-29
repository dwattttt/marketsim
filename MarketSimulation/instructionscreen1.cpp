#include "instructionscreen1.h"
#include "ui_instructionscreen1.h"

InstructionScreen1::InstructionScreen1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreen1)
{
    ui->setupUi(this);
}

InstructionScreen1::~InstructionScreen1()
{
    delete ui;
}
