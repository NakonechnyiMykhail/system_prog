// hw5.cpp :    Encrypt/Decrypt string with XOR
// author:      Nakonechnyi Mikhail
// date:        28.06.20
// version:     3.0
// description of homework task:
// Реализовать криптование / декриптование строки.Приложение для криптования или декриптования
// принимает строку и ключ криптования длиной 8 байт.Для криптования должна быть применена
// операция XOR, а результат криптования следующего байта должен зависить от результата криптования
// предыдущего.
//
// Expect:
// Результат работы приложения должен быть представлен в таком виде, чтобы его можно было скопировать
// и подать на вход приложения для декриптования
//
// Hint:
// Вам для решения нужно посмотреть на то, как работает xor, а также как преобразовать строковое
// предстваление числа в int
//

// links:
// https://en.wikipedia.org/wiki/Exclusive_or
// https://en.wikipedia.org/wiki/XOR_cipher
// https://codeby.net/threads/prjachem-stroki-v-programmax-c.69031/
// https://evileg.com/ru/post/271/
// https://habr.com/ru/company/yandex/blog/324866/
// https://habr.com/ru/post/183462/
// https://habr.com/ru/company/yandex/blog/324866/
// https://habr.com/ru/company/yandex/blog/327636/

/*
1. Ключ шифрования для операции XOR.
Меняются только те биты двоичного числа, которые в маске имеют значение(1).
То-есть, если ключ как в примере выше =2, то изменится всего 1 бит в оригинальном байте,
т.к. 02 = 0000.0010. У однобайтного ключа рассеиваемость должна быть намного больше -
минимум 4 бита из 8-ми, например 0110.1011 = 0x6b, или что-то в этом роде.

2. Длинна ключа для операции XOR.
1-байтный ключ имеет всего 255 возможных вариантов, и подобрать его перебором не составит
труда. А вот 2-байтный ключ имеет уже 65'535 вариантов, 4-байтный вообще 4'294'967'295 и т.д.
Плюс не забываем про рассеиваемость единиц в нём.

3. Интересной особенность операции XOR является то, что если текст везде ксорится одним ключом,
то по исходному и зашифрованному тексту можно найти ключ. То-есть:

C-подобный:
A xor 1234 = C
С xor 1234 = A
--------------
С xor A = 1234
Поэтому шифровать строки можно/нужно разными ключами, чтобы по одной строке взломщик не смог расшифровать
другие. В этом случае, помогает обычный инкремент ключа на каждом байте. Например, чтобы зашифровать строку
"HELLO" выбираем стартовый ключ(0x77) и шифруем: "H"=0x77, "E"=0х78, "L"=0х79, "L"=0х7a, "O"=0х7b, и т.д.
Такая обычная смена алгоритма уже не позволит вычислить ключ по С xor A = 1234

4. А вообще, шифровать нужно блочным шифром, например 512 или 1К-битным ключом (сразу по 64/128 символов
соответственно). Не знаю как в никсах, а винда имеет специальные криптографические API-функции типа
CryptGenRandom() из Advapi32.dll и ей подобных. Эти функции позволяют задавать длину ключа в аргументах.
Теоритически, такие строки нельзя будет расшифровать вообще, или потребуется минимум 1000 и одна ночь.
Если мы шифруем не свои рекорды в косынке или солитёр, а например номера банковских карт, то лучше
использовать эти API.

5. Хорошим тоном является "динамическое шифрование" в программах, когда перед вывод строки на экран мы
её расшифровываем, и после - опять шифруем. Иначе, после загрузки программы в память, можно просто сдампить
в файл секцию, и получим все строки в явном виде. В вашем-же случае, строки остаются закодированы только на
диске, а в памяти - всё в стиле "ню"

XOR table:

Input	Output
A	B
0	0	0
0	1	1
1	0	1
1	1	0

Bitwise operation
1 XOR 1 = 0
1 XOR 0 = 1
0 XOR 1 = 1
0 XOR 0 = 0
1110 XOR 1001 = 0111

Example:
---------------------------------------------------------------------
the string "Wiki"
W = (dec) 87    = (hex) 57 = (bin) 01010111     // 64+16+4+2+1
i = (dec) 105   = (hex) 69 = (bin) 01101001     // 64+32+8+1
k = (dec) 107   = (hex) 6b = (bin) 01101011     // 64+32+8+2+1
i = (dec) 105   = (hex) 69 = (bin) 01101001     // 64+32+8+1

(01010111 01101001 01101011 01101001 in 8-bit ASCII)
---------------------------------------------------------------------
key 11110011
---------------------------------------------------------------------
ENCRYPT:
		01010111 01101001 01101011 01101001
(+) 	11110011 11110011 11110011 11110011
=	    10100100 10011010 10011000 10011010

result: 0x66 0x58 0x5a 0x58 = (102) f - (88) X - (90) Z - (88) X
_________________________________________________________________________________________________
?????output: 128+32+4 - 128+16+8+2 - 128+16+8 - 128+16+8+2 = 164 - 154 - 152 - 154
				=
_________________________________________________________________________________________________

---------------------------------------------------------------------
DECRYPT:
		10100100 10011010 10011000 10011010
(+) 	11110011 11110011 11110011 11110011
=	    01010111 01101001 01101011 01101001

---------------------------------------------------------------------
*/
#include <algorithm>
#include <bitset>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <windows.h>

void XOR(DWORD startAddress, DWORD dwSize) {
	// https://www.youtube.com/watch?v=AKV9PF-k9qQ
	_asm {									//inline assembly
		push eax
		push ecx
		mov ecx, startAddress				//putting the start address of the memory block in the ECX register
		add ecx, dwSize						//adding the size of the memory block to the ECX register
		mov eax, startAddress				//put the start address into the EAX register

		encryption:							//our encryption loop
		xor byte ptr ds : [eax] , 0x24		//XOR the byte with 0x7F - can make this whatever byte value we want
			inc eax							//incrementing eax
			cmp eax, ecx					//comparing eax register with ecx
		jl encryption;						//jump back to the start of our loop

		pop ecx								//putting the top of the stack into ECX register
		pop eax								//putting the top of the stack into EAX register
	}
}

void HexDump(void* addr, int len) {
	int i{ 0 };
	unsigned char buff[17];
	unsigned char* pc = static_cast<unsigned char*>(addr);

	for (size_t i = 0; i < len; i++) {		//process every byte in the data
		if ((i % 16) == 0) {				//multiply of 16 means new line (with line offset)
			if (i != 0) {					//don't print zeroth ASCII
				printf(" %s\n", buff);
			}
			printf(" %04x ", i);			//print offset
		}

		printf(" %02x", pc[i]);				//now the hex code for the specific character


		if ((pc[i] < 0x20) || (pc[i] > 0x7E)) {
			buff[i % 16] = '.';
		}
		else {
			buff[i % 16] = pc[i];
		}

		buff[(i % 16) + 1] = '\0';			//null-terminator

	}

	while ((i % 16) != 0) {					//pad out last line of not exactly 16 characters
		printf("   ");
		i++;
	}

	printf(" %s\n", buff);					//print final ASCII bit
}


/////////////////////////////////////////////////////////////////////////////////////////
// Реализов функцию шифрования и дешифрования строк. 
// принцип шифрования : 
// на все биты каждого символа наложить восьми битную маску (операция XOR), 
// затем поменять местами четные и нечетные биты. 
// после шифрования напечатать коды символов зашифрованной строки и полученную строку . 
// дешифровать результат и убедиться что строока равна исходной.
//
//typedef std::string  T_str;

std::string FromDOS(const std::string& DOS_string) {
	char buf[255];
	OemToCharA(DOS_string.c_str(), buf);
	return buf;
}

std::string XorToKey(const std::string& s, unsigned key) {
	struct  T_xor_to_key {
		unsigned  key_;
		//-------------------------------------------------------------------------------
		T_xor_to_key(unsigned  key) : key_(key)
		{}
		//-------------------------------------------------------------------------------
		char  operator() (char  symb) {
			return symb ^ key_;
		}
	};
	std::string res_s;
	std::transform(s.begin(), s.end(), std::back_inserter(res_s), T_xor_to_key(key));
	return  res_s;
}

std::string SwapOddAndEvenBits(const std::string& s) {
	struct  T_swap_odd_and_even_bits {
		char  operator() (char  symb) {
			char  even_bits = symb & std::bitset<8>(std::string("10101010")).to_ulong();
			even_bits >>= 1;
			even_bits &= std::bitset<8>(std::string("01111111")).to_ulong();

			char  odd_bits = symb & std::bitset<8>(std::string("01010101")).to_ulong();
			odd_bits <<= 1;

			return  even_bits | odd_bits;
		}
	};
	std::string res_s;
	std::transform(s.begin(), s.end(), std::back_inserter(res_s), T_swap_odd_and_even_bits());
	return  res_s;
}

std::string Encode(const std::string& s, unsigned key) {
	return  SwapOddAndEvenBits(XorToKey(s, key));
}

std::string Decode(const std::string& s, unsigned key) {
	return  XorToKey(SwapOddAndEvenBits(s), key);
}
/////////////////////////////////////////////////////////////////////////////////////////

std::string SimpleXOR(const std::string& data, const char* key) {
	std::string xor_str = data;
	for (size_t i = 0; i < xor_str.length(); i++) {
		xor_str[i] = data[i] ^ key[i];
	}
	return xor_str;
}

// Lesson6 HomeWork review
void XOR_crypt() {
	//char c = 1;
	//char k = 1;
	//std::cout << (c ^ k);

	char msg[] = "Hello World!!";
	char key[] = "12345678";
	for (size_t i = 0; i < sizeof(msg) - 1; ++i) {
		int keyIndex = 0;
		if (i < sizeof(key)) {
			keyIndex = i;
		}
		if (i != 0) {
			*(msg + i) ^= key[keyIndex];
			*(msg + i) ^= *(msg + i - 1);
		}
		else {
			*(msg + i) ^= key[keyIndex];
		}

	}
	std::cout << "Encryption Text: " << msg << std::endl;
	char prevSymb = 0;
	for (size_t i = 0; i < sizeof(msg) - 1; ++i) {
		int keyIndex = 0;
		if (i < sizeof(key)) {
			keyIndex = i;
		}
		if (i != 0) {
			char tmp = *(msg + i);
			*(msg + i) ^= key[keyIndex];
			*(msg + i) ^= prevSymb;
			prevSymb = tmp;
		}
		else {
			prevSymb = *(msg + i);
			*(msg + i) ^= key[keyIndex];//msg[i]
		}
	}
	std::cout << "Decryption Text: " << msg << std::endl;
}

std::string CipherEncryption(const std::string& msg, const std::string& key, int state) {
	std::string encryptHexa = "";
	unsigned int temp{ 0 }, keyItr{ 0 };
	std::stringstream res;
	std::string xorstring = msg;

		
	if (state == 2) { // --- CODE export ASCII/UNICODE ?? -----
		for (size_t i = 0; i < msg.length(); ++i) {
			if (i != 0) {
				xorstring[i] ^= key[keyItr];
				xorstring[i] ^= xorstring[i - 1];
			}
			else {
				xorstring[i] ^= key[keyItr];
			}
			//std::cout << "xorstring [" << i <<"] " << xorstring[i] << std::endl;
			keyItr++;
			if (keyItr >= key.length()) {
				// once all of key's letters are used, repeat the key
				keyItr = 0;
			}
			//encryptHexa += xorstring[i];
		}
		std::cout << "Encrypted Text: " << xorstring;
		return xorstring;
	} 
	else { // --- CODE export HEX -----
		for (size_t i = 0; i < msg.length(); ++i) {
			if (i != 0) {
				temp = xorstring[i] ^ key[keyItr];
				temp ^= xorstring[i - 1];
			}
			else {
				temp = xorstring[i] ^ key[keyItr];
			}
			//std::cout << "temp/(int) [" << i << "]: "<< temp << "\t" << (int)temp << std::endl;
			res << std::hex << std::setfill('0') << std::setw(2) << (int)temp;
			//std::cout << std::hex << std::setfill('0') << std::setw(2) << (int)temp << std::endl;
			keyItr++;
			if (keyItr >= key.length()) {
				// once all of key's letters are used, repeat the key
				keyItr = 0;
			}
		}
		res >> encryptHexa;
		std::cout << "Encrypted Text: " << encryptHexa << std::endl;
		return encryptHexa;
	}
}

std::string CipherDecryption(const std::string& msg, const std::string& key, int state) {
	std::string hexToUni = "";
	unsigned int keyItr{ 0 };
	std::string decryptText = "";

	if (state == 2) {// --- CODE export ASCII/UNICODE ?? -----
		decryptText = msg;
		for (size_t i = 0; i < msg.length(); ++i) {
			if (i != 0) {
				decryptText[i] = msg[i] ^ key[keyItr];
				decryptText[i] ^= msg[i - 1];
			}
			else {
				decryptText[i] = msg[i] ^ key[keyItr];
			}

			keyItr++;
			if (keyItr >= key.length()) {
				// once all of key's letters are used, repeat the key
				keyItr = 0;
			}
		}
	}
	else {// --- CODE export HEX -----
		
		for (size_t i = 0; i < msg.length() - 1; i += 2) {
			// splitting hex into a pair of two
			std::string output = msg.substr(i, 2);
				
			// converting hex into unicode
			int decimal = strtol(output.c_str(), NULL, 16);
			hexToUni += (char)decimal;
		}
		std::cout << hexToUni << std::endl;
		for (size_t i = 0; i < hexToUni.length(); ++i) { // size == length
			if (i != 0) {
				hexToUni[i] ^= key[keyItr]; // [i % (sizeof(key) / sizeof(char))]
				hexToUni[i] ^= hexToUni[i - 1];
			}
			else {
				hexToUni[i] ^= key[keyItr];
			}
			decryptText += hexToUni[i];// (char)temp;

			keyItr++;
			if (keyItr >= key.length()) {
				// once all of key's letters are used, repeat the key
				keyItr = 0;
			}
		}
	}

	std::cout << "Decrypted Text: " << decryptText << std::endl;
	return decryptText;
}

void BruteForce(
	int keylen,
	const std::string& ciphertext, 
	const std::string& plaintext, 
	bool EnableAlphabetLower,
	bool EnableAlphabetUpper,
	bool EnableNumerals,
	bool EnableAnsi, 
	const char* tempkey = ""
) {
	// ASCII https://xor.pw/?#
	// https://www.youtube.com/watch?v=qhi4G-wUDt0
	// review 
	std::string numerals = "0123456789";
	std::string alphabetLower = "abcdefghijklmnopqrstuvwxyz";
	std::string alphabetUpper = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	std::string specialAnsi = "!\"@#$%^&*~|/?.,<>;:'+=-_`\\ ()";

	static int iterations = 0;
	std::string consoleTitle;
	std::string decipher;
	iterations++;
	if (keylen == 0) {
		decipher = SimpleXOR(ciphertext, tempkey); // Only for ASCII
		consoleTitle = "Key: '" + std::string(tempkey);
		std::cout << decipher << "Iterations: " << iterations << std::endl;
		//SetConsoleTitle(consoleTitle.c_str());
		if (decipher == plaintext) {
			std::cout << "Key found! It is : '" << tempkey << "'";
			std::cout << "It took " << iterations << " iterations to find the key!";
		}
		return;
	}

	// for lower alphabet
	if (EnableAlphabetLower) {
		for (size_t i = 0; i < alphabetLower.length(); i++) {
			std::string appended = tempkey + alphabetLower[i];
			BruteForce(keylen - 1, ciphertext, plaintext, 
				EnableAlphabetLower,
				EnableAlphabetUpper,
				EnableNumerals,
				EnableAnsi,
				appended.c_str());
		}
	}
	// for upper alphabet
	if (EnableAlphabetUpper) {
		for (size_t i = 0; i < alphabetUpper.length(); i++) {
			std::string appended = tempkey + alphabetUpper[i];
			BruteForce(keylen - 1, ciphertext, plaintext,
				EnableAlphabetLower,
				EnableAlphabetUpper,
				EnableNumerals,
				EnableAnsi,
				appended.c_str());
		}
	}
	// for numerals
	if (EnableNumerals) {
		for (size_t i = 0; i < numerals.length(); i++) {
			std::string appended = tempkey + numerals[i];
			BruteForce(keylen - 1, ciphertext, plaintext,
				EnableAlphabetLower,
				EnableAlphabetUpper,
				EnableNumerals,
				EnableAnsi,
				appended.c_str());
		}
	}
	// for numerals
	if (EnableAnsi) {
		for (size_t i = 0; i < specialAnsi.length(); i++) {
			std::string appended = tempkey + specialAnsi[i];
			BruteForce(keylen - 1, ciphertext, plaintext,
				EnableAlphabetLower,
				EnableAlphabetUpper,
				EnableNumerals,
				EnableAnsi,
				appended.c_str());
		}
	}
}

int GetInteger(std::string category) {
	/*
	Funtion:    print category and check inputting varieble for correct data
	Get:        integer varieble from user
	Return:     int
	*/
	int number{ 0 };
	while (true)
	{
		std::cout << "\nEnter your " << category << ": ";
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

std::string GetString(std::string category)
{
	/*
	Funtion:    print category and check inputting varieble for correct data
	Get:        string varieble from user
	Return:     string
	*/
	std::string str;
	while (true)
	{
		std::cout << "Enter your " << category << ": ";
		std::getline(std::cin, str); // get all line

		bool bRejected = false;

		// checking each character at the entered word
		for (std::size_t nIndex = 0; nIndex < str.length() && !bRejected; ++nIndex)
		{
			// if a current character is a letter -> ok
			if (isalpha(str[nIndex])) { continue; }

			// if we want to allow "SPACE"
			//if (str[nIndex] == ' ') { continue; }

			// another situations - re-enter 
			bRejected = true;
		}
		// if all is good
		if (!bRejected && str.length() > 1) { break; }
	}
	return str;
}

int main()
{
	std::locale::global(std::locale(""));
	srand(static_cast<unsigned>(time(0)));
	std::string msg;
	std::cout << "\nEnter message: ";
	std::getline(std::cin, msg);

	std::string key;
	std::cout << "\nEnter key: ";
	std::getline(std::cin, key);
	std::string encText, decText;
	int code = 1;

	while (code != 6)
	{
		
		std::cout <<"\n1. Hex (default)"
					"\n2. Unicode"
					"\n3.(+/-) Unicode with bitwise shift"
					"\n4.(+/-) Crack your key(brutforce)"
					"\n5. ASM encryption"
					"\n6. Exit"
					"\nChoose(1,2,3,4,5,6)";
		code = GetInteger("choice");
		if (code == 6) { return 0; }
		switch (code)
		{
		case 1: {// HEX works
			std::cout << std::endl << "\n---Encryption---" << std::endl;
			encText = CipherEncryption(msg, key, code);
			std::cout << std::endl << "\n---Decryption---" << std::endl;
			decText = CipherDecryption(encText, key, code);
			break;
		}
		case 2: {
			std::cout << std::endl << "\n---Encryption---" << std::endl;
			encText = CipherEncryption(msg, key, code);
			std::cout << std::endl << "\n---Decryption---" << std::endl;
			decText = CipherDecryption(encText, key, code);
			break;
		}
		case 3: {// with bitwise shift

			//unsigned  key = rand();
			uint64_t key = 2552625742224436547;
			std::cout << key << std::endl;
			//std::cout << "Enter the line: ";

			std::string DOS_str = GetString("the line");
			//getline(std::cin, DOS_str);
			if (DOS_str.empty()) { break; }
			std::string s = FromDOS(DOS_str);
			std::string coded_s = Encode(s, key);
			std::string decoded_s = Decode(coded_s, key);
			std::cout << "Encrypt line:"
				<< coded_s
				<< std::endl
				<< "Decrypt line:"
				<< decoded_s
				<< std::endl;

			break;
		}
		case 4: {
			std::string ciphertext = GetString("ciphertext");			// EPEC
			std::string plaintext = GetString("plaintext");				// test
																		// key=1567
			std::cout << std::endl << "\n---Brutforce---" << std::endl;
			BruteForce(4, ciphertext, plaintext,
				true, // lower
				false, // upper
				false, // numerals
				false, // ansi
				"");
			break;
		}
		case 5: {
			std::string text = "Test String"; // ???? GetString("text");
			std::cout << "Text:\n\n";
			HexDump(&text, text.length());

			std::cout << "Encrypted:\n\n";
			XOR((DWORD)&text, sizeof(text));
			HexDump(&text, text.length());
			system("pause");
		}
		default:
			std::cout << std::endl << "\n---EXIT---" << std::endl;
			break;
		}
	}

	return 0;
}

/*
// REVIEW versions 
//void encodeDecode(const char* input, const char* key)
//{
//    //const char* input;
//    //int inputLength = strlen(input);
//    //const char* key;
//    //int keyLength = strlen(key);
//
//    ////char output;
//    //std::string output;
//
//
//    //for (int i = 0; i < inputLength; ++i) // const char* -> inputLength +1
//    //{
//    //
//    //    output[i] = input[i] ^ key[i % keyLength]; // keyLength + 1
//    //    //std::cout << static_cast<unsigned char>(input[i] ^ key[i % keyLength]);
//    //    std::cout << output[i];
//    //}
//    //std::cout << std::endl;
//    ////return output;
//}
//
//void decrypt(std::string VALUE, std::string KEY)
//{
//    std::string const  value = VALUE;// argv[1];
//    std::string const  key = KEY;//argv[2];
//
//    std::cout << "string " << value << " (\"";
//    for (std::size_t loop = 0; loop < value.size(); ++loop)
//    {
//        std::cout
//            << (char)(static_cast<unsigned int>(value[loop] ^ key[loop % key.size()]));
//    }
//    std::cout << "\"," << value.size() << ");\n";
//}
//
//void encrypt(std::string VALUE, std::string KEY)
//{
//    std::string const  value = VALUE;// argv[1];
//    std::string const  key = KEY;//argv[2];
//
//    std::cout << "string " << value << " (\"";
//    for (std::size_t loop = 0; loop < value.size(); ++loop)
//    {
//        std::cout << "\\x"
//            << std::hex
//            << std::setw(2)
//            << std::setfill('0')
//            << static_cast<unsigned int>(value[loop] ^ key[loop % key.size()]);
//    }
//    std::cout << "\"," << value.size() << ");\n";
//}
//
////string Martin("\x14\x0e\x00\x1f\x30\x01", 6);
////
////string Wiki("\x66\x58\x5a\x58", 4);
*/