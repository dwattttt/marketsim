#ifndef QUEST1_H
#define QUEST1_H

#include <QWidget>

namespace Ui {
class quest1;
}

class QuestionScreen1 : public QWidget
{
    Q_OBJECT
    
public:
    explicit QuestionScreen1(QWidget *parent = 0);
    ~QuestionScreen1();
    
private:
    Ui::quest1 *ui;
};

#endif // QUEST1_H
