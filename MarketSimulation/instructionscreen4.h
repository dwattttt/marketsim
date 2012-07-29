#ifndef INSTRUCTIONSCREEN4_H
#define INSTRUCTIONSCREEN4_H

#include <QWidget>

namespace Ui {
class InstructionScreen4;
}

class InstructionScreen4 : public QWidget
{
    Q_OBJECT
    
public:
    explicit InstructionScreen4(QWidget *parent = 0);
    ~InstructionScreen4();
    
private:
    Ui::InstructionScreen4 *ui;
};

#endif // INSTRUCTIONSCREEN4_H
