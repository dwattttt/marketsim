#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QCloseEvent>
#include "market.h"
#include "simulationwindow.h"
#include "decryptionwindow.h"
#include "instructionscreen1.h"
#include "instructionscreen2.h"
#include "instructionscreen3.h"
#include "instructionscreen4.h"
#include "instructionscreen5.h"
#include "instructionscreen6.h"
#include "instructionscreen7.h"
#include "instructionscreen8.h"
#include "instructionscreentest1.h"
#include "instructionscreentest2.h"
#include "instructionscreentest3.h"
#include "quest1.h"
#include "finalscreen.h"
#include "titlescreen.h"
#include "initialallocationscreen.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QList<QWidget*>*    widgets;
    QList<QWidget*>::iterator pos;

    Market*             market;
    SimulationWindow*   sim;
    DecryptionWindow*   dec;
    InstructionScreen1* inst1;
    InstructionScreen2* inst2;
    InstructionScreen3* inst3;
    InstructionScreen4* inst4;
    InstructionScreen5* inst5;
    InstructionScreen6* inst6;
    InstructionScreen7* inst7;
    InstructionScreen8* inst8;
    InstructionScreenTest1* instTest1;
    InstructionScreenTest2* instTest2;
    InstructionScreenTest3* instTest3;
    TitleScreen*        title;
    InitialAllocationScreen* initAlloc;
    QuestionScreen1* quest1;
    FinalScreen* fin;

    bool simStarted;
    bool simRunning;
    bool finishedExperiment;
    bool test1Passed;
    bool test2Passed;

    // To make sure users can't exit until they've finished the experiment
    void closeEvent(QCloseEvent *);

private slots:
    void preNavigation();
    void nextScreen();
    void prevScreen();
    void updateTime(QString timeString);
    void passTest1();
    void passTest2();
};

#endif // MAINWINDOW_H
