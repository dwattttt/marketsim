#ifndef INSTRUCTIONSCREEN6_H
#define INSTRUCTIONSCREEN6_H

#include <QWidget>

namespace Ui {
class InstructionScreen6;
}

class InstructionScreen6 : public QWidget
{
    Q_OBJECT
    
public:
    explicit InstructionScreen6(QWidget *parent = 0);
    ~InstructionScreen6();
    
private:
    Ui::InstructionScreen6 *ui;
};

#endif // INSTRUCTIONSCREEN6_H
