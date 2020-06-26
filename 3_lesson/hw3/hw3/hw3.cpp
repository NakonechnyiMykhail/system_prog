// hw3.cpp : Build your house as at the picture.
// author:      Nakonechnyi Mikhail
// date:        25.06.20
// version:     2.0
// description of homework:
// 1. Нарисовать домик как на рисунке 
// 2. Дать возможность пользователю вводить высоту домика (задача со звездочкой)
// 3. Дать возможность ввести количество домиков. Домики рисуются справа на лево ( задача с двумя звездочками)
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

void version_one();
void version_two();
inline uint16_t get_int(std::string category);
void print_height(int height, int width, int tab);

int main()
{
	//version_one();

	//version_two();

	print_height(10,10,0);

	return 0;
}

void print_roof(int count)
{
	for (size_t i = count; i > 0; i--)
	{
		std::cout << " ";
	}
	
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
void version_two()
{

	

}

void print_height(int height, int width, int tab = 0)
{
		std::cout << tab * ' ' << '|' << width * ' ' << '|';
}

void print_width(int width, char ch)
{
	for (size_t i = 1; i <= width; i++)
	{
		std::cout << ch;
	}
}

void version_one()
{
	int length = 11;
	int left = 5, right = 6;
	for (size_t i = 1; i < length - 1; ++i)
	{
		for (size_t j = 0; j <= length; ++j)
		{

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
		std::cout << std::endl;
	}
}


inline uint16_t get_int(std::string category)
{
	/*
	Funtion:    print category and check inputting varieble for correct data
	Get:        integer varieble from user
	Return:     int
	*/
	uint16_t number { 0 };
	while (true)
	{
		std::cout << "Enter your " << category << ": ";
		std::cin >> number;

		if (std::cin.fail())
		{
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