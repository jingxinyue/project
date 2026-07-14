// Qt应用程序核心头文件
#include <QtGui/QApplication>
// 自定义主界面窗口头文件
#include "mywidget.h"
// 全局数据类声明头文件
#include "main.h"
// Qt字符编码处理头文件
#include <QTextCodec>

// 实时采集温度静态变量
double tempData::tempValue = 0;
// 实时采集湿度静态变量
double tempData::humiValue = 0;
// 烟雾传感器状态标记
int tempData::smogStatus = 0;
// 全局告警总开关
bool tempData::allAlarmIsOn = true;
// 温度告警上限阈值
double tempData::maxTempValue = 0;
// 温度告警下限阈值
double tempData::minTempValue = 0xffff;
// 湿度告警上限阈值
double tempData::maxHumiValue = 0;
// 湿度告警下限阈值
double tempData::minHumiValue = 0xffff;
// 红外探测状态标识
int tempData::irdaStatue = 0;
// 备用通道温度数据
double tempData::tempValueBlue = 0;
// 备用通道湿度数据
double tempData::humiValueBlue = 0;

int main(int argc, char* argv[])
{
    // 初始化Qt应用实例
    QApplication a(argc, argv);

    // 全局界面字体配置
    QFont font;
    font.setFamily("wenquanyi");
    //font.setPointSize(10);
    a.setFont(font);

    
    //QTextCodec::setCodecForTr(QTextCodec::codecForName("GB2312"));
    
    QTextCodec* codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForTr(codec);
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);

    // 创建主窗体对象
    myWidget w;
    //w.show();
    // 窗体以全屏模式启动
    w.showFullScreen();

    // 启动Qt消息事件循环
    return a.exec();
}
