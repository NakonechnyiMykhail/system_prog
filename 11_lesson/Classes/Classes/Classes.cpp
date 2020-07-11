// Classes.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Worker.h"
#include "Developer.h"

void ShowDevInfo(Developer& dev) { 
    std::cout << "full name = " << dev.GetFullName() << std::endl;
}

void ShowWorkerInfo1(Worker worker) { // full copy of Class
    // copy by new for each member of class
    std::cout << "full name = " << worker.GetFullName() << std::endl;
}

void ShowWorkerInfo2(Worker* worker) { // copy pointer for class
    // Worker* copy_worker = worker;
    std::cout << "full name = " << worker->GetFullName() << std::endl;
}
void ShowWorkerInfo3(Worker& worker) { // copy link for class
    // Worker* copy_worker = worker;
    std::cout << "full name = " << worker.GetFullName() << std::endl;
}
int Add(int a,  int b) { // send argument by copy
    //int a = a;
    //int b = b;
    return a + b;
}
//char Add(int a, int b) { // ERROR
//    return a + b;
//}
//char Add(const int& a, int b) { // ERROR
//    return a + b;
//}
char Add(char a, char b) {
    return a + b;
}
void Add(int a, int b, int& res) { // send argument by link
    //int a = a;
    //int b = b;
    res = a + b;
}
void Add(const double& a, const double& b, double& res) { // send argument by link
    //int& a = a;
    //int& b = b;
    res = a + b;
}
int main()
{
    //int a = 10;
    //int b = 20;
    //char a1 = 10;
    //char a2 = 10;
    //
    //int res = Add(a, b);
    //int res2{ 0 };
    //Add(a, b, res);

    //char res3 = Add(a, b);


    // ===================================
    //Worker worker("Mike", "Nikon", "Dev");
    //Worker worker1;
    ////Worker worker2("Mike", "Niko2");    // if private CAN'T DO this
    //std::string vlad = "Vlad";
    //worker.SetFirstName("Ivan"); // const char*
    //worker.SetFirstName(vlad); // string
    //ShowWorkerInfo1(worker);
    //ShowWorkerInfo2(&worker);
    //ShowWorkerInfo3(worker);
    //ShowWorkerInfo3(worker1);

    // ===================================
    Developer dev;
    dev.SetFirstName("Ivan");
    //dev.m_firstname = "iva";
    std::cout << dev.GetFirstName() << std::endl;
    ShowDevInfo(dev);
    std::cout << "Salary = " << dev.GetSalary() << std::endl;

    return 0;
}