#include "instructionscreen5.h"
#include "ui_instructionscreen5.h"
#include "QPictureLabel.hpp"
InstructionScreen5::InstructionScreen5(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreen5)
{
    ui->setupUi(this);

    QPictureLabel *lbl = new QPictureLabel(ui->frame);
    lbl->setPixmap(QPixmap(":/ui/decrypt_1"));
    ui->frame->layout()->addWidget(lbl);
}

InstructionScreen5::~InstructionScreen5()
{
    delete ui;
}
