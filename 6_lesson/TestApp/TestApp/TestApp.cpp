// TestApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


int main()
{


    //char arr[10] = {1,2,3,4,5,6,7,8,9,0};
    //int* i = (int*)arr; // c-style cast  
    //short* i2 = (short*)arr;
    //i = i + 1;
    //int val = *i;

    //int arr2[] = {0x11111111, 0x22222222, 0x33334433};
    //char* ch = (char*)arr2;


    //std::cout << std::hex << (int)*(ch + 0) << std::endl; //
    //std::cout << std::hex << (int)*(ch + 1) << std::endl;
    //std::cout << std::hex << (int)*(ch + 5) << std::endl;
    //std::cout << std::hex << (int)*(ch + 9) << std::endl;

    //char a = *(ch + 0); // 0x11
    //char b = *(ch + 1); // 0x11
    //char c = *(ch + 5); // 0x22
    //char d = *(ch + 9); // 0x44

    //int x = 0;
    //char y = x;

    //int x2 = 0xfaaaaaff;
    //char y2 = x2; // ff = 1 byte = 255

    //unsigned char y3 = 0xff; // =-1 if not unsigned
    //unsigned int x3 = y3;    
    //std::cout << x3 << std::endl;

    //int z1 = 10;
    //unsigned int z2 = 20;
    //if (static_cast<unsigned int>(z1) < z2) {

    //}

    //char* chr = 0;;
    //void* v = chr;
    //int num = 0xffffffff;
    //int* pnum = &num;
    //std::cout << sizeof(chr) << std::endl;  // 4 byte
    //std::cout << sizeof(*chr) << std::endl; // 1 byte
    //std::cout << sizeof(num) << std::endl;  // 4 byte
    ////chr = static_cast<char*>(v); // = v (it's error)
    //
    //chr = reinterpret_cast<char*>(num); // = num OR static_cast<char*> -> errors
    //chr = (char*)num; // bad solution -> static_cast, reint_cast and other cast will look for for this task

    //// C-cast
    //// static_cat
    //// reinterpret_cast (if we know better than a compiler)

    // task
    int A[3] = { 3, 0, 7 };
    int* B; // 0x500
    int** C;
    C = &B; // 0x500
    B = A + 2; // &A[2] = 7
    //std::cout << *B << std::endl;
    //std::cout << **C << std::endl;
    B--;    // &A[1] = 0
    (*B)--; // A = {3, -1, 7}               -1
    **C += 3; // A = {3, 2, 7}              2
    A[0] = A[1]; // A = {2, 2, 7}           2, 2, 7
    A[1] = *(B - 1) + *A; // A = {2, 4, 7}  2 + 2
    // 2, 4, 7
    for (auto& i : A)
    {
        std::cout << i << std::endl;
    }


    //XOR_crypt();

    return 0;
}