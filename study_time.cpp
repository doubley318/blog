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
    int study_time = 0;
    time_t timePointer;
    time(&timePointer);
    char temp[64];
    strftime(temp, sizeof(temp), "%Y%m%d_%H%M%S", localtime(&timePointer));
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

        GetCursorPos(&last_p); //获取鼠标坐标

        time_t now, later;
        time(&now);
        time(&later);
        bool kerboard = false;
        while (later - now < 60)
        {
            for (int i = 1; i < 255; i++)
            {
                if (KEY_DOWN(i))
                {
                    kerboard = true;
                    Sleep(1000 * (59 + now - later));
                    break;
                }
            }
            Sleep(1000);
            time(&later);
        }

        GetCursorPos(&p); //获取鼠标坐标

        if (!(p.x == last_p.x && p.y == last_p.y) || kerboard)
        {
            study_time++;
        }
        outfile << (string)temp << " ";
        outfile << study_time << "mins" << endl;
    }

    return 0;
}