#ifndef MARKETINDEXWIDGET_H
#define MARKETINDEXWIDGET_H

#include <QWidget>

namespace Ui {
class MarketIndexWidget;
}

class MarketIndexWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit MarketIndexWidget(QWidget *parent = 0);
    ~MarketIndexWidget();

public slots:
    void IndexChanged(double index, double indexChangePct);
private:
    Ui::MarketIndexWidget *ui;
};

#endif // MARKETINDEXWIDGET_H
