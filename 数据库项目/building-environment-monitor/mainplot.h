#ifndef MAINPLOT_H
#define MAINPLOT_H

#include <qwt_plot.h>
#include <qdatetime.h>
#include "main.h"

#define HISTORY 60 // 数据最大存储时长，单位秒
//调整前向声明顺序
class QwtPlotCurve;
class QwtPlotMarker;

class MainPlot : public QwtPlot
{
    Q_OBJECT
public:
    enum Data
    {
        Temp,
        Humi,

        NData
    };

    MainPlot(QWidget * = 0);
    //const QwtPlotCurve *cpuCurve(int id) const
    //    { return data[id].curve; }

protected:
    void timerEvent(QTimerEvent *e);

    void showSmog( double x, double y );
    
    QwtPlotMarker *smogMaker;



private slots:
    void showCurve(QwtPlotItem *, bool on);//槽函数重命名，调整内部成员排版换行格式



private:
    struct
    {
        QwtPlotCurve *curve;
        double data[HISTORY];
    } data[NData];
    double timeData[HISTORY];

    int dataCount;
};


#endif // MAINPLOT_H
