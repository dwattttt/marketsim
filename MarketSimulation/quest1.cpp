#include "quest1.h"
#include "ui_quest1.h"

#ifndef QT_NO_DEBUG
#include <QDebug>
#endif

QuestionScreen1::QuestionScreen1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::quest1)
{
    ui->setupUi(this);
    //connect(ui->submitButton, SIGNAL(poop()), this, SLOT(on_submitButton_clicked()) );
    ui->errorMsg->setHidden(true);
}

QuestionScreen1::~QuestionScreen1()
{
    delete ui;
}

void QuestionScreen1::chuckSkitz()
{
    ui->errorMsg->setHidden(false);
}

void QuestionScreen1::on_submitButton_clicked()
{
    // some kind of checking that all the fields have been entered
    if (ui->A1->text().length() < 3) return chuckSkitz();
    if (ui->A2->text().length() < 1) return chuckSkitz();
    if ( !(ui->EQ->isChecked() || ui->GT->isChecked() || ui->LT->isChecked()) ) return chuckSkitz();
    if (ui->A4->text().length() < 1) return chuckSkitz();
    if ( !(ui->True->isChecked() || ui->False->isChecked()) ) return chuckSkitz();
    if ( !(ui->maleRadio->isChecked() || ui->femaleRadio->isChecked())) return chuckSkitz();

    // hide error message once checks have passed
    ui->errorMsg->setHidden(true);


    // get answers and save them to file
    QString fileName = QString("Questionnaire").append(QDateTime::currentDateTime().toString(" - MM-dd hh.mm.txt"));
    QFile* file = new QFile(fileName);
    file->open(QIODevice::WriteOnly | QIODevice::Text);
    QTextStream out(file);

    // print results to file
    //      (can include formatting here if desired)
    out << ui->A1->text().toLatin1() << endl;
    out << ui->A2->text().toLatin1() << endl;
    if   ( ui->EQ->isChecked() ) out << QString("Equal\n").toLatin1();
    if   ( ui->GT->isChecked() ) out << QString("More\n").toLatin1();
    if   ( ui->LT->isChecked() ) out << QString("Less\n").toLatin1();
    out << ui->A4->text().toLatin1() << endl;
    if   ( ui->True->isChecked() )  out << QString("True\n").toLatin1();
    if   ( ui->False->isChecked() ) out << QString("False\n").toLatin1();
    if   ( ui->maleRadio->isChecked() )  out << QString("Male\n").toLatin1();
    if   ( ui->femaleRadio->isChecked() ) out << QString("Female\n").toLatin1();

    file->close();

    // // has now submitted results //

    // hide the submit button
    ui->submitButton->setEnabled(false);

    // show the next button
    emit gimmeANextButton();
}
