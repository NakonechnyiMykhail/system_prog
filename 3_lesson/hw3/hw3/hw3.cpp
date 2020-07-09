// hw3.cpp :	Build your house as at the picture.
// author:      Nakonechnyi Mikhail
// date:        25.06.20
// version:     3.0 (04/07/2020)
// description of homework:
// 1. Нарисовать домик как на рисунке 
// 2. Дать возможность пользователю вводить высоту домика (задача со звездочкой)
// 3. Дать возможность ввести количество домиков. Домики рисуются справа на лево ( задача с двумя звездочками)
//
// helpful links:
// https://stackoverflow.com/questions/21493306/printing-multiple-lines-at-the-same-time-c
//
// ASCII Escape Doc
// http://ascii-table.com/ansi-escape-sequences.php

/*
    /\
   /  \
  /    \
 /------\
/ |    | \
  |    |
  |    |
  |____|

*/


#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <windows.h>
#include <string>
#include <functional>

//You need to initialize the escape character by calling its ASCII value
const char esc(27);

uint16_t GetInteger(std::string category) {
	/*
	Funtion:    print category and check inputting varieble for correct data
	Get:        integer varieble from user
	Return:     int
	*/
	uint16_t number { 0 };
	while (true) {
		std::cout << "Enter your " << category << ": ";
		std::cin >> number;

		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			continue;
		}
		// our data shoul be Non-zero
		if (number <= 0) { continue; }

		break;
	}
	return number;
}

auto SumStr {
	/*
	* lambda for set a same width for text message 
	*/
	[](const std::string& str) {
		std::string tmp;
		for (size_t i = 0; (str.length() + i) < 40; i++) {
			tmp += " ";
		}
		return str + tmp;
	}
};

void SlowPrint(unsigned long speed, std::string s) {
	int i = 0;
	while (s[i] != 0)
	{
		std::cout << s[i++];
		std::cout.flush();
		Sleep(speed);
	}
}

void DefineConsole() {

	std::cout << esc << "[0m"; // Text attributes 0	All attributes off
	std::cout << esc << "[=6h"; // 6	640 x 200 monochrome (graphics)
	std::cout << esc << "[1;31m" << esc << "[40m"; 
	// Text attributes	  1	Bold on
	// Foreground colors 31	Red
	// Background colors 40	Black
}

void PrintText(const std::string& str) {
	//std::cout << esc << "[1A" // This line moves the cursor up.
	//	<< "\r"; // This line moves the cursor all the way back to the left.
	std::cout << "================================================================================\n\n"
		<< "================================================================================"
		<< esc << "[1A\r";
	SlowPrint(20, SumStr(str));
}

void PrintRoof(int roofHeight) {
	for (size_t i = roofHeight; i > 0; --i) {
		for (size_t j = 0; j < i; ++j) {
			std::cout << " ";
		}
		std::cout << "/";
		for (size_t j = roofHeight; j - i > 0; --j) {
			std::cout << "  ";
		}
		std::cout << "\\" << std::endl;
	}
	
}

void v1_to_console() {
	int length = 11;
	int left = 5, right = 6;
	std::cout << esc << "[0;80H";
	for (size_t i = 1; i < length - 1; ++i) {
		for (size_t j = 0; j <= length; ++j) {
			if (j == left)
			{
				std::cout << '/';
			}
			else if (j == right)
			{
				std::cout << '\\';
			}
			else if (i == 5 && j >= 2 && j <= 9)
			{
				std::cout << '-';
			}
			else if (i >= 6 && (j == 2 || j == 9))
			{
				std::cout << '|';
			}
			else if (i == 9 && j >= 3 && j < 9)
			{
				std::cout << '_';
			}
			else
			{
				std::cout << ' ';
			}

		}
		left--; right++;
		std::cout << "\n" << esc << "[0;80H";
	}
}
std::string version_one_to_str()  {
	int length = 11;
	int left = 5, right = 6;
	std::string picture;
	for (size_t i = 1; i < length - 1; ++i)
	{
		for (size_t j = 0; j <= length; ++j)
		{

			if (j == left)
			{
				picture += '/';
			}
			else if (j == right)
			{
				picture += '\\';
			}
			else if (i == 5 && j >= 2 && j <= 9)
			{
				picture += '-';
			}
			else if (i >= 6 && (j == 2 || j == 9))
			{
				picture += '|';
			}
			else if (i == 9 && j >= 3 && j < 9)
			{
				picture += '_';
			}
			else
			{
				picture += ' ';
			}

		}
		left--; right++;
		picture += '\n';
	}
	return picture;
}



int main(int argc, char* argv[]) {
	// ============ welcome ==============================
	//DefineConsole();
	//PrintText("\t\t\tHello dear friend in my app!");
	//std::cout << esc << "[3A\r";
	//PrintText("\t\t\tWe will build your dream house!");
	//std::cout << esc << "[3A\r";
	//PrintText("\t\t\tI can help you with it!");
	//std::cout << esc << "[2J\r" << esc << "[0;0H\r"; // erase display and restore cursor to (0,0)
	// ============ welcome ==============================

	//std::cout << esc << "[0;0H\r";// line 0 column 3
	//std::cout << "oooooooooo\r";
	//std::cout << esc << "[3C" << "k";// line 0 column 3
	////std::cout << esc << "[3D" << "k";// line 0 column 3
	//getchar();
	//std::cout << esc << "[2;5f\r"; // line 0 column 5
	//std::cout << "t";
	//std::cout << esc << "[K\r"; // erase line
	//getchar();
	//std::cout << "my friend";
	//std::cout << esc << "[2J\r"; // erase display
	//std::cout << esc << "[2A\r" << esc << "[2;37m" << std::endl;

	// "================================================================================"
	//std::string consoleWidth = "To automatically close the console when debugging stops, enable Tools                      Automa";
	//int consoleWidthLength = 80;// consoleWidth.length(); // 80
	

	//std::string temp = "[0;" + std::to_string(consoleWidthLength) + "H";
	//std::string temp2 = "[0;" + std::to_string(consoleWidthLength-12) + "H";
	//std::cout << esc << temp << version_one_to_str() << '\r';
	//std::cout << esc << temp2 << version_one_to_str() << std::endl;

	//std::cout << esc << "[80C"; 
	//std::string str = version_one_to_str();
	//std::cout << str;

	//std::cout << esc << "[0;68H\r";
	//std::cout << version_one_to_str() << std::endl;

	// -----------------------------------------------------------

	v1_to_console();













	//version_two();

	//PrintRoof(12);


	//print_roof(2);

	//print_roof(22);
	//print_height(10,10,0);

	return 0;
}




/*
simple version

      /\
     /  \ 
	/    \ 
   /      \ 
  /        \
 |----------|
 |          |
 |          |
 |          |
 |          |
 |__________|

*/

/*
      /\
     /  \ ___
	/    \| |
   /      \ |
  /        \|
 /----------\
/|          |\
 |          |
 |          |
 |          |
 |__________|

 width / height= 

   /
  /
 /----------------------
/

conditions:
	-	get width
	-	get height
	-	pipe:
		* slim
		* fat
		~ left/right
*/
//void version_two()
//{
//
//	
//
//}
//
//void print_height(int height, int width, int tab = 0)
//{
//	for (size_t i = 0; i < height; i++)
//	{
//		for (size_t j = 0; j < width; j++)
//		{
//
//		}
//	}
//		std::cout << tab * ' ' << '|' << width * ' ' << '|';
//}
//
//void print_width(int width, char ch)
//{
//	for (size_t i = 1; i <= width; i++)
//	{
//		std::cout << ch;
//	}
//}
//

