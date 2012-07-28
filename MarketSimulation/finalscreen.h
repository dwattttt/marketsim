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
    
private:
    Ui::finalscreen *ui;
};

#endif // FINALSCREEN_H
