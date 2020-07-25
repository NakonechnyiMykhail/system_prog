// strings.cpp :	String realization.
// author:			Nakonechnyi Mikhail
// date:			24.07.20
// version:			1.0
// description of homework task:
// class String, который будет принимать в конструкторе const char*, 
// копирует чары во внутренний буффер, выделенный по new.Реализовать деструктор
// Сделать конструктор копирования и 
// оператор =, 
// оператор == , 
// оператор != , 
// оператор !, 
// оператор[]
//
// quastions:
// 1. how to rewrite operator ->  str += str1; (str = str + str1;)

#include <iostream>
#include "String.h"

int main()
{
	String str = "hello";
	String str1("mike");
	String str3;
	String str4;
	String str5;

	str3 = str1;

	if (str1 == str3)
	{
		std::cout << "str1 == str3" << std::endl;
	}
	if (!(str != str3))
	{
		std::cout << "str != str3" << std::endl;
	}

	str4 = str + str3; // 10
	//str.Print();
	std::cout << str4 << "\n";

	str5 = str1 + " " + str4; 
	std::cout << str5 << "\n";
	//str5.Print();


	return 0;
}

