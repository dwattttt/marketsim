#ifndef INSTRUCTIONSCREENTEST1_H
#define INSTRUCTIONSCREENTEST1_H

#include <QWidget>

namespace Ui {
class InstructionScreenTest1;
}

class InstructionScreenTest1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit InstructionScreenTest1(QWidget *parent = 0);
    ~InstructionScreenTest1();
    
private:
    Ui::InstructionScreenTest1 *ui;

    const static double price1 = 5;
    const static double price2 = 5;
    const static double wealth = 10.0;

signals:
    void        testPassed();

private slots:
    void updatePrices();
    void displayAllocation();
    void updateAllocation();
};

#endif // INSTRUCTIONSCREENTEST1_H
