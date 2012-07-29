#include "instructionscreen2.h"
#include "ui_instructionscreen2.h"

InstructionScreen2::InstructionScreen2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreen2)
{
    ui->setupUi(this);
}

InstructionScreen2::~InstructionScreen2()
{
    delete ui;
}
