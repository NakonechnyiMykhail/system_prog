// TestApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    bool b;         // 1 byte (8bit)
    char c;         // 1 byte (8bit)
    short s;        // 2 byte
    int i;          // i >= s && i <= l (2,4)
    long l;         // 4-8 byte
    long long ll;   // ll >= l (8 byte)


    //std::cout << "sizeof(b):\t\t" << sizeof(b) << "\n";
    //std::cout << "sizeof(c):\t\t" << sizeof(c) << "\n";
    //std::cout << "sizeof(s):\t\t" << sizeof(s) << "\n";
    //std::cout << "sizeof(i):\t\t" << sizeof(i) << "\n";
    //std::cout << "sizeof(l):\t\t" << sizeof(l) << "\n";
    //std::cout << "sizeof(ll):\t\t" << sizeof(ll) << "\n";

    //x86
    //sizeof(b) :     1
    //sizeof(c) :     1
    //sizeof(s) :     2
    //sizeof(i) :     4
    //sizeof(l) :     4
    //sizeof(ll) :    8

    //x64
    //sizeof(b) :     1
    //sizeof(c) :     1
    //sizeof(s) :     2
    //sizeof(i) :     4
    //sizeof(l) :     4
    //sizeof(ll) :    8

    int8_t  i8;
    int16_t i16;
    int32_t i32;
    int64_t i64;
    
    unsigned char ch = 0xff;
    ch += 1;

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

