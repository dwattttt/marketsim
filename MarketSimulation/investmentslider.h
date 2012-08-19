#ifndef INVESTMENTSLIDER_H
#define INVESTMENTSLIDER_H

#include <QWidget>

namespace Ui {
class investmentSlider;
}

class investmentSlider : public QWidget
{
    Q_OBJECT
    
public:
    explicit investmentSlider(QWidget *parent = 0);
    void setAllocation(double newAllocation);
    void toggleDummyBar(bool toggle);
    ~investmentSlider();
private:
    Ui::investmentSlider *ui;
    double calculateAllocation();
    double allocation;
private slots:
    void allocationChanged();
    void allocationLockedIn();

signals:
    void allocationUpdated(double firstAllocation);

public slots:
    void updatePrices(double price1, double price2);
    void updateAllocation(double firstAllocation);
    void updateWealth(double newWealth);
};

#endif // INVESTMENTSLIDER_H
