#include "substitutioncipher.h"
#include <QChar>
#include <QMap>
#include <QVector>
#include <QString>
#include <QMessageBox>
#include <algorithm>

SubstitutionCipher::SubstitutionCipher()
{
    QString original("abcdefghijklmnopqrstuvwxyz");
	
    QVector<int> mapList;
	
	for(int i = 0; i < original.length(); i++)
	{
		mapList.append(i);
	}
	
    // Assumes srand called at program init
    std::random_shuffle(mapList.begin(), mapList.end());
	
	for(int i = 0; i < original.length(); i++)
	{
        mapping.append(
                    QPair<QChar,QChar>(original[i], original[mapList[i]])
                    );
	}
}

QChar SubstitutionCipher::Map(QChar conv)
{
    foreach(CharMapping mapPair, mapping)
    {
        if (mapPair.first == conv.toLower())
        {
            if (conv.isUpper())
                return mapPair.second.toUpper();
            else
                return mapPair.second;
        }
    }

    QMessageBox::critical(0,"Error","Unable to find appropriate decryption mapping");
    exit(1);
}

QChar SubstitutionCipher::ReverseMap(QChar conv)
{
    foreach(CharMapping mapPair, mapping)
    {
        if (mapPair.second == conv.toLower())
        {
            if (conv.isUpper())
                return mapPair.first.toUpper();
            else
                return mapPair.first;
        }
    }
	
	QMessageBox::critical(0,"Error","Unable to find appropriate decryption mapping");
    exit(1);
}

QVector<CharMapping> SubstitutionCipher::AllMappings()
{
    QVector<CharMapping> rtn(mapping);
    std::random_shuffle(rtn.begin(), rtn.end());

    return rtn;
}
