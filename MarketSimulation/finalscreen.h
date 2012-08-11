#ifndef FINALSCREEN_H
#define FINALSCREEN_H

#include <QWidget>

namespace Ui {
class finalscreen;
}

class FinalScreen : public QWidget
{
    Q_OBJECT
    
public:
    explicit FinalScreen(QWidget *parent = 0);
    ~FinalScreen();
    void Populate(double investmentValue, int decryptionsCompleted);
    static const double DECRYPTION_VALUE = 0.15;
private:
    Ui::finalscreen *ui;
};

#endif // FINALSCREEN_H
