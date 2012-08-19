//Source: http://stackoverflow.com/questions/5653114/display-image-in-qt-to-fit-label-size

#include <QPainter>

#include "QPictureLabel.hpp"

void QPictureLabel::paintEvent(QPaintEvent *aEvent)
{
    QLabel::paintEvent(aEvent);
    _displayImage();
}

void QPictureLabel::setPixmap(QPixmap aPicture)
{
    _qpSource = _qpCurrent = aPicture;
    repaint();
}

void QPictureLabel::_displayImage()
{
    if (_qpSource.isNull()) //no image was set, don't draw anything
        return;

    float cw = width(), ch = height();
    float pw = _qpCurrent.width(), ph = _qpCurrent.height();

    if (_qpSource.width() < cw && _qpSource.height() < ch)
    {
        _qpCurrent = _qpSource;
    }
    else if ((pw > cw && ph > ch && pw/cw) > ph/ch || //both width and high are bigger, ratio at high is bigger or
        (pw > cw && ph <= ch) || //only the width is bigger or
        (pw < cw && ph < ch && cw/pw < ch/ph) //both width and height is smaller, ratio at width is smaller
        )
        _qpCurrent = _qpSource.scaledToWidth(cw, Qt::SmoothTransformation);
    else if ((pw > cw && ph > ch && pw/cw) <= ph/ch || //both width and high are bigger, ratio at width is bigger or
        (ph > ch && pw <= cw) || //only the height is bigger or
        (pw < cw && ph < ch && cw/pw > ch/ph) //both width and height is smaller, ratio at height is smaller
        )
        _qpCurrent = _qpSource.scaledToHeight(ch, Qt::SmoothTransformation);

    int x = (cw - _qpCurrent.width())/2, y = (ch - _qpCurrent.height())/2;

    QPainter paint(this);
    paint.drawPixmap(x, y, _qpCurrent);
}
