#ifndef MAIN_H
#define MAIN_H

#include <QDebug>

class tempData
{
public:
    static double tempValue;//当前环境温度数值
    static double humiValue;//当前环境湿度数值
    static int smogStatus; //烟雾传感器状态标识
    static double maxTempValue;//温度上限告警阈值
    static double minTempValue;//温度下限告警阈值
    static double maxHumiValue;//湿度上限告警阈值
    static double minHumiValue;//湿度下限告警阈值
    static bool allAlarmIsOn;//全局告警总开关
    static int irdaStatue; //红外设备工作状态
    static double tempValueBlue;//备用通道温度数据
    static double humiValueBlue;//备用通道适度数据
};

#endif // MAIN_H
