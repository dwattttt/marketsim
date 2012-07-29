#include "instructionscreen5.h"
#include "ui_instructionscreen5.h"

InstructionScreen5::InstructionScreen5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreen5)
{
    ui->setupUi(this);
}

InstructionScreen5::~InstructionScreen5()
{
    delete ui;
}
