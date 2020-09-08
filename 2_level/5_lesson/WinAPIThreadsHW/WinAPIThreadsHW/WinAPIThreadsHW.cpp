// WinAPIThreadsHW.cpp :    WINAPI Thread is created by setting SECONDS of lifecycle in system varieble.
// author:                  Nakonechnyi Mikhail
// date:                    08.09.20
// version:                 1.0 
// description of homework:
/*
Напишите программу, которая через переменную окружения принимает время 
жизни потока в секундах.Запускает поток который выводит каждые 5 сек текущее 
время и завершается через заданное количество времени
*/

#pragma warning(disable : 4996) //_CRT_SECURE_NO_WARNINGS
//#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <windows.h>
#include <ctime> 
#include <chrono>
#include <string>
#include <stdio.h>


const std::string currentDateTime() {
    // Get current date/time, format is YYYY-MM-DD.HH:mm:ss
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    //strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    strftime(buf, sizeof(buf), "%X", &tstruct);

    return buf;
}

DWORD WINAPI ThreadStart(LPVOID lpParam)
{
    if (lpParam)
    {
        int mili_sec = *static_cast<DWORD *>(lpParam) * 1000;
        while (mili_sec != 0)
        {
            if (mili_sec % 5000 == 0)
            {
                std::cout << "currentDateTime()=" << currentDateTime() << std::endl;
            }
            mili_sec -= 1000;
            Sleep(1000);
        }
    }
    else
    {
        std::cerr << "lpParam is not set!" << std::endl;
    }

    return 0;
}


int main()
{
    char* pValue;
    size_t len;
    errno_t err = _dupenv_s(&pValue, &len, "LIFETIMER");

    if (err == 0 && pValue != nullptr)
    {
        DWORD dwThrdParam = atoi(pValue);
        std::cout << "dwThrdParam = " << dwThrdParam << std::endl;

        HANDLE thread1 = CreateThread(0, 0, ThreadStart, &dwThrdParam, 0, 0);
        Sleep(dwThrdParam * 1000);
        free(pValue);
    }
    return 0;
}

/*
======================= cmd print ==========================================
set LIFETIMER=24
echo %LIFETIMER%
    24

WinAPIThreadsHW\Debug\WinAPIThreadsHW.exe
dwThrdParam = 24
Timer=24000
Timer=23000
Timer=22000
Timer=21000
Timer=20000
currentDateTime()=08:58:31
Timer=19000
Timer=18000
Timer=17000
Timer=16000
Timer=15000
currentDateTime()=08:58:36
Timer=14000
Timer=13000
Timer=12000
Timer=11000
Timer=10000
currentDateTime()=08:58:41
Timer=9000
Timer=8000
Timer=7000
Timer=6000
Timer=5000
currentDateTime()=08:58:46
Timer=4000
Timer=3000
Timer=2000
Timer=1000
*/