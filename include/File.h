#ifndef _FILE_
#define _FILE_

#include "Specifications.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>

// 代码行的结构体，包含操作数，信息和Speed
struct Body
{
    int operate;
    double info[3];
    int speed;
};

typedef Body line;

class Plan
{
public:
    Plan(char* filename);
    ~Plan(){};
    bool load(std::ifstream &input); //文件载入
    void chart(); //输出文件命令总数和注释总数
    int GetCommand(){return command;}; // 输出命令总数 
    line Getdata(int i){return data[i];}; // 输出某一行命令

    void PrintLine(line input); // 打印指令
    void PrintLine(int i); // 打印指令
    void PrintAllLines(); // 打印全部指令  
private:
    int mode; // 工作模式，由IN指令进行设置，设置之后不会变化。
    int speed; // 速度，可以再运行中进行变化，用SP指令进行设置。
    bool debug; // DEBUG模式会输出一些信息

    int command; // 命令总数
    int comment; // 注释总数

    line data[MAX_LINE]; // 指令行
    void treat(char *s); // 去除指令头所用的函数
    int translate(char s1, char s2); // 识别指令
    std::string reverse_translat(int num); // 指令数到指令代号的转化
    

    void clear(int i); // 清除一个指令内的信息
};

#endif