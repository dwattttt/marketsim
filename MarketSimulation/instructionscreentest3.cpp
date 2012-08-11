#include "instructionscreentest3.h"
#include "ui_instructionscreentest3.h"
#include "decryptionwindow.h"

InstructionScreenTest3::InstructionScreenTest3(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InstructionScreenTest3)
{
    ui->setupUi(this);

    QVector<QString> testWords;
    testWords.append(QString("dog"));

    win = new DecryptionWindow(NULL,this,testWords);
    ui->decryptionWidget->layout()->addWidget(win);

    connect(win,SIGNAL(DecryptionCompleted()),this,SLOT(DisableOnDecryptionComplete()));
}

InstructionScreenTest3::~InstructionScreenTest3()
{
    delete ui;
}

void InstructionScreenTest3::DisableOnDecryptionComplete()
{
    win->Disable();
}
