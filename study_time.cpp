#include "stdio.h"
#include <iostream>
#include <windows.h>
#include <time.h>
#include <string>
#include <fstream>
using namespace std;

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? true : false)

int main()
{
    POINT p;
    POINT last_p;
    // 定义总的学习时间：以分钟为单位
    int study_time = 0;
    time_t timePointer;
    time(&timePointer);
    char temp[64];
    // 将时间转化为年月日时分秒的格式
    strftime(temp, sizeof(temp), "%Y%m%d_%H%M%S", localtime(&timePointer));
    // 记录时间的文件
    string record_txt = (string)temp + ".txt";
    ofstream outfile(record_txt);
    if (!outfile)
    {
        cout << "filed to open file\n";
        exit(1);
    }
    while (true)
    {

        time_t timePointer;
        time(&timePointer);
        char temp[64];
        strftime(temp, sizeof(temp), "%Y-%m-%d %H:%M:%S", localtime(&timePointer));

        GetCursorPos(&last_p); //获取鼠标起始坐标

        time_t now, later;
        time(&now);
        time(&later);
        bool keyboard = false;
        bool mouse = false;
        // 每60秒检测一次
        while (later - now < 60)
        {
            // 检测鼠标位置
            GetCursorPos(&p); //获取鼠标结束坐标
            if (!(p.x == last_p.x && p.y == last_p.y))
                mouse = true;
            // 检测键盘输入
            for (int i = 1; i < 255; i++)
            {
                if (KEY_DOWN(i))
                {
                    keyboard = true;
                    break;
                }
            }
            if (keyboard || mouse)
                Sleep(1000 * (59 + now - later));
            Sleep(1000);
            time(&later);
        }

        if (mouse || keyboard)
        {
            study_time++;
        }
        outfile << (string)temp << " ";
        outfile << study_time << "mins" << endl;
    }
	outfile.close();
    return 0;
}
