#ifndef GUESSINPUT_H
#define GUESSINPUT_H

#include <QObject>
#include <QVector>
#include <QLineEdit>
#include <QGridLayout>
#include "decrypt/substitutioncipher.h"

class GuessInput : public QObject
{
    Q_OBJECT

public:
    explicit    GuessInput(QObject *parent, QGridLayout *layout, QString word, SubstitutionCipher *cipher);
    bool        Validate();

private:
    QString guessWord;
    SubstitutionCipher *subCipher;
    QVector<QLineEdit*> fields;

private slots:
    void    FieldChanged(QString text);
};

#endif // GUESSINPUT_H
