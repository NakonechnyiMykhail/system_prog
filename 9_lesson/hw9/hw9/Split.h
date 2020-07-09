#pragma once
#include <iostream>
#include <string>
#include <vector>

struct Tokens {
	Tokens* next{ nullptr };
	int length{ 0 };			// length of char before a token
	std::string str;
};

void Split(const char* str, char delimiter, char** tokens);
std::vector<std::string> SplitVector(const std::string& s, char delim);
std::vector<std::string> SplitVector2(const std::string& str, const std::string& delim);
void SplitToks(const std::string& str, char delim, Tokens* toks);