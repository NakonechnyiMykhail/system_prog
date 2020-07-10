// HWRew.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main() {
    std::cout << "Enter the height: ";
    int height = 0;
    std::cin >> height;
    if (height < 5)
    {
        std::cout << "height must be larger than 5\n";
        return 0;
    }
    const int roofHeight = height / 2;
    const int wallHeight = height - roofHeight;
    for (size_t i = roofHeight; i > 0; --i)
    {
        for (size_t j = 0; j < i; ++j)
        {
            std::cout << " ";
        }
        std::cout << "/";    
        for (size_t j = roofHeight; j - i > 0; --j)
        {
            std::cout << "  ";
        }
        std::cout << "\\" << std::endl;
    }
    const int doubleWallWidth = 2;
    int buildingWidth = roofHeight * 2;
    for (size_t i = 0; i < buildingWidth + doubleWallWidth; ++i)
    {
        std::cout << "-";
    }
    std::cout << std::endl;
    for (size_t i = 0; i < wallHeight; ++i)
    {
        std::cout << "|";
        for (size_t j = 0; j < buildingWidth; ++j)
        {
            std::cout << " ";
        }
        std::cout << "|" << std::endl;
    }
    for (size_t i = 0; i < buildingWidth + doubleWallWidth; ++i)
    {
        std::cout << "-";
    }



    return 0;
}
