#ifndef SIMULATIONWINDOW_H
#define SIMULATIONWINDOW_H

#include <QWidget>
#include "market.h"

namespace Ui {
class SimulationWindow;
}

class SimulationWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit SimulationWindow(Market *market, QWidget *parent);
    ~SimulationWindow();
    void initAllocation();

private:
    Ui::SimulationWindow *ui;

    // Pointer to the main market
    Market* market;

private slots:
    void updatePrices(double time);
    void updateAllocation(double newAllocation);
};

#endif // SIMULATIONWINDOW_H
