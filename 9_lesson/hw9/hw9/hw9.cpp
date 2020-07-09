// hw9.cpp :    Split function.
// author:      Nakonechnyi Mikhail
// date:        08.07.20
// version:     1.0
// description of homework task:
//Реализовать функцию split(const char* str, char delimiter, char** tokens).
//Функция принимает на вход строку(str), которую необходимо разделить на токены по 
//разделителю(delimeter) и вернуть массив токенов(tokens).
//Пример:
//const char* str = "12-34567-890"
//split(str, '-', tokens)
//Должен вернуть масиив токенов :
//12
//34567
//890
// 
// future work:
// make with single/doubly link list

#include <iostream>
#include "Split.h"

int main() {
    const char* str = "12-34567-890";
    char** tokens{ nullptr }; 

    //version 1
    //Split(str, '-', tokens);
    
    //version 2
    //std::vector<std::string> v = SplitVector(str, '-');   //version 2 - 1
    //std::vector<std::string> v = SplitVector2(str, "-");    //version 2 - 2
    //for (const auto& i : v) { std::cout << i << std::endl; }

    //version 3
    Tokens* toks{ nullptr };
    SplitToks(str, '-', toks);

    return 0;
}


/*
Questions:
    1) .hpp, .cxx files and differents between .h and .cpp
    2) differents between const char* and std::string and whats prefere or it depends on developer
    
    
    
*/