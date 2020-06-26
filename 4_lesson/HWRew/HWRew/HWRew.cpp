// HWRew.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    std::cout << "Enter the height: ";
    int height = 0;
    std::cin >> height;
    if (height < 5)
    {
        std::cout << "height must be larger than 5\n";
        return 0;
    }



    std::cout << "Hello World!\n";
}
