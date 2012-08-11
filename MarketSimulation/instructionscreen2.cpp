#include "instructionscreen2.h"
#include "ui_instructionscreen2.h"
#include "QPictureLabel.hpp"

InstructionScreen2::InstructionScreen2(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreen2)
{
    ui->setupUi(this);

    QPictureLabel *lbl = new QPictureLabel(ui->frame);
    lbl->setPixmap(QPixmap(":/ui/market"));
    ui->frame->layout()->addWidget(lbl);
}

InstructionScreen2::~InstructionScreen2()
{
    delete ui;
}
