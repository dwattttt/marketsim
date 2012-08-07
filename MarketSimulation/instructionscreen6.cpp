#include "instructionscreen6.h"
#include "ui_instructionscreen6.h"
#include "QPictureLabel.hpp"

InstructionScreen6::InstructionScreen6(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreen6)
{
    ui->setupUi(this);

    QPictureLabel *lbl = new QPictureLabel(ui->frame);
    lbl->setPixmap(QPixmap(":/ui/decrypt_2"));
    ui->frame->layout()->addWidget(lbl);
}

InstructionScreen6::~InstructionScreen6()
{
    delete ui;
}
