#include "decryptionwindow.h"
#include "ui_decryptionwindow.h"

DecryptionWindow::DecryptionWindow(Market* market, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DecryptionWindow)
{
    ui->setupUi(this);
}

DecryptionWindow::~DecryptionWindow()
{
    delete ui;
}
