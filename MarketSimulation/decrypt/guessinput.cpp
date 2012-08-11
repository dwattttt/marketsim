#include "guessinput.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QWidget>
#include <QSpacerItem>
#include <QFontMetrics>

#include "decryptionwindow.h"
GuessInput::GuessInput(QObject *parent, QGridLayout *layout, QString word, SubstitutionCipher *cipher)
    : QObject(parent)
{
    this->guessWord = word;
    this->subCipher = cipher;

    // Lay out a ciphered label and text field for each letter in the word to be guessed
    for(int i = 0; i < word.length();i++)
    {
        QLabel *letterLabel = new QLabel(cipher->ReverseMap(word[i]).toUpper());
        QLineEdit *entryField = new QLineEdit();
        entryField->setFixedSize(20,20);
        QWidget *layoutContainer = new QWidget();
        QGridLayout *subLayout = new QGridLayout();
        QSpacerItem *spacer = new QSpacerItem(30,20);
        subLayout->addWidget(letterLabel,0,0);
        subLayout->addWidget(entryField,1,0);
        subLayout->addItem(spacer,0, 1, 1, 2);
        layoutContainer->setLayout(subLayout);
        layout->addWidget(layoutContainer,0,i);
        fields.append(entryField); // Keep a reference to the guesses so they can be checked
        connect(entryField,SIGNAL(textChanged(QString)), this, SLOT(FieldChanged(QString)));
        entryField->setMaxLength(1);
    }
}


bool GuessInput::Validate()
{
    QVector<QLineEdit*> invalidList;

    QPalette white;
    white.setColor(fields[0]->backgroundRole(), QColor(255,255,255));
    QPalette red;
    red.setColor(fields[0]->backgroundRole(), QColor(255,220,220));

    for(int i = 0; i < guessWord.length(); i++)
    {
        if (guessWord[i].toLower() != fields[i]->text()[0].toLower())
        {
            fields[i]->setPalette(red);
            invalidList.append(fields[i]);
        }
        else
        {
            fields[i]->setPalette(white);
        }
    }

    // TODO highlight invalid guesses rather than just returning true/false
    return invalidList.count() == 0 ? true : false;
}

void GuessInput::FieldChanged(QString text)
{
    Validate();
}

void GuessInput::Disable()
{
    foreach (QLineEdit *field, fields)
    {
        field->setEnabled(false);
    }
}
