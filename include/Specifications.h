#ifndef _SPECIFICATION_H_
#define _SPECIFICATION_H_

//-----------------------机械结构相关-------------------------
#define     ROD_DISTANCE        (9)          // 相邻两臂间距
#define     PLATFORM_RADIUS     (25)         // 固定平台等效半径
#define     ACTUATOR_RADIUS     (9)          // 执行器等效半径
#define     ACTUATOR_INITIAL_Z  (-22)        // 初始执行器Z坐标

#define     ROD_A_LENGTH        (10)         // A杆长度
#define     ROD_B_LENGTH        (25)         // B杆长度

#define     PI                  (3.1415926)  //Pi值

//-----------------------加工文件相关-------------------------
#define     MAX_LINE            (200)        //文件最大指令容量   
#define     STORAGE             (300)        //文件最大总量

//加工文件使用的是整数，转化为实际距离，要除以以下的参数
#define     MULTIPLYING_POWER   (100)        //数字转化倍率

#endif