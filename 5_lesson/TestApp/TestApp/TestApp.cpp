// TestApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

void links(); // part 1
void chars(); // part 2

void task1_ex(); // Anton version with HEX
void task1_my(); // my version
void task2(std::string);
std::vector<std::string> getWords(std::string str);


//bool isFirstLetterOfWord(const char* arrayWords, int index);
//std::string getWord(const char* arrayWords);


int main()
{

    links(); // part 1
    chars(); // part 2

    task1_ex(); // Anton version with HEX
    task1_my(); // my version

    // !!! if ARRAY - sizeof 
    // !!! if link - strlen (sizeof RETURN size of TYPE)


    // ================================================
    std::string str = "hello, world! string my map is name";

    task2(str);

    return 0;
}

void task2(std::string)
{
    // task 2 = only first symbols will upper
    

    std::vector<std::string> words = getWords(str);

    for (auto& word : words)
    {
        for (size_t j = 0; j < word.length(); j++)
        {
            if (j == 0)
            {
                std::cout << (char)(word[j] - 32);
            }
            else
            {
                std::cout << word[j];
            }
        }
        std::cout << ' ';
    }


    // REVIEW first idea
    //for (size_t i = 0; i < sizeof(arr2); i++)
    //{
    //    if ((*(arr2 + i) != ' ' || 
    //        *(arr2 + i) != '.' || 
    //        *(arr2 + i) != ',' || 
    //        *(arr2 + i) != ':' ||
    //        *(arr2 + i) != ';' ||
    //        *(arr2 + i) != '!' || 
    //        *(arr2 + i) != '-')
    //        && isFirstLetterOfWord(arr2, i))
    //    {
    //        *(arr2 + i) -= 32;
    //    }


    //    std::cout << arr2[i];
    //}
}

std::vector<std::string> getWords(std::string str)
{
    std::string word = "";
    std::vector<std::string> words; 
    std::istringstream ss(str);

    do {
        std::string word;
        ss >> word;
        words.push_back(word);
    } while (ss);
    return words;
}

bool isFirstLetterOfWord(std::string arrayWords, int index)
{
    // REVIEW
    bool isFirst = false;
    std::vector<std::string> words; 
    for (const auto& i : arrayWords)
    {
    }
    return isFirst;
}


std::string getWord(const char* arrayWords)
{
    // REVIEW
    char tmp[20];
    for (size_t i = 0; i < sizeof(arrayWords); i++) // strlen OR sizeof
    {
        while (
            *(arrayWords + i) != ' ' ||
            *(arrayWords + i) != '.' ||
            *(arrayWords + i) != ',' ||
            *(arrayWords + i) != ':' ||
            *(arrayWords + i) != ';' ||
            *(arrayWords + i) != '!' ||
            *(arrayWords + i) != '-')
        {
            *(tmp + i) = *(arrayWords + i);
        }
    }
    return tmp;
}

void task1_ex()
{
    // ================================================
    // task 1 = all symbols will upper
    char arr1[] = "hello world";
    char symbols[] = "AZaz";
    for (size_t i = 0; i < sizeof(arr1); i++)
    {
        char* curSymbolPtr = arr1 + i;
        char curSymbol = *curSymbolPtr;
        // 0x61 - 0x7a
        if (curSymbol >= 0x61 && curSymbol <= 0x7a)
        {
            *curSymbolPtr = curSymbol - 0x20;
        }
    }
    std::cout << arr1;
    // ================================================
}

void task1_my()
{
    // ================================================
    // task 1 = all symbols will upper
    char arr[] = "hello, world!";
    
    //std::cout << (int)'A' << '\t' << (int)'a' << std::endl;
    //std::cout << (int)'Z' << '\t' << (int)'z' << std::endl;

    std::cout << arr << std::endl;
    
    for (size_t i = 0; i < sizeof(arr); i++)
    {
        if (*(arr + i) != ' ' ||
            *(arr + i) != '.' ||
            *(arr + i) != ',' ||
            *(arr + i) != ':' ||
            *(arr + i) != ';' ||
            *(arr + i) != '!' ||
            *(arr + i) != '-')
        {
            *(arr + i) = *(arr + i) - 32; // 32 -> 0x20
        }
            

        std::cout << arr[i];
    }
}

void links()
{
    //part 1 of lesson
    // memory: 0x000000 - 0xffffffff
    // stack memory: 0x500 - 0x100  ???
    // прямой или обратный порядок?
    // 
    
    int i = 0x10; // i -> 0x500
    int y = 0x20; // i -> 0x4fc 
    int x = 0x30; // i -> 0x4f8
    char c = 5;
    char arr[0x500] = {};
    arr[0] = 10; // arr[0x000000] = 10;
    arr[1] = 11; // arr[0x000001] = 11;
    // ...
    //arr[0x7fffffff] = 11;

    int* pi = &i;
    char* pc = &c;
    *pi = 0x30;

    int** ppi = &pi;
    //int*** pppi = &ppi; // не используется в основном
    std::cout << "*pi =\t" << *pi << std::endl;
    int a = **ppi;
    **ppi = 0x40;

    std::cout << "a =\t" << a << std::endl;
    std::cout << "i =\t" << i << std::endl;
    std::cout << "&i =\t" << &i << std::endl;
    std::cout << "*pi =\t" << *pi << std::endl;
    std::cout << "pi =\t0x" << pi << std::endl;
    std::cout << "ppi =\t0x" << ppi << std::endl;
    std::cout << "&pi =\t0x" << &pi << std::endl;

    // example
    // 0x100 i =  10
    // 0x104 pi = 0x100
    // 0x108 ppi = 0x104
}

void chars()
{

    // stack memory
   int x = 10;

   // static memory
   const int z = 20;
   const char* str = "Hello,\0 world!";
   //char* str = "Hello, world!"; // DOESN'T WORK because of STATIC memory
   char c = 'g';
   // each symbol => char 8bit
   const char* ch = "c"; // 2 symbols = c and Null-terminator (\0) (C-string)
   std::cout << z << std::endl;
   std::cout << str << std::endl;

   for (size_t i = 0; i < strlen(str); i++)
   {
       char f = *(++str); // *(str + 1) / *(str + i)
   }
}