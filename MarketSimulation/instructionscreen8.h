#ifndef INSTRUCTIONSCREEN8_H
#define INSTRUCTIONSCREEN8_H

#include <QWidget>

namespace Ui {
class InstructionScreen8;
}

class InstructionScreen8 : public QWidget
{
    Q_OBJECT
    
public:
    explicit InstructionScreen8(QWidget *parent = 0);
    ~InstructionScreen8();
    
private:
    Ui::InstructionScreen8 *ui;
};

#endif // INSTRUCTIONSCREEN8_H
