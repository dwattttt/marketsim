#include "marketindexwidget.h"
#include "ui_marketindexwidget.h"
#include <QString>

MarketIndexWidget::MarketIndexWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MarketIndexWidget)
{
    ui->setupUi(this);
    IndexChanged(100.0, 0.0);
}

MarketIndexWidget::~MarketIndexWidget()
{
    delete ui;
}

void MarketIndexWidget::IndexChanged(double index, double indexChangePct)
{
    ui->lblIndex->setText(QString::number(index, 'f', 1));
    if (indexChangePct == 0)
    {
        ui->lblIndexChange->setText("");
        ui->lblIndexImage->setPixmap(NULL);
    }
    else
    {
        ui->lblIndexChange->setText(QString::number(indexChangePct,'f',1) + QString("%"));

        if (indexChangePct > 0)
        {
            ui->lblIndexImage->setPixmap(QPixmap(":/ui/arrow-up"));
            ui->lblIndexChange->setStyleSheet("QLabel { color: green }");
        }
        else
        {
            ui->lblIndexImage->setPixmap(QPixmap(":/ui/arrow-down"));
            ui->lblIndexChange->setStyleSheet("QLabel { color: red }");
        }
    }
}
