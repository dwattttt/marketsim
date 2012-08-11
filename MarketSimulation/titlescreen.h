#ifndef TITLESCREEN_H
#define TITLESCREEN_H

#include <QWidget>
#include <QString>

namespace Ui {
class TitleScreen;
}

class TitleScreen : public QWidget
{
    Q_OBJECT
    
public:
    explicit TitleScreen(QWidget *parent = 0);
    ~TitleScreen();
    
private:
    Ui::TitleScreen *ui;
};

#endif // TITLESCREEN_H
