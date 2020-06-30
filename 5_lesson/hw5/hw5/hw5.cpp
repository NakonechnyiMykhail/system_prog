// hw5.cpp :    Encrypt/Decrypt string with XOR
// author:      Nakonechnyi Mikhail
// date:        28.06.20
// version:     1.0
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




#include <iostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <cstdint>

using namespace std;

void cipherEncryption() {
    std::string msg;
    std::cout << "Enter message: ";
    getline(cin, msg);
    //std::cin(msg, 50).get()

    std::string key;
    std::cout << "Enter key: ";
    std::getline(std::cin, key);

    std::string encryptHexa = "";
    int keyItr = 0;
    std::stringstream res;
    for (size_t i = 0; i < msg.length(); ++i) {
        int temp = msg[i] ^ key[keyItr];

        res << std::hex << std::setfill('0') << std::setw(2) << (int)temp;
        keyItr++;
        if (keyItr >= key.length()) {
            // once all of key's letters are used, repeat the key
            keyItr = 0;
        }
    }
    res >> encryptHexa;
    std::cout << "Encryption Text: " << encryptHexa;
}

void cipherDecryption() {
    std::string msg;
    std::cout << "Enter message: ";
    std::getline(std::cin, msg);

    std::string key;
    std::cout << "Enter key: ";
    std::getline(std::cin, key);

    std::string hexToUni = "";
    
    for (size_t i = 0; i < msg.length() - 1; i+=2) {
        // splitting hex into a pair of two
        std::string output = msg.substr(i, 2);

        // converting hex into unicode
        int decimal = strtol(output.c_str(), NULL, 16);
        hexToUni += (char)decimal;    
    }
    std::string decryptText = "";
    int keyItr = 0;
    for (size_t i = 0; i < hexToUni.length(); ++i) {
        int temp = hexToUni[i] ^ key[keyItr];

        decryptText += (char)temp;
        keyItr++;
        if (keyItr >= key.length()) {
            // once all of key's letters are used, repeat the key
            keyItr = 0;
        }
    }

    std::cout << "Decryption Text: " << decryptText;
}

int GetInteger()
{
    /*
    Funtion:    print category and check inputting varieble for correct data
    Get:        integer varieble from user
    Return:     int
    */
    uint16_t number{ 0 };
    while (true)
    {
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

int main()
{
    std::cout << "1. Encryption\n2. Descryption\nChoice(1,2): ";
    int choice = 2; // getInteger()

    if (choice == 1) {
        std::cout << std::endl << "---Encryption---" << std::endl;
        cipherEncryption();
    }
    else if (choice == 2) {
        std::cout << std::endl << "---Decryption---" << std::endl;
        cipherDecryption();
    }
    else {
        std::cout << std::endl << "Wrong choice" << std::endl;
    }

    return 0;
}
