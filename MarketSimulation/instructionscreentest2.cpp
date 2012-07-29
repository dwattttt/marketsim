#include "instructionscreentest2.h"
#include "ui_instructionscreentest2.h"

InstructionScreenTest2::InstructionScreenTest2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreenTest2)
{
    ui->setupUi(this);
}

InstructionScreenTest2::~InstructionScreenTest2()
{
    delete ui;
}
