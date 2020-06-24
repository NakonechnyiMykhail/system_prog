// hw3.cpp : Build your house as at the picture.
// 

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

int main()
{
	int length = 11;
	int left = 5, right = 6;
	for (size_t i = 1; i < length-1; ++i)
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
			else if (i == 5 && j >=2 && j <= 9)
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

