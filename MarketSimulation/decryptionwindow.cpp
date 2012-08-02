#include "decryptionwindow.h"
#include "ui_decryptionwindow.h"
#include <QGridLayout>
#include <QLayoutItem>
#include <QLabel>
#include <QVBoxLayout>

DecryptionWindow::DecryptionWindow(Market* market, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DecryptionWindow)
{
    ui->setupUi(this);

    connect(ui->btnSubmit, SIGNAL(clicked()), this, SLOT(DoneClicked()));

    score = 0;
    wordyStuff = WordList(":/dictionary")
            .Generate(MIN_DECRYPTION_LEN,MAX_DECRYPTION_LEN);
    ResetTask();
}

void DeleteGridChildren(QGridLayout *grid)
{
    QLayoutItem  *child;
    while ((child = grid->takeAt(0)) != 0) {
        child->widget()->deleteLater();
    }
}

void DecryptionWindow::ResetTask()
{
    ui->lblScore->setText(QString("%1").arg(score));

    // TODO delete old cipher if exists
    cipher = new SubstitutionCipher();

    // clear old grid if it exists
    DeleteGridChildren(ui->keyGrid);

    // Step through all cipher mappings and display a key in grid format
    QVector<CharMapping> mappings = cipher->AllMappings();
    int count = 0;
    foreach(CharMapping map, mappings)
    {
        QLabel *nextLbl = new QLabel(QString("%1 : %2").arg(map.first, map.second));
        ui->keyGrid->addWidget(nextLbl, count / 5, count % 5);
        count++;
    }

    // TODO delete old input if exists
    DeleteGridChildren(ui->guessGrid);
    input = new GuessInput(this, ui->guessGrid, wordyStuff[score], cipher);

    input->Validate();
}

void DecryptionWindow::DoneClicked()
{
    bool isCorrect = input->Validate();

    if (isCorrect)
    {
        score++;
        ResetTask();
    }

}

int DecryptionWindow::GetScore()
{
    return score;
}

DecryptionWindow::~DecryptionWindow()
{
    delete ui;
}

