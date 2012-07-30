#ifndef WORDLIST_H
#define WORDLIST_H

#include <QString>
#include <QVector>
class WordList
{
public:
	// Construct, store dictionary path for later consumption
    explicit            WordList(const QString path);
    QVector<QString>    Generate(int minLength, int maxLength);
private:
	QString	dictPath;
};
#endif // WORDLIST_H
