#ifndef INSTRUCTIONSCREEN3_H
#define INSTRUCTIONSCREEN3_H

#include <QWidget>

namespace Ui {
class InstructionScreen3;
}

class InstructionScreen3 : public QWidget
{
    Q_OBJECT
    
public:
    explicit InstructionScreen3(QWidget *parent = 0);
    ~InstructionScreen3();
    
private:
    Ui::InstructionScreen3 *ui;
};

#endif // INSTRUCTIONSCREEN3_H
