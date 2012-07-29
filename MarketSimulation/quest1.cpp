#include "quest1.h"
#include "ui_quest1.h"

QuestionScreen1::QuestionScreen1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::quest1)
{
    ui->setupUi(this);
}

QuestionScreen1::~QuestionScreen1()
{
    delete ui;
}
