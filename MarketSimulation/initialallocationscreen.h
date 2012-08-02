#ifndef INITIALALLOCATIONSCREEN_H
#define INITIALALLOCATIONSCREEN_H

#include <QWidget>
#include "market.h"

namespace Ui {
class InitialAllocationScreen;
}

class InitialAllocationScreen : public QWidget
{
    Q_OBJECT
    
public:
    explicit InitialAllocationScreen(Market *market, QWidget *parent = 0);
    ~InitialAllocationScreen();
    
private:
    Ui::InitialAllocationScreen *ui;

    // Pointer to the main market
    Market* market;

private slots:
    void updatePrices();
    void displayAllocation();
    void updateAllocation();

};

#endif // INITIALALLOCATIONSCREEN_H
