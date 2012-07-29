#ifndef INSTRUCTIONSCREENTEST3_H
#define INSTRUCTIONSCREENTEST3_H

#include <QWidget>

namespace Ui {
class InstructionScreenTest3;
}

class InstructionScreenTest3 : public QWidget
{
    Q_OBJECT
    
public:
    explicit InstructionScreenTest3(QWidget *parent = 0);
    ~InstructionScreenTest3();
    
private:
    Ui::InstructionScreenTest3 *ui;
};

#endif // INSTRUCTIONSCREENTEST3_H
