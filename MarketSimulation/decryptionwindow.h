#ifndef DECRYPTIONWINDOW_H
#define DECRYPTIONWINDOW_H

#include <QWidget>
#include <QVector>
#include <QString>
#include "market.h"
#include "decrypt/substitutioncipher.h"
#include "decrypt/wordlist.h"
#include "decrypt/guessinput.h"

namespace Ui {
class DecryptionWindow;
}

class DecryptionWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit DecryptionWindow(Market* market, QWidget *parent = 0);
    ~DecryptionWindow();
    int GetScore();
    static const int MIN_DECRYPTION_LEN = 3;
    static const int MAX_DECRYPTION_LEN = 4;

private:
    void ResetTask();
    Ui::DecryptionWindow *ui;

    int score;
    QVector<QString> wordyStuff;
    SubstitutionCipher *cipher;
    GuessInput *input;
    Market* market;

private slots:
    void DoneClicked();
};

#endif // DECRYPTIONWINDOW_H
