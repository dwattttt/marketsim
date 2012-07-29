#ifndef INITIALALLOCATIONSCREEN_H
#define INITIALALLOCATIONSCREEN_H

#include <QWidget>

namespace Ui {
class InitialAllocationScreen;
}

class InitialAllocationScreen : public QWidget
{
    Q_OBJECT
    
public:
    explicit InitialAllocationScreen(QWidget *parent = 0);
    ~InitialAllocationScreen();
    
private:
    Ui::InitialAllocationScreen *ui;
};

#endif // INITIALALLOCATIONSCREEN_H
