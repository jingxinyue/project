#include "zigbeetopo.h"

ZigbeeTopo::ZigbeeTopo()
{      
    cliect_thread1 = new Cliect();
    this->start();
}

ZigbeeTopo::~ZigbeeTopo()
{
}

void ZigbeeTopo::run(){

    while(1)
    {
        //上锁，独立客户端调用权限，防止多线程抢占引发错乱
        mutex.lock();
        //读取环境温度湿度传感器数据
        cliect_thread1->Api_Cliect_GetTempHum();

        //cliect_thread1->Api_Cliect_GetRfidId();

        cliect_thread1->Api_Cliect_GetGPRSSignal();
        //获取zigbee组网的拓扑结构信息
        cliect_thread1->Api_Cliect_GetZigBeeNwkTopo();


        mutex.unlock();

        usleep(800000);
        usleep(800000);
        usleep(800000);
    }

}
