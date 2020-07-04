// TestApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

// 1. start() - prepare params for main
// 2. main()
//int main(int argc, char** argv)
int main(int argc, const char* argv[])
{
	// main arguments
	for (size_t i = 0; i < argc; i++) {
		std::cout << argv[i] << std::endl;
		// anaconda3 powershell
			//(base)PS D : \courses\codebase\8_lesson\TestApp\Debug > .\TestApp.exe
			//D : \courses\codebase\8_lesson\TestApp\Debug\TestApp.exe
			//Hello World!
			//(base)PS D : \courses\codebase\8_lesson\TestApp\Debug > .\TestApp.exe hello
			//D : \courses\codebase\8_lesson\TestApp\Debug\TestApp.exe
			//hello
			//Hello World!
			//(base)PS D : \courses\codebase\8_lesson\TestApp\Debug >
	}

    return 0;
}
