#include "titlescreen.h"
#include "ui_titlescreen.h"

TitleScreen::TitleScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleScreen)
{
    ui->setupUi(this);

#ifndef QT_NO_DEBUG
    ui->label->setText(QString("This is the debugging version of this software. Please use the release version for actual testing..."));
#endif
}

TitleScreen::~TitleScreen()
{
    delete ui;
}
