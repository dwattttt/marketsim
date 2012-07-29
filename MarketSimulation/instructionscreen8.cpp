#include "instructionscreen8.h"
#include "ui_instructionscreen8.h"

InstructionScreen8::InstructionScreen8(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreen8)
{
    ui->setupUi(this);
}

InstructionScreen8::~InstructionScreen8()
{
    delete ui;
}
