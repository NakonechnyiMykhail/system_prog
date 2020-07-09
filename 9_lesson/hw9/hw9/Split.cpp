#include "Split.h"
#include <iostream>

auto CountOfDelimiters {
	/*
	* lambda for search counts of delimiters
	*/
	[](auto str, auto delimiter) {
		int count{ 0 };
		//for (const auto& i : str) {
		for (size_t i = 0; i < strlen(str); ++i) {
			if (str[i] == delimiter) {
				count++;
			}
		}
		return (count+1);
	}
};

void Split(const char* str, char delimiter, char** tokens) {
	//Tokens tokens{ nullptr };
	std::string tmpStr = "";
	//const char* tmpStr = "";				// this version doesn't work
	int length = strlen(str);
	int count{ 0 }, sizeOfWord{ 1 }, countOfWords{ 0 };
	if (!tokens) {
		countOfWords = CountOfDelimiters(str, delimiter);
		tokens = new char* [countOfWords];
	}

	std::cout << "count of words = " << countOfWords << std::endl;


	//while (str[index] != '\0' )
	for (size_t index = 0; index <= strlen(str); ++index) {
		if (str[index] != delimiter && str[index] != '\0') {
			//*(tokens + index) = reinterpret_cast<char*>(str[index]);
			////tokens[count] += tmp; // *(tokens + i) ???
			tmpStr += str[index];
			//tmpStr[index] += str[index];
			std::cout << "tmpStr = " << tmpStr << "sizeOfWord = " << sizeOfWord << std::endl;

			sizeOfWord++;
		}
		else if (count < countOfWords) {
			tokens[count] = new char[sizeOfWord];
			//std::cout << "count = " << count << std::endl;

			for (size_t i = 0; i < sizeOfWord; ++i) {
				//tokens[count][i] = tmpStr[i];
				//**(tokens + i) = tmpStr[i];
				tokens[count][i] = tmpStr[i];
				//tokens[count] = new sizeof(tmpStr.c_str());
				//tokens[count] = tmpStr.c_str(); // static_cast<char*>();
			}
			sizeOfWord = 1;
			tmpStr = "";
			count++;
			std::cout << "count = " << count << "tmpStr = " << tmpStr << "sizeOfWord = " << sizeOfWord << std::endl;

		}

	}

	//for (const auto& element : token)

	// print
	for (size_t i = 0; i < countOfWords; i++) {
		std::cout << "[" << i << "] = " << tokens[i] << std::endl;
	}
	// delete
	for (size_t i = 0; i < countOfWords; i++) {
		delete[] tokens[i];
	}

}

//char** Split(const char* str, char delimiter, char** tokens);

//void Split2s(const char* str, char delimiter, char* tokens[]) {
//	//Tokens tokens{ nullptr };
//	
//	int length = strlen(str);
//	int count{ 0 }, index{ 0 }, newSize{ 0 };
//	std::string tmpStr = "";
//	//const char* tmpStr = "";
//	while (str[index] != '\0') {
//		if (str[index] == delimiter) {
//			++count;
//			//tokens[count] = nullptr;
//			//*(tokens + index) = reinterpret_cast<char*>(str[index]);
//			//std::cout << str[index] << std::endl; -> OK
//		}
//		tokens[count][index] = reinterpret_cast<char*>(str[index]);
//
//
//		index++;
//	}
//
//	//for (const auto& element : **token)
//
//	for (size_t i = 0; i < count; i++) {
//		std::cout << "[" << i << "] = " << tokens[i] << std::endl;
//	}
//}


