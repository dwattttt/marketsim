#include "instructionscreen7.h"
#include "ui_instructionscreen7.h"
#include "QPictureLabel.hpp"

InstructionScreen7::InstructionScreen7(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreen7)
{
    ui->setupUi(this);

    QPictureLabel *lbl = new QPictureLabel(ui->frame);
    lbl->setPixmap(QPixmap(":/ui/decrypt_3"));
    ui->frame->layout()->addWidget(lbl);
}

InstructionScreen7::~InstructionScreen7()
{
    delete ui;
}
