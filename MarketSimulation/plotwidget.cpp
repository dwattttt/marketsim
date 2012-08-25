#include "plotwidget.h"
#include "ui_plotwidget.h"

#include <qwt/qwt_scale_draw.h>
#include <qwt/qwt_plot_canvas.h>
#include <qwt/qwt_plot_layout.h>
#include <qwt/qwt_legend.h>
#include "market.h"

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

    setAxisTitle(QwtPlot::xBottom, " Time [s]");
    setAxisScaleDraw(QwtPlot::xBottom,
                     new QwtScaleDraw());
    setAxisAutoScale(QwtPlot::xBottom, false);
    setAxisScale(QwtPlot::xBottom, 0, Market::EXPERIMENT_RUNNING_TIME);
    setAxisLabelRotation(QwtPlot::xBottom, -50.0);
    setAxisLabelAlignment(QwtPlot::xBottom, Qt::AlignLeft | Qt::AlignBottom);

    setAxisTitle(QwtPlot::yLeft, " Price [$]");
    setAxisScaleDraw(QwtPlot::yLeft,
                     new QwtScaleDraw());
    setAxisScale(QwtPlot::yLeft, 0, MAX_PRICE_PLOT);
    setAxisLabelRotation(QwtPlot::yLeft, -50.0);
    setAxisLabelAlignment(QwtPlot::yLeft, Qt::AlignLeft | Qt::AlignBottom);

    // Setup the data
    asset1Data = new CircularBuffer((Market::EXPERIMENT_RUNNING_TIME)/2 + 4); // Running time, /2 for data every 2 seconds, + a safety buffer
    asset2Data = new CircularBuffer((Market::EXPERIMENT_RUNNING_TIME)/2 + 4);
    timeData = new CircularBuffer((Market::EXPERIMENT_RUNNING_TIME)/2 + 4);

    asset1Curve = new QwtPlotCurve("Asset 1");
    asset1Curve->setPen(QPen(Qt::red));
    asset1Curve->attach(this);

    asset2Curve = new QwtPlotCurve("Asset 2");
    asset2Curve->setPen(QPen(Qt::blue));
    asset2Curve->attach(this);
}

PlotWidget::~PlotWidget()
{
    delete ui;
}

void PlotWidget::addData(double time, double price1, double price2)
{
    timeData->insertItem(time);
    asset1Data->insertItem(price1);
    asset2Data->insertItem(price2);

    asset1Curve->setRawSamples(timeData->getData(),asset1Data->getData(),asset1Data->getSize());
    asset2Curve->setRawSamples(timeData->getData(),asset2Data->getData(),asset2Data->getSize());

    replot();
}
