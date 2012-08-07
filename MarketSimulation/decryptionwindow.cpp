#include "decryptionwindow.h"
#include "ui_decryptionwindow.h"
#include <QGridLayout>
#include <QLayoutItem>
#include <QLabel>
#include <QVBoxLayout>
#include <QMessageBox>

DecryptionWindow::DecryptionWindow(Market* market, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DecryptionWindow)
{
    ui->setupUi(this);

    this->market = market;
    QString decryptsFileName = "Decrypts " + QDateTime::currentDateTime().toString(" - MM-dd hh.mm.txt");
    decryptsFile = new QFile(decryptsFileName);
    bool ok = decryptsFile->open(QIODevice::WriteOnly | QIODevice::Text);

    if (!ok)
    {
        // We've failed to open a log file for writing. wtf.
        QMessageBox::critical(0,"Error","Unable to write user decryptions file");
        exit(EXIT_FAILURE);
    }

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
    QVector<CharMapping> mappings = cipher->AllMappings(RANDOMIZE_KEYS);
    int count = 0;
    foreach(CharMapping map, mappings)
    {
        QLabel *nextLbl = new QLabel(QString("%1 : %2").arg(map.first.toUpper(), map.second.toUpper()));
        ui->keyGrid->addWidget(nextLbl, count % 5, count / 5);
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

        QByteArray data;
        int expTime = market->experimentTime->elapsed();
        data.clear();
        data.append(QString::number(expTime) + "\n");
        decryptsFile->write(data);
        decryptsFile->flush();
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

