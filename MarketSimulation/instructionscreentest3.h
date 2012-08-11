#ifndef INSTRUCTIONSCREENTEST3_H
#define INSTRUCTIONSCREENTEST3_H

#include <QWidget>
#include "decryptionwindow.h"

namespace Ui {
class InstructionScreenTest3;
}

class InstructionScreenTest3 : public QWidget
{
    Q_OBJECT
    
public:
    explicit InstructionScreenTest3(QWidget *parent = 0);
    DecryptionWindow *win;
    ~InstructionScreenTest3();
    
private:
    Ui::InstructionScreenTest3 *ui;

private slots:
    void DisableOnDecryptionComplete();
};

#endif // INSTRUCTIONSCREENTEST3_H
