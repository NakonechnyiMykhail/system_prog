// hw2.cpp:     User Profile
// author:      Nakonechnyi Mikhail
// date:        20.06.20
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

#include <iostream>
#include <fstream>
#include <cstdlib> // exit()
#include <cctype>
#include <string> 
#include <cstring>
#include <cstdint> // std::int16_t
#include <cstddef> // std::size_t
#include <iomanip> // std::setw() | std::setprecision() 

inline std::string get_str(std::string category);
inline int get_int(std::string category);
void output(int state, std::string firstName, std::string lastName, int age, int termUntilRetirement, double annualSalary, std::string position);
    
int main()
{
    std::string first_name{ "" }, last_name{ "" }, position{ "" };
    std::uint16_t age{0}, daily_wage{ 0 };

    // v1 ===========================================================================
    
    //std::cout << "Hello, user!\n We are glad to see you in our app. Please, enter unswers to the following questions.\n"
    //    "Enter your \"First name\": ";
    //std::cin >> first_name;
    //std::cout << "Enter your \"Last name\": ";
    //std::cin >> last_name;
    //std::cout << "Enter your \"Age\": ";
    //std::cin >> age;
    //std::cout << "Enter your \"Daily wage\": ";
    //std::cin >> daily_wage;
    //std::cout << "Enter your \"Position\" at the company: ";
    //std::cin >> position;

    //if (age <= 0 )
    //{
    //    std::cerr << "Oops, you entered an invalid age!" << std::endl;
    //    exit(1);
    //} 

    //int term_until_retirement = 55 - age;
    //float annual_salary = (daily_wage * 250) * 0.8;

    //file << "User Data Profile:\n"
    // << "Name: " << first_name << " " << last_name << std::endl
    // << "Age: " << age << std::endl
    // << "TermUntilRetirement: " << term_until_retirement << std::endl
    // << "AnnualSalary: " << annual_salary << std::endl
    // << "Position: " << position << std::endl;

    //std::cout << "User Data Profile:\n"
    // << "Name: " << first_name << " " << last_name << std::endl
    // << "Age: " << age << std::endl
    // << "TermUntilRetirement: " << term_until_retirement << std::endl
    // << "AnnualSalary: " << annual_salary << std::endl
    // << "Position: " << position << std::endl;

    // v2 ===========================================================================
    std::cout << "Hello, user!\nWe are glad to see you in our app. Please, enter unswers to the following questions.\n";
    first_name = get_str("\"First name\"");
    last_name = get_str("\"Last name\"");

    // BUG: if I use following line in the end - I cann't enter "Position" 
    position = get_str("\"Position\"");
    age = get_int("\"Age\"");
    daily_wage = get_int("\"Daily wage\"");
    

    int term_until_retirement = 55 - age;
    
    // Warning	C26451	Arithmetic overflow : 
    // Using operator '*' on a 4 byte value and then casting the result to a 8 byte value.Cast the value to the wider type before calling operator '*' to avoid overflow(io.2).hw
    // NEED: all int numbers write down with point as float/double
    double annual_salary = (daily_wage * 250.0) * 0.8;
    std::uint8_t state = 0;
    std::cout << 
        "Menu (select output version - default console & file):\n"
        "1. Console output\n"
        "2. File output\n";
    state = get_int("choise about output information");

    output(state, first_name, last_name, age, term_until_retirement, annual_salary, position);

    return 0;
}

void output(
    int state,
    std::string firstName, 
    std::string lastName, 
    int age, 
    int termUntilRetirement, 
    double annualSalary, 
    std::string position)
{
    /*
    Funtion:    transform all variebles to text format
    Get:        state: 1.Console, 2.File, Default: console and file output data
    Get:        data variebles from user (string, string, int, int, float, string) 
    */
    std::ofstream file("profile.txt", std::ios::app & std::ios::trunc);
    if (!file)
    {
        std::cerr << "Uh oh, profile.txt could not be opened for writing!" << std::endl;
        exit(1);
    }

    switch (state)
    {
    case 1:
        std::cout << std::noshowpoint;
        std::cout.fill(' ');
        std::cout << "User Data Profile:\n"
         << "Name: " << std::setw(22) << firstName << " " << lastName << std::endl
         << "Age: " << std::setw(18) << age << std::endl
         << "TermUntilRetirement: " << std::setw(2) << termUntilRetirement << std::endl
         << "AnnualSalary: " << std::setw(11) << annualSalary << std::endl
         << "Position: " << std::setw(17) << position << std::endl;
        break;
    case 2:
        file << std::noshowpoint;
        file.fill(' ');
        file << "User Data Profile:\n"
            << "Name: " << std::setw(22) << std::left << firstName << " " << lastName << std::endl
            << "Age: " << std::setw(18) << std::left << age << std::endl
            << "TermUntilRetirement: " << std::setw(2) << std::left << termUntilRetirement << std::endl
            << "AnnualSalary: " << std::setw(11) << std::left << annualSalary << std::endl
            << "Position: " << std::setw(17) << std::left << position << std::endl;
        break;
    default:
        std::cout << std::noshowpoint;
        std::cout.fill(' ');
        std::cout << "User Data Profile:\n"
            << "Name: " << std::setw(22) << firstName << " " << lastName << std::endl
            << "Age: " << std::setw(18) << age << std::endl
            << "TermUntilRetirement: " << std::setw(2) << termUntilRetirement << std::endl
            << "AnnualSalary: " << std::setw(11) << annualSalary << std::endl
            << "Position: " << std::setw(17) << position << std::endl;
        // ===============================================================
        file << std::noshowpoint;
        file.fill(' ');
        file << "User Data Profile:\n"
            << "Name: " << std::setw(22) << firstName << " " << lastName << std::endl
            << "Age: " << std::setw(18) << age << std::endl
            << "TermUntilRetirement: " << std::setw(2) << termUntilRetirement << std::endl
            << "AnnualSalary: " << std::setw(11) << annualSalary << std::endl
            << "Position: " << std::setw(17) << position << std::endl;
        break;
    }

    // old vertion with returning string
    //std::string str = "User Data Profile:\n"
    //    "Name: " + firstName + " " + lastName + "\n"
    //    "Age: " + std::to_string(age) + "\n"
    //    "TermUntilRetirement: " + std::to_string(termUntilRetirement) + "\n"
    //    "AnnualSalary: " + std::to_string(annualSalary) + "\n"
    //    "Position: " + position + "\n";
}

inline int get_int(std::string category)
{
    /*
    Funtion:    print category and check inputting varieble for correct data
    Get:        integer varieble from user 
    Return:     int
    */
    int number{0};
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
    std::string str{""};
    while (true)
    {
        std::cout << "Enter your " << category << ": ";
        std::getline(std::cin, str); // get all line

        bool bRejected = false;

        // checking each character at the entered word
        //unsigned int
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
        if (!bRejected) { break; }
    }
    return str;
}