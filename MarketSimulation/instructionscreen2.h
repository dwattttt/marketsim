#ifndef INSTRUCTIONSCREEN2_H
#define INSTRUCTIONSCREEN2_H

#include <QWidget>

namespace Ui {
class InstructionScreen2;
}

class InstructionScreen2 : public QWidget
{
    Q_OBJECT
    
public:
    explicit InstructionScreen2(QWidget *parent = 0);
    ~InstructionScreen2();
    
private:
    Ui::InstructionScreen2 *ui;
};

#endif // INSTRUCTIONSCREEN2_H
