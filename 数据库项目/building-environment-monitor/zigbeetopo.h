#ifndef ZIGBEETOPO_H
#define ZIGBEETOPO_H

// Qt基础组件头文件引入，用于界面与进程调度相关能力
#include <QWidget>
#include <QProcess>
// 多线程核心依赖头文件，实现后台拓扑数据轮询任务
#include <QThread>
#include <QString>
#include <QStringList>
// 线程互斥锁，保护多线程下共享数据的读写安全，防止竞态问题
#include <QMutex>

// 后台服务通信接口头文件
#include "server/api.h"
// 网络客户端连接与数据收发底层封装头文件
#include "server/cliect_td.h"

/**
 * @brief Zigbee拓扑网络后台工作线程类
 * 继承QThread，以独立子线程方式运行，避免阻塞主线程UI渲染
 * 负责处理zigbee组网的数据接收、解析、状态上报全流程
 */
class ZigbeeTopo : public QThread
{
    Q_OBJECT
public:
    // 构造函数：初始化线程基础资源
    ZigbeeTopo();
    // 析构函数：释放线程占用资源，安全退出线程
    ~ZigbeeTopo();

    /**
     * @brief 线程主循环执行函数
     * 重写QThread的run方法，线程启动后自动进入该函数执行循环业务
     */
    void run();

public:
    // 多线程互斥保护锁，用于同步访问客户端共享数据
    QMutex mutex;
    // 网络客户端实例指针，承载与服务端的数据交互工作
    cliect* cliect_thread;

private slots:

private:
};

#endif // ZIGBEETOPO_H
