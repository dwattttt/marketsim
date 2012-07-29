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
};

#endif // INSTRUCTIONSCREENTEST1_H
