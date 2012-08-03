#include "plotwidget.h"
#include "ui_plotwidget.h"

#include <qwt/qwt_scale_draw.h>
#include <qwt/qwt_plot_canvas.h>
#include <qwt/qwt_plot_layout.h>
#include <qwt/qwt_legend.h>

PlotWidget::PlotWidget(QWidget *parent) :
    QwtPlot(parent),
    ui(new Ui::PlotWidget)
{
    ui->setupUi(this);

    // Setup plot stuff
    setAutoReplot(false);
    canvas()->setBorderRadius( 10 );

    plotLayout()->setAlignCanvasToScales(true);

    QwtLegend *legend = new QwtLegend;
    legend->setItemMode(QwtLegend::CheckableItem);
    insertLegend(legend, QwtPlot::RightLegend);

    setAxisTitle(QwtPlot::xBottom, " System Uptime [h:m:s]");
    setAxisScaleDraw(QwtPlot::xBottom,
                     new QwtScaleDraw());
    setAxisScale(QwtPlot::xBottom, 0, 60); // Own Change
    setAxisLabelRotation(QwtPlot::xBottom, -50.0);
    setAxisLabelAlignment(QwtPlot::xBottom, Qt::AlignLeft | Qt::AlignBottom);

    xData = (double *) malloc(sizeof(double)*60);
    yData = (double *) malloc(sizeof(double)*60);
    for (int i=0; i<60; i++) {
        xData[i] = i;
        yData[i] = 2*i;
    }

    curve = new QwtPlotCurve("Asset 1");
    curve->setRawSamples(xData,yData,60);
    curve->attach(this);
}

PlotWidget::~PlotWidget()
{
    delete ui;
}
