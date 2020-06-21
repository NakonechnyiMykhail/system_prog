// hw2.cpp:     User Profile
// author:      Nakonechnyi Mikhail
// date:        20.06.20
// version:     1.0
/* description of homework:
Заимплементить приложение анкеты которое должно запросить у пользователя:
        First name
        Last name
        Age
        Daily wage
        Position

Сохранить полученные данные и вывести в формате:
        Name: Полное Имя;
        Age: возраст;
        TermUntilRetirement: количество лет до пенисии ( пенсия в 55)
        AnnualSalary (годовая зп за вычетом налогов 20 %. В году 250 рабочих дней)
        Position: должность

*/
/* 
BUG:            if I use get_str for "position" varieble in the end. 
WORKING:        this version and if I use standard practice with cout and cin
NEED TO FIX:    I guess first step of position -> get_str = get "enter" and suppose it as user input
*/

#include <iostream>
#include <fstream>
#include <cstdlib> // exit()
#include <cctype>
#include <string> 
#include <cstring>
#include <cstdint> // std::int16_t
#include <cstddef> // std::size_t
#include <iomanip> // std::setw() | std::setprecision() 

uint16_t show_menu();
inline std::string get_str(std::string category);
inline uint16_t get_int(std::string category);
inline uint16_t get_width(std::string inputData, std::string descriptionName);
void output(uint16_t state, std::string firstName, std::string lastName, uint16_t age, uint16_t termUntilRetirement, uint16_t annualSalary, std::string position);


int main()
{
    std::string first_name, last_name, position;
    uint16_t age{ 0 }, daily_wage{ 0 }, state{ 0 };

    std::cout << "Hello, user!\nWe are glad to see you in our app. Please, enter unswers to the following questions.\n";
    first_name = get_str("\"First name\"");
    last_name = get_str("\"Last name\"");
    age = get_int("\"Age\"");
    daily_wage = get_int("\"Daily wage\"");
    position = get_str("\"Position\"");
    
    uint16_t term_until_retirement = (age > 0 && age < 55) ? 55 - age : 0;
    uint16_t annual_salary = (int)(daily_wage * 250.0) * 0.8;

    output(show_menu(), first_name, last_name, age, term_until_retirement, annual_salary, position);

    return 0;
}

uint16_t show_menu()
{
    /*
    Funtion:    show menu and get choice for outputting profile data
    Get:        integer varieble from user
    Return:     int
    */
    std::cout <<
        "Menu (select output version - default console & file):\n"
        "1. Console output\n"
        "2. File output\n"
        "3. Default\n";
    uint16_t state = get_int("choice about output information");
    return state;
}

inline uint16_t get_width(std::string inputData, std::string descriptionName)
{
    /*
    inputData:          string of input user data  -> ex: Mikhail Nakonechnyi
    descriptionName:    string of description name -> ex: AnnualSalary
    21                  is max lenght of higher description name
    */
    uint16_t inputDataLength = inputData.length();
    uint16_t descriptionNameLength = descriptionName.length();
    return 21 - descriptionNameLength + inputDataLength;
}

void output(
    uint16_t state,
    std::string firstName, 
    std::string lastName, 
    uint16_t age, 
    uint16_t termUntilRetirement,
    uint16_t annualSalary,
    std::string position)
{
    /*
    Funtion:    transform all variebles to text format
    Get:        state: 1.Console, 2.File, 3.Default: console and file output data
    Get:        data variebles from user (string, string, int, int, float, string) 
    */
    std::ofstream file("profile.txt", std::ios::app & std::ios::trunc);
    if (!file)
    {
        std::cerr << "Uh oh, profile.txt could not be opened for writing!" << std::endl;
        exit(1);
    }
    std::string fullName = firstName + " " + lastName;
    uint16_t wName = get_width(fullName, "Name: ");
    uint16_t wAge = get_width(std::to_string(age), "Age: ");
    uint16_t wRetiree = get_width(std::to_string(termUntilRetirement), "TermUntilRetirement: ");
    uint16_t wSalary = get_width(std::to_string(annualSalary), "AnnualSalary: ");
    uint16_t wPosition = get_width(position, "Position: ");

    switch (state)
    {
    case 1:
        std::cout << std::noshowpoint;
        std::cout.fill(' ');
        std::cout << "User Data Profile:\n"
            << "Name: " << std::setw(wName)  << fullName << std::endl
            << "Age: " << std::right << std::setw(wAge) << age << std::endl
            << "TermUntilRetirement: " << std::right << std::setw(wRetiree) << termUntilRetirement << std::endl
            << "AnnualSalary: " << std::right << std::setw(wSalary) << annualSalary << std::endl
            << "Position: " << std::right << std::setw(wPosition) << position << std::endl;
        break;
    case 2:
        file << std::noshowpoint;
        file.fill(' ');
        file << "User Data Profile:\n"
            << "Name: " << std::setw(wName) << fullName << std::endl
            << "Age: " << std::right << std::setw(wAge) << age << std::endl
            << "TermUntilRetirement: " << std::right << std::setw(wRetiree) << termUntilRetirement << std::endl
            << "AnnualSalary: " << std::right << std::setw(wSalary) << annualSalary << std::endl
            << "Position: " << std::right << std::setw(wPosition) << position << std::endl;
        break;
    default:
        std::cout << std::noshowpoint;
        std::cout.fill(' ');
        std::cout << "User Data Profile:\n"
            << "Name: " << std::setw(wName) << fullName << std::endl
            << "Age: " << std::right << std::setw(wAge) << age << std::endl
            << "TermUntilRetirement: " << std::right << std::setw(wRetiree) << termUntilRetirement << std::endl
            << "AnnualSalary: " << std::right << std::setw(wSalary) << annualSalary << std::endl
            << "Position: " << std::right << std::setw(wPosition) << position << std::endl;
        // ===============================================================
        file << std::noshowpoint;
        file.fill(' ');
        file << "User Data Profile:\n"
            << "Name: " << std::setw(wName) << fullName << std::endl
            << "Age: " << std::right << std::setw(wAge) << age << std::endl
            << "TermUntilRetirement: " << std::right << std::setw(wRetiree) << termUntilRetirement << std::endl
            << "AnnualSalary: " << std::right << std::setw(wSalary) << annualSalary << std::endl
            << "Position: " << std::right << std::setw(wPosition) << position << std::endl;
        break;
    }
}

inline uint16_t get_int(std::string category)
{
    /*
    Funtion:    print category and check inputting varieble for correct data
    Get:        integer varieble from user 
    Return:     int
    */
    uint16_t number{0};
    while (true)
    {
        std::cout << "Enter your " << category << ": ";
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

inline std::string get_str(std::string category)
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