// hw7.cpp :    Single & Double link lists.
// author:      Nakonechnyi Mikhail
// date:        03.07.20
// version:     1.0
// description of homework task:
//Описать структуру Worker с полями имя, должность и зп. Создать 10 структур в цикле 
//через указатель на следующую структуру (как мы это сделали на занятии). 
//Зп заполнить используя rand функцию. В цикле пройтись и посчитать среднюю зп по компании"
//Усложнение задачи :
//связать структуры Worker через структуру Pointer
//struct Pointer {
//    Worker* next;
//    Worker* prev;
//}
// 
// future:
// add id - index and functions InsertAfter / InsertBefore
// add class and template versions

#include <iostream>
#include <fstream>
#include <cstdlib> // exit()
#include <cctype>
#include <string> 
#include <cstdint> // std::int16_t
#include <cstddef> // std::size_t
#include <iomanip> // std::setw() | std::setprecision() 
#include <random>
#include <ctime>

// list
struct Worker {
    std::string name;
    std::string position;
    int salary{ 0 };
    Worker* next{ nullptr };
};

// list 2
struct Worker2 {
    std::string name;
    std::string position;
    int salary{ 0 };
    Worker2* next{ nullptr };
    Worker2* prev{ nullptr };
};




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

int PrintMenu() {
    std::cout <<
        "\n1. Single link list"
        "\n2. Double link list"
        "\n3.(-) Class for linked list"
        "\n4.(-) Class template"
        "\n5.(-) Stack"
        "\n6. Exit";
    return GetInteger("choice");
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
        std::cout << "Enter " << category << ": ";
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

int Random(int from, int to, int step) {
    int temp = from + std::rand() % (to - from + step);
    while ((temp % step) != 0) {
        temp = from + std::rand() % (to - from + step);
    }
    return temp;
}
// ============= version 2 (hard) ===================
double AvarangeSalary2(Worker2* worker) {
    double sum{ 0.0 };
    int count{ 0 };
    Worker2* currentWorker = worker;
    while (currentWorker != nullptr) {
        sum += currentWorker->salary;
        currentWorker = currentWorker->next;
        count++;
    }

    return sum / static_cast<double>(count);
}

void PushStart2(Worker2** worker, std::string name, std::string position, int salary) {
    // 1. allocate stucture
    Worker2* new_worker = new Worker2;// ({ name, position, salary, new Worker2, nullptr });
    // 2. put in the data
    new_worker->name = name;
    new_worker->position = position;
    new_worker->salary = salary;
    // 3. Make next of new node as head and previous as NULL
    new_worker->next = (*worker);
    new_worker->prev = nullptr;
    // 4. change prev of head node to new node
    if ((*worker) != nullptr) {
        (*worker)->prev = new_worker;
    }
    // 5. move the head to point to the new node
    (*worker) = new_worker;

}

void Append2(Worker2** worker, std::string name, std::string position, int salary)
{
    /* 1. allocate node */
    Worker2* new_worker = new Worker2;
    Worker2* last = *worker; /* used in step 5*/

    /* 2. put in the data  */
    new_worker->name = name;
    new_worker->position = position;
    new_worker->salary = salary;

    /* 3. This new node is going to be the last node, so
          make next of it as NULL*/
    new_worker->next = nullptr;

    /* 4. If the Linked List is empty, then make the new
          node as head */
    if (*worker == nullptr) {
        new_worker->prev = nullptr;
        *worker = new_worker;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != nullptr)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_worker;

    /* 7. Make last node as previous of new node */
    new_worker->prev = last;

    return;
}

void PrintWorkers2(Worker2* worker, int mode) {
    std::cout << "\nID\tName\tPosition\tSalary\n";
    int count{ 0 };
    switch (mode)
    {
    case 1: // forward direction
    {
        Worker2* last = worker;

        while (worker != nullptr) {
            std::cout << ++count  << "\t" << worker->name << "\t" <<
                worker->position << "\t\t" << worker->salary << std::endl;
            last = worker;
            worker = worker->next;
        }
        break;
    }
    case 2: // reverse direction
    {
        Worker2* last = worker;
        while (last != nullptr) {
            std::cout << ++count << "\t" << last->name << "\t" <<
                last->position << "\t\t" << last->salary << std::endl;
            last = last->prev;
        }
        break;
    }
    default:
        Worker2* currentWorker = worker;
        do {
            std::cout << ++count << "\t" << currentWorker->name << "\t" <<
                currentWorker->position << "\t\t" << currentWorker->salary << std::endl;
            currentWorker = currentWorker->next;
        } while (currentWorker != nullptr);
        break;
    }
}

// ============= version 1 (easy) ===================
double AvarangeSalary(Worker* worker) {
    double sum{ 0.0 };
    int count{ 0 };
    Worker* currentWorker = worker;
    while (currentWorker != NULL) {
        sum += currentWorker->salary;
        currentWorker = currentWorker->next;
        count++;
    }

    return sum / static_cast<double>(count);
}

void PushStart(Worker** worker, std::string name, std::string position, int salary) {
    Worker* new_worker;
    new_worker = new Worker;// ({ name, position, salary });

    new_worker->name = name;
    new_worker->position = position;
    new_worker->salary = salary;
    new_worker->next = (*worker);
    (*worker) = new_worker;
}

void Append(Worker* worker, std::string name, std::string position, int salary) {
    Worker* current = worker;
    while (current->next != 0) {
        current = current->next;
    }
    current->next = new Worker({ name, position, salary });
    //current->name = name;
    //current->position = position;
    //current->salary = salary;
    current->next->next = 0;
}

void PrintWorkers(Worker* worker) {
    Worker* currentWorker = worker;
    std::cout << "\nID\tName\tPosition\tSalary\n";
    int count{ 0 };
    while (currentWorker != nullptr) {
        std::cout << ++count << "\t"<< currentWorker->name << "\t" << 
            currentWorker->position << "\t\t" << currentWorker->salary << std::endl;
        currentWorker = currentWorker->next;
    }
}


int main()
{
    // randomize std::rand() ================================================
    //srand(time(NULL));        // v1
    //srand((unsigned)time(0)); // v2

    // v3 c++11 style
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(2000, 5000); // distribution in range [1, 6]

    //for (size_t i = 0; i < 20; i++)
    //{
    //    std::cout << dist(rng) << std::endl;
    //}

    //for (size_t i = 0; i < 10; i++)
    //{
    //    std::cout << Random(1000, 5000, 100) << std::endl;
    //}
    // =======================================================================

    std::string name, position;
    int salary{ 0 }, switch_on{ 1 };

    do {
        switch_on = PrintMenu();
        if (switch_on == 6) {
            return 0;
        }
        name = GetString("name " + std::to_string(1));
        position = GetString(name + " position");
        salary = (switch_on == 1) ? dist(rng) : Random(2000, 5000, 100);

        switch (switch_on) {
        case 1: { //version 1 (easy)
            Worker* workers = nullptr; // new Worker({ name, position, salary });
            PushStart(&workers, name, position, salary);
            if (workers == nullptr) {
                return 1;
            }
            for (size_t i = 1; i < 2; i++) {
                name = GetString("name " + std::to_string(i + 1));
                position = GetString(name + " position");
                salary = dist(rng);
                Append(workers, name, position, salary);
            }
            // ========== to first element ==============
            std::cout << "Enter worker to first element of list\n";
            name = GetString("name " + std::to_string(0));
            position = GetString(name + " position");
            salary = dist(rng);
            PushStart(&workers, name, position, salary);
            // ========== first end =====================
            PrintWorkers(workers);
            std::cout << "Avarage salary of company: " << AvarangeSalary(workers) << std::endl;
            delete workers;
            break;
        }
        case 2: { // version 2 (hard)
            Worker2* workers2 = nullptr;// = new Worker2({ name, position, salary, new Worker2, nullptr });
            PushStart2(&workers2, name, position, salary);
            if (workers2 == nullptr) {
                return 1;
            }
            for (size_t i = 1; i < 2; i++) { // <-- 9
                name = GetString("name " + std::to_string(i + 1));
                position = GetString(name + " position");
                salary = Random(2000, 5000, 100); // per 500
                Append2(&workers2, name, position, salary);
            }
            // ========== to first element ==============
            std::cout << "Enter worker to first element of list\n";
            name = GetString("name " + std::to_string(0));
            position = GetString(name + " position");
            salary = Random(2000, 5000, 100);
            PushStart2(&workers2, name, position, salary);
            // ========== end first element ==============
            PrintWorkers2(workers2, 1); // mode = 1 forward
            std::cout << "Avarage salary of company: " << AvarangeSalary2(workers2) << std::endl;
            delete workers2;
            break;
        }
        case 3:// version 3
            break;
        case 4:// version 4
            break;
        case 5:// version 5
            break;
        default:
            std::cout << "Try again!" << std::endl;
            break;
        }
    } while (switch_on != 6);


    return 0;
}
