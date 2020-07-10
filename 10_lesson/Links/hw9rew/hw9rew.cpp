// hw9rew.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int GetDelimitersCount(const char* str, char delimiter) {
	int count{ 0 };
	for (size_t i = 0; str[i]; i++) {
		if (str[i] == delimiter) {
			++count;
		}
	}
	return count;
}

char** Split(const char* str, char delimiter) {
	int delimitersCount = GetDelimitersCount(str, delimiter);
	char** arr = new char* [delimitersCount + 1];
	const int arrSize = delimitersCount + 2;
	int curDelimiter{ 0 }, prevDelimiter{ 0 };
	char* resStr = new char[strlen(str)];
	for (size_t i = 0; i <= strlen(str); i++) {
		//resStr[i] = str[i];   ==    *(resStr + i) = *(str + i);
		if (str[i] == delimiter) {
			resStr[i] = '\x0'; // == 0 == \0
			arr[curDelimiter++] = &resStr[prevDelimiter];
			prevDelimiter = i + 1;
		}
		else {
			resStr[i] = str[i];
		}
	}
	arr[curDelimiter] = &resStr[prevDelimiter];
	arr[arrSize - 1] = 0;

	return arr;
}

// version 2 by copy
char** SplitCopy(const char* str, char delimiter) {
	int currentToken{ 0 };
	int delimiterCount = GetDelimitersCount(str, delimiter);
	char** tokens = new char * [delimiterCount + 1];
	size_t prevDelimiterPos{ 0 };
	size_t currDelimiterPos{ 0 };
	for (; str[currDelimiterPos]; ++currDelimiterPos) {
		if (str[currDelimiterPos] == delimiter) {
			char* tmpStr = new char[currDelimiterPos - prevDelimiterPos + sizeof('\x0')];
			for (size_t i = 0; i < currDelimiterPos - prevDelimiterPos; ++i) {
				tmpStr[i] = str[prevDelimiterPos + i];
			}
			tmpStr[currDelimiterPos - prevDelimiterPos] = '\x0';
			prevDelimiterPos = currDelimiterPos + sizeof(delimiter);
			tokens[currentToken] = tmpStr;
			currentToken += 1;
		}
	}
	//copy the last token
	char* tmpStr = new char[currDelimiterPos - prevDelimiterPos + sizeof('\x0')];
	for (size_t i = 0; i < currDelimiterPos - prevDelimiterPos; ++i) {
		tmpStr[i] = str[prevDelimiterPos + i];
	}
	tmpStr[currDelimiterPos - prevDelimiterPos] = '\x0';
	tokens[currDelimiterPos++] = tmpStr;
	tokens[currDelimiterPos] = '\x0'; // 0

	return tokens;
}


int main()
{
	//char** arr = Split("111-222222222-33-44444444", '-');
	//char** arr = Split("--4-4-", '-');
	//for (size_t i = 0; arr[i]; i++) {
	//	std::cout << arr[i] << std::endl;
	//}

	//v2
	char** arr2 = SplitCopy("111-222222222-33-44444444", '-');
	for (size_t i = 0; arr2[i]; i++) {
		std::cout << arr2[i] << std::endl;
	}

	return 0;
}

