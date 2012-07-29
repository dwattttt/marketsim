#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create our market
    market = new Market("data.dat",this,2000);

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

    pos = widgets->begin();
    ui->stackedWidget->setCurrentWidget(*pos);

    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(nextScreen()));
    connect(ui->prevButton, SIGNAL(clicked()), this, SLOT(prevScreen()));


    market->startMarket();

    connect(market, SIGNAL(newTime(QString)), this, SLOT(updateTime(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::nextScreen()
{
    if (pos != widgets->end()) {
        pos++;
        ui->stackedWidget->setCurrentWidget(*pos);
    }
}

void MainWindow::prevScreen()
{
    if (pos != widgets->begin()) {
        pos--;
        ui->stackedWidget->setCurrentWidget(*pos);
    }
}

void MainWindow::updateTime(QString timeString)
{
    ui->timeLabel->setText(timeString);
}
