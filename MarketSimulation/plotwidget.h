#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QWidget>
#include <QByteArray>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>

#include "circularbuffer.h"

namespace Ui {
class PlotWidget;
}

class PlotWidget : public QwtPlot
{
    Q_OBJECT
    
public:
    explicit PlotWidget(QWidget *parent = 0);
    ~PlotWidget();

    void addData(double time, double price1, double price2);
    
private:
    Ui::PlotWidget *ui;

    CircularBuffer* asset1Data;
    CircularBuffer* asset2Data;
    CircularBuffer* timeData;

    QwtPlotCurve* asset1Curve;
    QwtPlotCurve* asset2Curve;
};

#endif // PLOTWIDGET_H
