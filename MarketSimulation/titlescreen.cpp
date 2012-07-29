#include "titlescreen.h"
#include "ui_titlescreen.h"

TitleScreen::TitleScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TitleScreen)
{
    ui->setupUi(this);
}

TitleScreen::~TitleScreen()
{
    delete ui;
}
