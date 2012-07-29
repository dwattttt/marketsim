#ifndef INSTRUCTIONSCREEN1_H
#define INSTRUCTIONSCREEN1_H

#include <QWidget>

namespace Ui {
class InstructionScreen1;
}

class InstructionScreen1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit InstructionScreen1(QWidget *parent = 0);
    ~InstructionScreen1();
    
private:
    Ui::InstructionScreen1 *ui;
};

#endif // INSTRUCTIONSCREEN1_H
