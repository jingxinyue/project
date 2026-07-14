#ifndef API_H
#define API_H
#include <QMutex>
#include "zigbee_struct.h"
 extern struct NodeInfo *pNodeInfo2;
//extern QList<DeviceInfo*> DevinfoList;
extern struct DeviceInfo*  DevinfoList;
extern struct NodeInfo *arr[20];//节点信息缓存数组，上限支持20个组网设备
extern int i_depth;//网络树形结构中节点的层级深度值
extern int flag_coord;
extern float show_buf_temp[720] ;
extern float show_buf_hum[720] ;
extern int temp_count;//解析完成后的环境温度长整型原始采集值
extern unsigned long int ptemperature;
extern unsigned int ptemp;
extern unsigned int phum;
extern unsigned long int pid;
extern unsigned long int id_temp;
//extern int irda_warn_flag;
//extern int int_warn_flag;
//extern int smog_warn_flag;
//extern static int irda_warn_flag_temp;
//extern static int int_warn_flag_temp;
//extern static int smog_warn_flag_temp;
extern int sockfd;
extern int gprssig;
extern NwkDesp pNwkDesp2;
extern int coorstate;
#endif
