#ifndef MARKET_H
#define MARKET_H

#include <QObject>
#include <QTimer>
#include <QFile>
#include <QTime>

class Market : public QObject
{
    Q_OBJECT
public:
    explicit    Market(QString storedPathFile, QObject *parent = 0,
                       int evolveTimeMS = 2000);
    virtual     ~Market();

    double      getPrice1();
    double      getPrice2();
    double      getWealth();
    double      getAllocation();

    void        updateAllocation(double newAllocation);

    void        recordData(bool async, bool simWindow = true);

    void        startMarket();
signals:
    void        priceChange();
    void        newTime(QString);

public slots:

private:
    bool        usingStoredPath;

    double      price1;
    double      mu1;
    double      sigma1;
    double      price2;
    double      mu2;
    double      sigma2;
    double      dt;

    double      allocation;
    double      shares1;
    double      shares2;
    double      wealth;

    QTime*      experimentTime;

    QTimer*     timeTimer;
    QTimer*     evolveTimer;
    QFile*      storedPath;

    QFile*      logFile;
    QFile*      swapLogFile;

    std::pair<double, double> dWienerSample();
    std::pair<double, double> stdNormalSample();

    void        loadNextPriceFromFile();

private slots:
    void        updatePrice();
    void        updateTime();
};

#endif // MARKET_H
