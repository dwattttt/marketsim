#include "instructionscreen7.h"
#include "ui_instructionscreen7.h"

InstructionScreen7::InstructionScreen7(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreen7)
{
    ui->setupUi(this);
}

InstructionScreen7::~InstructionScreen7()
{
    delete ui;
}
