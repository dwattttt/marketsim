#include "instructionscreen3.h"
#include "ui_instructionscreen3.h"

InstructionScreen3::InstructionScreen3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreen3)
{
    ui->setupUi(this);
}

InstructionScreen3::~InstructionScreen3()
{
    delete ui;
}
