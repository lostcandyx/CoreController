#include "File.h"

Plan::Plan(char *filename)
{
    for (int i = 0; i < MAX_LINE; i++)
    {
        clear(i);
    }
    speed = 0;
    mode = 0;
    debug = false;

    command = 0;
    comment = 0;

    std::ifstream input(filename); //打开文件
    if (load(input))
    {
        std::cout << "[ Succeed Loaded : " << filename << " ]" << std::endl;
    }
    else
    {
        std::cout << "[ Fail to load : " << filename << " ]" << std::endl;
    }
    input.close(); //关闭文件
}

void Plan::clear(int i)
//对某一行指令清零
{
    data[i].operate = 0;
    data[i].info[0] = 0;
    data[i].info[1] = 0;
    data[i].info[2] = 0;
    data[i].speed = 0;
}

bool Plan::load(std::ifstream &input)
//文件加载
{
    if (!input.is_open()) //打开文件
    {
        std::cout << "Failed to open the file" << std::endl;
        return false;
    }
    int index = 0, num = 0;
    //num为总条数，index为line的索引
    command = 0; //命令的总量
    comment = 0; //备注的总量
    while (1)
    {
        if (input.eof())
        {
            std::cout << "Reach the end of the file" << std::endl;
            break;
        }
        if ((index > MAX_LINE - 1) || (num > STORAGE))
        {
            std::cout << "Reach the limit of the storage" << std::endl;
            break;
        }

        char str[30]; //字符串
        input.getline(str, sizeof(str) - 1);
        if (str[0] == '#') //由#开头的是指令行
        {
            data[index].operate = translate(str[2], str[3]); //获取指令码

            treat(str); //去除字符串的前面部分

            int X0 = 0, X1 = 0, X2 = 0;

            if (data[index].operate == 2) // 设置速度
            {
                sscanf(str, "%d", &X0);
                speed = X0;
                data[index].info[0] = X0;
            }
            else if (data[index].operate == 1) // 设置工作模式
            {
                sscanf(str, "%d", &X0);
                mode = X0;
                data[index].info[0] = X0;
            }
            else if (data[index].operate == 3) // 到达三维中的某一点
            {
                sscanf(str, "%d %d %d", &X0, &X1, &X2); // 获取操作数

                data[index].info[0] = X0 / MULTIPLYING_POWER;
                data[index].info[1] = X1 / MULTIPLYING_POWER;
                data[index].info[2] = X2 / MULTIPLYING_POWER;
                data[index].speed = speed;
            }
            else if (data[index].operate == 4) // 文件结束符号
            {
                mode = 0;
                command++;
                return true;
            }
            if (debug) //debug模式会进行显示
                PrintLine(index);

            index++;
            command++;
        }
        else if (str[0] == '%') //由%开头的是备注行
        {
            comment++;
        }
        else
        {
            std::cout << "Non-standard coding" << std::endl;
            return false;
        }

        num++;
    }
    return true;
}

int Plan::translate(char s1, char s2)
// 使用两个字符翻译操作数
{
    int S = (int)(s1 * 100 + s1);
    int result = 0; // 默认是错误ER
    if (s1 == 'I' && s2 == 'N')
        result = 1; // 初始化 IN
    else if (s1 == 'S' && s2 == 'P')
        result = 2; // 设置速度 SP
    else if (s1 == 'T' && s2 == 'O')
        result = 3; // 到达某一点 TO
    else if (s1 == 'E' && s2 == 'D')
        result = 4; // 文件结束
    return result;
}

std::string Plan::reverse_translat(int num)
{
    std::string result = "ER"; // 错误
    switch (num)
    {
    case 1:
        result = "IN"; // 初始化
        break;
    case 2:
        result = "SP"; // 设置速度
        break;
    case 3:
        result = "TO"; // 移动到空间中某点
        break;
    case 4:
        result = "ED"; // 文件结束
        break;
    }
    return result;
}

void Plan::treat(char *s)
// 处理函数，将字符串前面的部分去掉，包括#和两个字符的指令码号和两个空格
{
    int i = 5;
    int j = 0;
    for (; s[i] != '\0'; i++, j++)
    {
        s[j] = s[i];
    }
    s[j] = s[i];
}

void Plan::PrintLine(line input)
// 输出该命令
{
    std::cout << reverse_translat(input.operate) << "  ";
    std::cout << input.info[0];
    if (input.operate == 3)
    {
        std::cout << " " << input.info[1] << " " << input.info[2];
        std::cout << " "
                  << "(" << input.speed << ")";
    }
    std::cout << "\n";
}

void Plan::PrintLine(int i)
// 输出第 i 行命令
{
    std::cout << reverse_translat(data[i].operate) << " ";
    std::cout << data[i].info[0];
    if (data[i].operate == 3)
    {
        std::cout << " " << data[i].info[1] << " " << data[i].info[2];
        std::cout << " "
                  << "(" << data[i].speed << ")";
    }
    std::cout << "\n";
}

void Plan::PrintAllLines()
// 打印全部指令
{
    for (int i = 0; i < command; i++)
    {
        PrintLine(i);
    }
}

void Plan::chart()
// 输出命令总数和注释总数
{
    printf("| command :%3d | comment :%3d |\n", command, comment);
}