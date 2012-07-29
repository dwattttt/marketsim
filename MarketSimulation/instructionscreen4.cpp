#include "instructionscreen4.h"
#include "ui_instructionscreen4.h"

InstructionScreen4::InstructionScreen4(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreen4)
{
    ui->setupUi(this);
}

InstructionScreen4::~InstructionScreen4()
{
    delete ui;
}
