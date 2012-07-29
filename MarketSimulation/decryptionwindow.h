#ifndef DECRYPTIONWINDOW_H
#define DECRYPTIONWINDOW_H

#include <QWidget>
#include "market.h"

namespace Ui {
class DecryptionWindow;
}

class DecryptionWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit DecryptionWindow(Market* market, QWidget *parent = 0);
    ~DecryptionWindow();
    
private:
    Ui::DecryptionWindow *ui;

    Market* market;
};

#endif // DECRYPTIONWINDOW_H
