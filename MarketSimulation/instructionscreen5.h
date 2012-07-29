#ifndef INSTRUCTIONSCREEN5_H
#define INSTRUCTIONSCREEN5_H

#include <QWidget>

namespace Ui {
class InstructionScreen5;
}

class InstructionScreen5 : public QWidget
{
    Q_OBJECT
    
public:
    explicit InstructionScreen5(QWidget *parent = 0);
    ~InstructionScreen5();
    
private:
    Ui::InstructionScreen5 *ui;
};

#endif // INSTRUCTIONSCREEN5_H
