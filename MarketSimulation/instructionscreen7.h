#ifndef INSTRUCTIONSCREEN7_H
#define INSTRUCTIONSCREEN7_H

#include <QWidget>

namespace Ui {
class InstructionScreen7;
}

class InstructionScreen7 : public QWidget
{
    Q_OBJECT
    
public:
    explicit InstructionScreen7(QWidget *parent = 0);
    ~InstructionScreen7();
    
private:
    Ui::InstructionScreen7 *ui;
};

#endif // INSTRUCTIONSCREEN7_H
