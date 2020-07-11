// hw3.cpp :	Build your house as at the picture.
// author:      Nakonechnyi Mikhail
// date:        25.06.20
// version:     4.0 (11/07/2020)
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
/*
FUTURE WORK

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

#include <iostream>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstdarg>
#include <windows.h>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

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
		std::cout << "Enter " << category << ": ";
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

auto MaxHeight{
	/*
	* lambda for set a same width for text message
	*/
	[](const std::vector<int>& vect) 
	{
		int max{ 0 }; // INT_MIN
		for (auto val : vect)
		{
			if (max < val) { max = val; }
		}
		return max;
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
	SlowPrint(50, SumStr(str));
}

void SimpleHouseImplementation(int indexLine, int widthOfCursorStart, int height)
{
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
	const int roofHeight = height / 2;
	const int wallHeight = height - roofHeight;
	for (size_t i = roofHeight; i > 0; --i) {
		std::cout << esc << "[" + std::to_string(++indexLine) + ";" + std::to_string(widthOfCursorStart) + "H";
		for (size_t j = 0; j < i; ++j) {
			std::cout << " ";
		}
		std::cout << "/";
		for (size_t j = roofHeight; j - i > 0; --j) {
			std::cout << "  ";
		}
		std::cout << "\\" << std::endl;
	}
	const int doubleWallWidth = 2;
	int buildingWidth = roofHeight * 2;
	std::cout << esc << "[" + std::to_string(++indexLine) + ";" + std::to_string(widthOfCursorStart) + "H";
	for (size_t i = 0; i < buildingWidth + doubleWallWidth; ++i) {
		std::cout << "-";
	}
	std::cout << std::endl;
	for (size_t i = 0; i < wallHeight; ++i) {
		std::cout << esc << "[" + std::to_string(++indexLine) + ";" + std::to_string(widthOfCursorStart) + "H" << "|";
		for (size_t j = 0; j < buildingWidth; ++j) {
			std::cout << " ";
		}
		std::cout << "|" << std::endl;
	}
	std::cout << esc << "[" + std::to_string(++indexLine) + ";" + std::to_string(widthOfCursorStart) + "H";
	for (size_t i = 0; i < buildingWidth + doubleWallWidth; ++i) {
		std::cout << "-";
	}

}

int main(int argc, char* argv[]) {
	// ============ welcome ==============================
	DefineConsole();
	PrintText("\t\t\tHello dear friend in my app!");
	std::cout << esc << "[3A\r";
	PrintText("\t\t\tWe will build your dream house!");
	std::cout << esc << "[3A\r";
	PrintText("\t\t\tI can help you with it!");
	std::cout << esc << "[2J\r" << esc << "[0;0H\r"; // erase display and restore cursor to (0,0)
	// ============ welcome ==============================

	

	bool isPrinting = true;
	while (isPrinting)
	{
		std::vector<int> heightOfHouses;
		int fullConsoleWidth = GetInteger("max width for printing houses at your console");
		int sumOfHousesWidth{ 0 };
		std::cout << esc << "[2J\r"; // erase display
		std::cout << esc << "[1;0H";
		int countOfHouses = GetInteger("a count of houses which you want to build");
		std::cout << esc << "[2J\r"; // erase display
		int indexLine{ 1 };
		if (countOfHouses > 0) 
		{
			for (size_t i = 1; i <= countOfHouses; i++)
			{
				// a small bug with replase data at line if user has made a mistake with entering a correct number 
				std::cout << esc << "[" + std::to_string(indexLine) + ";0H";
				int height = GetInteger("the height of house["+ std::to_string(i) +"]");
				if (height < 5 && height > 150) {
					std::cout << esc << "[" + std::to_string(indexLine) + ";0H" << "height must be larger than 5 and smaller than 150\n";
					continue;
				}
				heightOfHouses.push_back(height);
				indexLine++;
			}
			for (const auto& widthOfHouses : heightOfHouses)
			{
				sumOfHousesWidth += widthOfHouses;
			}
			if ((sumOfHousesWidth + countOfHouses * 2) >= fullConsoleWidth)
			{
				std::cout << esc << "[2J\r"; // erase display
				std::cout << "Your common width of all houses is larger than \"Full Console Width\" ( " 
					+ std::to_string(fullConsoleWidth) + ") - count of houses * 2 (" + std::to_string(countOfHouses * 2) 
					+ " ) = " + std::to_string(fullConsoleWidth - countOfHouses * 2) + "\n";
				continue;
			}

			std::cout << esc << "[2J\r"; // erase display
			
			for (const auto& widthOfHouses : heightOfHouses)
			{
				int step = (widthOfHouses % 2 == 0) ? 2 : 1;
				indexLine = 1;
				fullConsoleWidth -= (widthOfHouses + step);
				SimpleHouseImplementation(indexLine, fullConsoleWidth, widthOfHouses-2); // small bug with height (-2 line for fundament)
			}
			//auto maxWidthOfHouse = max_element(std::begin(heightOfHouses), std::end(heightOfHouses)); // c++11
			int maxWidthOfHouse = MaxHeight(heightOfHouses);
			std::cout << std::endl;
			std::cout << esc << "[" + std::to_string(maxWidthOfHouse+2) + ";0H";
			system("pause");
			std::cout << esc << "[2J\r"; // erase display

			std::cout << "Do you want to build a houses again? (Enter: 1 (yes)/ 2 (no))\n";
			int choice = GetInteger("your choice");
			if (choice != 1)
			{
				isPrinting = false;
				break;
			}
		}
		else
		{
			std::cout << esc << "[2J\r"; // erase display
			std::cout << "Count of Houses must be larger than ZERO\n";
			continue;
		}
	}
	return 0;
}








