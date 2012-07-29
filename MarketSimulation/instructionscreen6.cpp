#include "instructionscreen6.h"
#include "ui_instructionscreen6.h"

InstructionScreen6::InstructionScreen6(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreen6)
{
    ui->setupUi(this);
}

InstructionScreen6::~InstructionScreen6()
{
    delete ui;
}
