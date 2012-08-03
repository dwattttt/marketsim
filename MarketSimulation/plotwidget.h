#ifndef PLOTWIDGET_H
#define PLOTWIDGET_H

#include <QWidget>
#include <qwt/qwt_plot.h>
#include <qwt/qwt_plot_curve.h>

namespace Ui {
class PlotWidget;
}

class PlotWidget : public QwtPlot
{
    Q_OBJECT
    
public:
    explicit PlotWidget(QWidget *parent = 0);
    ~PlotWidget();
    
private:
    Ui::PlotWidget *ui;
    QwtPlotCurve* curve;
    double* xData;
    double* yData;
};

#endif // PLOTWIDGET_H
