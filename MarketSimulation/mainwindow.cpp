#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create our market
    market = new Market(":/market-data",this,2000);

    // Create the windows
    sim = new SimulationWindow(market, 0);
    dec = new DecryptionWindow(market, 0);
    title = new TitleScreen(0);
    inst1 = new InstructionScreen1(0);
    inst2 = new InstructionScreen2(0);
    inst3 = new InstructionScreen3(0);
    inst4 = new InstructionScreen4(0);
    inst5 = new InstructionScreen5(0);
    inst6 = new InstructionScreen6(0);
    inst7 = new InstructionScreen7(0);
    inst8 = new InstructionScreen8(0);
    instTest1 = new InstructionScreenTest1(0);
    instTest2 = new InstructionScreenTest2(0);
    instTest3 = new InstructionScreenTest3(0);
    initAlloc = new InitialAllocationScreen(0);
    quest1 = new QuestionScreen1(0);
    fin = new FinalScreen(0);

    ui->stackedWidget->addWidget(title);
    ui->stackedWidget->addWidget(inst1);
    ui->stackedWidget->addWidget(inst2);
    ui->stackedWidget->addWidget(inst3);
    ui->stackedWidget->addWidget(inst4);
    ui->stackedWidget->addWidget(inst5);
    ui->stackedWidget->addWidget(inst6);
    ui->stackedWidget->addWidget(inst7);
    ui->stackedWidget->addWidget(inst8);
    ui->stackedWidget->addWidget(instTest1);
    ui->stackedWidget->addWidget(instTest2);
    ui->stackedWidget->addWidget(instTest3);
    ui->stackedWidget->addWidget(initAlloc);
    ui->stackedWidget->addWidget(sim);
    ui->stackedWidget->addWidget(dec);
    ui->stackedWidget->addWidget(quest1);
    ui->stackedWidget->addWidget(fin);


    // Make a list of widget pointers, so we can easily swap between them
    widgets = new QList<QWidget*>();
    widgets->push_back(title);
    widgets->push_back(inst1);
    widgets->push_back(inst2);
    widgets->push_back(inst3);
    widgets->push_back(instTest1);
    widgets->push_back(instTest2);
    widgets->push_back(inst4);
    widgets->push_back(inst5);
    widgets->push_back(inst6);
    widgets->push_back(inst7);
    widgets->push_back(instTest3);
    widgets->push_back(inst8);
    widgets->push_back(initAlloc);
    widgets->push_back(sim);
    widgets->push_back(dec);
    widgets->push_back(quest1);
    widgets->push_back(fin);

    pos = widgets->begin();
    ui->stackedWidget->setCurrentWidget(*pos);
    preNavigation();

    simStarted = false;
    finishedExperiment = false;

    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(nextScreen()));
    connect(ui->prevButton, SIGNAL(clicked()), this, SLOT(prevScreen()));

    connect(market, SIGNAL(newTime(QString)), this, SLOT(updateTime(QString)));
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->showFullScreen();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::preNavigation() {

    ui->prevButton->setEnabled(true);
    ui->nextButton->setEnabled(true);
    ui->timeLabel->setVisible(true);
    ui->timeLabelDesc->setVisible(true);
    ui->prevButton->setHidden(false);
    ui->nextButton->setHidden(false);

    //If we're at the start, hide the previous button
    if (pos == widgets->begin()) {
        ui->prevButton->setHidden(true);
    }

    //If we've reached the end, hide both buttons
    if (pos + 1 != widgets->end()) {
    }
    else {
        ui->nextButton->setHidden(true);
        ui->prevButton->setHidden(true);
    }

    //If we've reached the questionaire, hide the previous button
    if (pos + 2 != widgets->end()) {
    }
    else {
        ui->prevButton->setHidden(true);
    }

    //Third last screen is decryption
    //If simulation is running, can't go forward
    if (pos + 3 == widgets->end()) {
        if (simRunning) {
            ui->nextButton->setEnabled(false);
        }
    }

    //Fourth last screen is simulation
    //Can never go back from simulation
    if (pos + 4 == widgets->end()) {

        //If time hasn't run out, the simulation starts now
        if (!simStarted){
            market->startMarket();
            simRunning = true;
            simStarted = true;
        }
        ui->prevButton->setEnabled(false);
    }

    //If the sim isn't running, hide the timer labels
    if (!simRunning) {
        ui->timeLabel->setVisible(false);
        ui->timeLabelDesc->setVisible(false);
    }

}

void MainWindow::nextScreen()
{

    //End() isn't that last item in a list, it's the one after that.
    //(WTF?)
    if (pos + 1 != widgets->end()) {
        pos++;
        preNavigation();
        ui->stackedWidget->setCurrentWidget(*pos);
    }
    // If we're now at the end, allow them to exit

    if (pos + 1 == widgets->end()) {
        finishedExperiment = true;
    }
}

void MainWindow::prevScreen()
{

    if (pos != widgets->begin()) {
        pos--;
        preNavigation();
        ui->stackedWidget->setCurrentWidget(*pos);
    }

}

void MainWindow::updateTime(QString timeString)
{
    ui->timeLabel->setText(timeString);
    if (timeString == "" && simRunning) {
        // We've finished the experiment; show them the last screens.
        simRunning = false;
        pos = widgets->end() - 2;
        preNavigation();
        ui->stackedWidget->setCurrentWidget(*pos);
    }
}

void MainWindow::closeEvent(QCloseEvent* event)
{
    if( ! finishedExperiment )
    {
        event->ignore();
    }
    else
    {
        event->accept();
    }
}