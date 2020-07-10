// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//struct Worker {
//    // all fields and methods are PUBLIC (default)
//    Worker(std::string firstname, std::string secondname, std::string position)
//    {
//        m_firstname = firstname;
//        m_secondname = secondname;
//        m_position = position;
//    }
//    std::string GetFullName() {
//        return m_firstname + " " + m_secondname;
//    }
//private:
//    std::string m_firstname;
//    std::string m_secondname;
//    std::string m_position;
//};

//std::string GetWorkerFullName(const Worker* worker) {
//    return worker->firstname + " " + worker->secondname;
//}


//struct Point {
//    int x;
//    int y;
//};

class Worker {
    // all fields and methods are PRIVATE (default)
    // good rules:
    //      public -> protected -> private (in the end)
    //      don't public members
public:
    Worker()
    {
    }

    Worker(std::string firstname, std::string secondname, std::string position)
    {
        m_firstname = firstname;
        m_secondname = secondname;
        m_position = position;
    }
    std::string GetFullName() {
        return m_firstname + " " + m_secondname;
    }
    std::string GetFirstName() {
        return m_firstname;
    }
    void SetFirstName(std::string name) {
        m_firstname = name;
    }
    //std::string m_firstname;
private:
    Worker(std::string firstname, std::string secondname)
    {
        m_firstname = firstname;
        m_secondname = secondname;
    }
private:
    std::string m_firstname;
    std::string m_secondname;
    std::string m_position;
};





int main()
{
    // structures
    ////Worker worker;
    ////std::cout << "full name = " << worker.firstname << " " << worker.secondname << std::endl;
    ////std::cout << "full name = " << GetWorkerFullName(&worker) << std::endl;

    //Worker worker = {"Mike", "Nikon", "Dev"};
    ////worker.firstname = "Ivan"; // PROTECT THIS
    //std::cout << "full name = " << worker.GetFullName() << std::endl;


    // classes
    Worker worker("Mike", "Nikon", "Dev");
    Worker worker1;
    //Worker worker2("Mike", "Niko2");    // if private CAN'T DO this
    std::cout << "full name = " << worker.GetFullName() << std::endl;
    std::cout << "full name = " << worker1.GetFullName() << std::endl;
    //std::cout << "full name = " << worker2.GetFullName() << std::endl;



    return 0;
}

