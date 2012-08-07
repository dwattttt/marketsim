// Source: http://stackoverflow.com/questions/5653114/display-image-in-qt-to-fit-label-size

#include "QImage.h"
#include "QPixmap.h"
#include "QLabel.h"

class QPictureLabel : public QLabel
{
private:
    QPixmap _qpSource; //preserve the original, so multiple resize events won't break the quality
    QPixmap _qpCurrent;

    void _displayImage();

public:
    QPictureLabel(QWidget *aParent) : QLabel(aParent) { }
    void setPixmap(QPixmap aPicture);
    void paintEvent(QPaintEvent *aEvent);
};
