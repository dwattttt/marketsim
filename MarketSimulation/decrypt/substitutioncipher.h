#ifndef SUBSTITUTIONCIPHER_H
#define SUBSTITUTIONCIPHER_H

#include <QChar>
#include <QVector>
#include <QPair>

typedef QPair<QChar,QChar> CharMapping;

class SubstitutionCipher
{
public:
	explicit SubstitutionCipher();
	QChar Map(QChar conv);
	QChar ReverseMap(QChar conv);
    QVector<CharMapping> AllMappings();

private:
    QVector<CharMapping> mapping;
};

#endif // SUBSTITUTIONCIPHER_H
