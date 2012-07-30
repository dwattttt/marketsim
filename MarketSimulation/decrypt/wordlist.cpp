#include "wordlist.h"
#include <QString>
#include <QVector>
#include <QRegExp>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>
#include <ctime>
#include <algorithm>


WordList::WordList(const QString path)
{
	this->dictPath = path;
}


// Attempts to load the dictionary file.
// If something goes wrong the method will directly notify the user and abort.
QVector<QString> LoadFile(QString path)
{
    bool ok;

    QFile file(path);
    ok = file.open(QIODevice::ReadOnly);

    if (!ok)
    {
        // We've failed to load the dictionary. Have to fail
        QMessageBox::critical(0,"Error","Unable to load decryption dictionary");
        exit(1);
    }

    QVector<QString> words;

    // Read in line-by-line, regex pattern accepts all single non-hyphenated words
    QTextStream in(&file);
    QString line;
    QRegExp rx("^[anv] \\[(\\w+)\\%");
    do
    {
        line = in.readLine();
        if (rx.indexIn(line) != -1)
        {
            words.append(rx.cap(1));
        }
    } while (!line.isNull());

    return words;
}

QVector<QString> WordList::Generate(int minLength, int maxLength)
{
    QVector<QString> allWords = LoadFile(this->dictPath);
    QVector<QString> filterWords;
	
	QString word;
	foreach(word, allWords)
	{
		if (word.count() < minLength) continue;
		if (word.count() > maxLength) continue;
		
		filterWords.append(word);
	}

    // Assumes srand called at program init
    std::random_shuffle(filterWords.begin(), filterWords.end());
	
	return filterWords;
}
