#ifndef QUEST1_H
#define QUEST1_H

#include <QWidget>
#include <QDateTime>
#include <QtCore>
#include <QTextStream>

namespace Ui {
class quest1;
}

class QuestionScreen1 : public QWidget
{
    Q_OBJECT

signals:
    void gimmeANextButton();

public:
    explicit QuestionScreen1(QWidget *parent = 0);
    ~QuestionScreen1();

private slots:
    void on_submitButton_clicked();

private:
    Ui::quest1 *ui;
    void chuckSkitz();
};

#endif // QUEST1_H
