// TestApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    //int arr[3] = { 1,2,3 };
    //const int arr2[10] = {};
    //arr[0] = 3;
    //arr[1] = 2;
    //arr[2] = 1;

    //std::cout << arr[1];

    //for (size_t i = 0; i < sizeof(arr) / sizeof(int); i++)
    //{
    //    arr[i] = i;
    //}

    //debug this with memory board
    //for (size_t i = 0; i < sizeof(arr); i++)
    //{
    //    arr[i] = i; // <- breakpoint
    //}

    //std::cout << sizeof(arr) << std::endl;
    //=====================================
    

    //const int arrSize = 2;
    //int arr[arrSize][arrSize] = { {1,2}, {3,4} };
    ////for (size_t i = 0; i < arrSize; i++)
    ////{
    ////    for (size_t j = 0; j < arrSize; j++)
    ////    {
    ////        std::cout << arr[i][j] << " ";
    ////    }
    ////    std::cout << std::endl;
    ////}
    ////-----------
    ////for (int j = 0; j < 4; j++) {
    ////    cout << *(*arr3 + j);
    ////}

    ////-----------
    //for (size_t i = 0; i < arrSize*arrSize; i++)
    //{
    //    std::cout << arr[0][i] << " ";
    //}

    // swap
    const int arrSize = 10;
    int arr[arrSize] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    for (size_t i = 0, j = arrSize; i < arrSize / 2; i++, j--)
    {
        int tmp = arr[i];
        arr[i] = arr[j-1];
        arr[j-1] = tmp;
    }
    for (size_t i = 0; i < arrSize; i++)
    {
        std::cout << arr[i] << " ";
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

