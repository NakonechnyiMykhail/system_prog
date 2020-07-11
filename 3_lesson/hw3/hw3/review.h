#pragma once
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
	int index{ 1 };
	std::cout << esc << "[" + std::to_string(index) + ";80H";

	for (size_t i = 1; i < length - 1; ++i) {
		for (size_t j = 0; j <= length; ++j) {
			if (j == left) {
				std::cout << esc << "[" + std::to_string(++index) + ";80H" << '/';
			}
			else if (j == right) {
				std::cout << '\\';
			}
			else if (i == 5 && j >= 2 && j <= 9) {
				std::cout << esc << "[" + std::to_string(++index) + ";80H" << '-';
			}
			else if (i >= 6 && (j == 2 || j == 9)) {
				std::cout << '|';
			}
			else if (i == 9 && j >= 3 && j < 9) {
				std::cout << '_';
			}
			else {
				std::cout << esc << "[" + std::to_string(++index) + ";80H" << ' ';
			}

		}
		left--; right++;
		std::cout << "\n" << esc << "[" + std::to_string(++index) + ";80H";
	}
}

std::string version_one_to_str() {
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


// FROM MAIN =========================================================
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

	//v1_to_console();
	//version_two();

	//PrintRoof(12);


	//print_roof(2);

	//print_roof(22);
	//print_height(10,10,0);
// FROM MAIN =========================================================



