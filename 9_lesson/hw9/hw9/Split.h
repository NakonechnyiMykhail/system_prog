#pragma once

struct Tokens {
	Tokens* next{ nullptr };
	int length{ 0 };			// length of char before a token
};

void Split(const char* str, char delimiter, char** tokens);
//char** Split(const char* str, char delimiter, char** tokens);
