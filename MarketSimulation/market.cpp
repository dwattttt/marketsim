#include "market.h"

#include <cmath>
#include <QByteArray>
#include <QMessageBox>
#include <QDateTime>
#include <QTime>

Market::Market(QString storedPathFile, QObject *parent, int evolveTimeMS) :
    QObject(parent)
{
    bool ok;

    // We're using a stored price path
    usingStoredPath = true;
    storedPath = new QFile(storedPathFile);
    ok = storedPath->open(QIODevice::ReadOnly);

    if (!ok)
    {
        // We've failed to load the market path. Have to fail
        QMessageBox::critical(0,"Error","Unable to load prices");
        exit(EXIT_FAILURE);
    }

    // Initial parameters
    allocation = .5;
    wealth = 10;

    // Load the first prices
    loadNextPriceFromFile();

    // Set up the log files
    QString logFileName = "Experiment" + QDateTime::currentDateTime().toString(" - MM-dd hh.mm.txt");
    logFile = new QFile(logFileName);
    ok = logFile->open(QIODevice::WriteOnly | QIODevice::Text);
    QString swapLogFileName = "Experiment Swaps" + QDateTime::currentDateTime().toString(" - MM-dd hh.mm.txt");
    swapLogFile = new QFile(swapLogFileName);
    ok = ok && swapLogFile->open(QIODevice::WriteOnly | QIODevice::Text);

    if (!ok)
    {
        // We've failed to open a log file for writing. wtf.
        QMessageBox::critical(0,"Error","Unable to write log file");
        exit(EXIT_FAILURE);
    }

    // Set up the time
    experimentTime = new QTime();

    // Set up the timers
    evolveTimer = new QTimer(this);
    evolveTimer->setInterval(evolveTimeMS);
    evolveTimer->setSingleShot(false);
    timeTimer = new QTimer(this);
    timeTimer->setInterval(1000);
    timeTimer->setSingleShot(false);
    connect(evolveTimer, SIGNAL(timeout()), this, SLOT(updatePrice()));
    connect(timeTimer, SIGNAL(timeout()), this, SLOT(updateTime()));
}

Market::~Market()
{
    delete experimentTime;

    delete evolveTimer;
    delete storedPath;

    delete logFile;
}

void Market::startMarket()
{
    evolveTimer->start();
    timeTimer->start();
    experimentTime->start();
}

double Market::getPrice1()
{
    return price1;
}

double Market::getPrice2()
{
    return price2;
}

double Market::getWealth()
{
    return wealth;
}

double Market::getAllocation()
{
    return allocation;
}


void Market::updatePrice()
{
    if (usingStoredPath)
    {
        // Load next prices from the stored data
        loadNextPriceFromFile();
    } else {
        // Calculate next prices
        std::pair<double, double> dW = dWienerSample();
        price1 *= exp((mu1-(sigma1*sigma1)/2)*dt+sigma1*dW.first);
        price2 *= exp((mu2-(sigma2*sigma2)/2)*dt+sigma2*dW.second);
    }

    // Calculate new total wealth
    wealth = shares1*price1 + shares2*price2;

    recordData(false);
    emit priceChange(experimentTime->elapsed()/1000);
}

void Market::updateAllocation(double newAllocation)
{
    allocation = newAllocation;

    shares2 = wealth/(price1 * (allocation/(1-allocation)) + price2);
    shares1 = (wealth - shares2*price2)/price1;
}

std::pair<double, double> Market::dWienerSample()
{
    std::pair<double, double> dW;
    std::pair<double, double> Z = stdNormalSample();
    dW.first = sqrt(dt)*Z.first;
    dW.second = sqrt(dt)*Z.second;
    return dW;
}

std::pair<double, double> Market::stdNormalSample()
{
    // Box-Muller transform
    unsigned int I1 = rand() + 1;
    unsigned int I2 = rand() + 1;
    double U1 = I1 / (RAND_MAX + 1.0);
    double U2 = I2 / (RAND_MAX + 1.0);

    double Z1 = sqrt(-2*log(U1))*cos(2*atan2(0.0,-1.0)*U2);
    double Z2 = sqrt(-2*log(U1))*sin(2*atan2(0.0,-1.0)*U2);

    std::pair<double, double> Z;
    Z.first = Z1;
    Z.second = Z2;

    return Z;
}

void Market::loadNextPriceFromFile()
{
    if (!usingStoredPath)
    {
        QMessageBox::critical(0, "Error", "Attempted to load price from file when not using stored data");
        exit(EXIT_FAILURE);
    }

    bool ok1, ok2;
    QByteArray priceLine = storedPath->readLine().trimmed();
    QList<QByteArray> priceStrings = priceLine.split(',');
    price1 = priceStrings.at(0).toDouble(&ok1);
    price2 = priceStrings.at(1).toDouble(&ok2);

    if (!(ok1 && ok2))
    {
        QMessageBox::critical(0, "Error", "Corrupted data file");
        exit(EXIT_FAILURE);
    }
}

void Market::recordData(bool async, bool simWindow)
{
    // Record allocation
    QByteArray data;
    int expTime = experimentTime->elapsed();
    data.append(QString::number(expTime) + "," + QString::number(wealth) + "," + QString::number(allocation) + "\n");
    logFile->write(data);
    logFile->flush();

    if (async)
    {
        // This was called because the user swapped screens; record this event
        data.clear();
        if (simWindow)
        {
            data.append(QString::number(expTime) + ",Simulation\n");
        } else {
            data.append(QString::number(expTime) + ",Decryption\n");
        }
        swapLogFile->write(data);
        swapLogFile->flush();
    }
}

void Market::updateTime()
{
    //int secondsLeft = (20*60) - experimentTime->elapsed()/1000;
    int secondsLeft = EXPERIMENT_RUNNING_TIME - round(experimentTime->elapsed()/1000.0);
    int minLeftMod = secondsLeft / 60;
    int secondsLeftMod = secondsLeft % 60;
    QString secStr;
    QString minStr;

    if (secondsLeftMod < 10) {
        secStr = "0" + QString::number(secondsLeftMod);
    } else {
        secStr = QString::number(secondsLeftMod);
    }
    if (minLeftMod < 10) {
        minStr = "0" + QString::number(minLeftMod);
    } else {
        minStr = QString::number(minLeftMod);
    }

    if (secondsLeft < 0) {
        emit newTime("");
    }
    else {
        emit newTime(minStr + ":" + secStr);
    }

}
