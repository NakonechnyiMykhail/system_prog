#include "Split.h"
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

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
	std::string tmpStr = "";
	//const char* tmpStr = "";				// this version doesn't work
	int length = strlen(str);
	int sizeOfWord{ 1 }, countOfWords{ 0 };
	if (!tokens) {
		countOfWords = CountOfDelimiters(str, delimiter);
		tokens = new char* [countOfWords];
	}

	for (size_t index = 0, count = 0; index <= strlen(str); ++index) {
		if (str[index] != delimiter && str[index] != '\0') {
			tmpStr += str[index];
			sizeOfWord++;
		}
		else if (count < countOfWords) {
			tokens[count] = new char[sizeOfWord];

			for (size_t i = 0; i < sizeOfWord; ++i) {
				tokens[count][i] = tmpStr[i];
			}
			sizeOfWord = 1;
			tmpStr = "";
			count++;
		}
	}

	// print
	for (size_t i = 0; i < countOfWords; i++) {
		std::cout << "[" << i << "] = " << tokens[i] << std::endl;
	}
	// delete
	for (size_t i = 0; i < countOfWords; i++) {
		delete[] tokens[i];
	}
}

std::vector<std::string> SplitVector(const std::string& s, char delim) {
	std::vector<std::string> result;
	std::stringstream ss(s);
	std::string item;

	while (getline(ss, item, delim)) {
		result.push_back(item);
	}

	return result;
}

std::vector<std::string> SplitVector2(const std::string& str, const std::string& delim) {
	std::vector<std::string> tokens;
	size_t prev = 0, pos = 0;
	do {
		pos = str.find(delim, prev);
		if (pos == std::string::npos) pos = str.length();
		std::string token = str.substr(prev, pos - prev);
		if (!token.empty()) tokens.push_back(token);
		prev = pos + delim.length();
	} while (pos < str.length() && prev < str.length());
	return tokens;
}

void SplitToks(const std::string& str, char delimiter, Tokens* toks) {
	int countOfWords = CountOfDelimiters(str, delimiter);

	for (size_t i = 0; i < countOfWords; i++) {

	}
}