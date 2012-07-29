#include "instructionscreentest3.h"
#include "ui_instructionscreentest3.h"

InstructionScreenTest3::InstructionScreenTest3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreenTest3)
{
    ui->setupUi(this);
}

InstructionScreenTest3::~InstructionScreenTest3()
{
    delete ui;
}
