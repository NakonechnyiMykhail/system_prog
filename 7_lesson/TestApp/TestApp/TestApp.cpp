// TestApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//void
int* f() {
    int x1 = 2;
    int y1 = 2;
    return &x1;
}

void f2() {
    //int a = 2;
}

int main()
{
    // STUCTURES

    //struct Coordinate {
    //    int x { 0 };
    //    int y { 0 };
    //};

    //struct Line {
    //    Coordinate first;
    //    Coordinate second;
    //};
    //struct Coor {
    //    Line dat;
    //    int x{ 0 };
    //    char y{ 0 };
    //    std::string str;
    //};
    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //struct Co {
    //    char x;
    //    int y;
    //    //char y;
    //    //char z;
    //    //char a;
    //    //char b;
    //    //char c;
    //};
    //struct C {
    //    char x;
    //    //char padding[3]; // packaging directives
    //    // pragma push/pack
    //    // https://docs.microsoft.com/ru-ru/cpp/preprocessor/pack?view=vs-2019
    //    int y;
    //};


    //std::cout << sizeof(Co) << std::endl;
    //Coordinate first { 3, 4 };
    //Coordinate second{ 1, 1 };
    //Coordinate third; // {0,0}

    //first.x = 4;
    //std::cout << "x = " << first.x << " y = " << first.y;

    ////data in file (as we know)
    //// 01 02 00 00 00
    //// 01           -> char
    //// 02 00 00 00  -> int

    //char arr[] = { 01, 02, 00, 00, 00 };

    //// char x => 01, 02, 00, 00
    //// int  y => 00 cc cc cc (garbage)
    //C* one = reinterpret_cast<C*>(arr);


    //Line line;
    //Line line1;
    //Line line2 = { {1,2}, {3,4} };
    //Line line3 { {}, {} };
    //line.first.x = 1;
    //line.second.x = 1;
    //line.first.y = 1;
    //line.second.y = 1;

    //line1.first = { 1,2 };
    //line1.second = { 1,2 };

    ////f();
    ////int a = f();
    //int* b = f();

    //// undefiened behavior
    //f2();                               // clear STACK variebles
    ////std::cout << *f() << std::endl;
    //std::cout << *b << std::endl;       // Not-VALID data
    //std::cout << *f() << std::endl;


    /*
    Memory

    Stack           - fast memory
    Heap (kucha)    - slow memory < than stack ~ 1000 times
    */
    //int x[10]{};
    //x[1] = 10;

    struct Worker {
        std::string name;
        Worker* next = 0;
    };
    //Worker y[500]{};

    // !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //// malloc -> cstdlib
    //int* i = (int*) malloc(sizeof(int)); // C-cast
    //int* a = static_cast<int*>(malloc(sizeof(int))); // BETTER than C-cast
    //int* a2 = static_cast<int*>(malloc(sizeof(int)*20)); // 20*4 bytes
    //int* a3 = static_cast<int*>(malloc(1000)); // 1000 bytes
    //*a = 100;

    //int t = 10;
    //t = 20; // OK - local varieble
    //
    //// memory leak
    //i = static_cast<int*>(malloc(1000));

    //std::cout << *a << std::endl;
    //
    //free(i);
    //free(a);
    //free(a2);
    //free(a3);

    //int* c = new int;
    //*c = 10;

    //// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //// new return pointer to Worker
    //// malloc return pointer to void
    //Worker* worker = new Worker; // sizeof(Worker)
    //
    //// set or get varieble
    //(*worker).name = "Anton";
    //// OR
    //worker->name = "Mike";

    //delete worker;
    //{// memory leak
    //    Worker* work2 = new Worker;
    //    work2->name = "Mike";
    //}
    //delete work2; // ERROR - No access to this varieble work2

    Worker* worker1 = new Worker({ "worker1" });
    Worker* worker2 = new Worker({ "worker2" });
    Worker* worker3 = new Worker({ "worker3" });
    worker1->next = worker2;
    worker2->next = worker3;
    

    for (Worker* curWorker = worker1; curWorker != 0; curWorker = curWorker->next)
    {
        std::cout << curWorker->name << std::endl;
    }

/*
OUR BOARD - Chess path for Knight

* X * X *
X * * * X
* * K * *
X * * * X
* X * X *

    int x1 = 3;
    int y1 = 4;
    int x2 = 1;
    int y2 = 1;
    const int fieldMaxX = 7;
    const int fieldMaxY = 7;
    if (x1 > fieldMaxX || x2 > fieldMaxX || y1 > fieldMaxY || y2 > fieldMaxY) {
        // ...
        return -1;
    }
    if ((abs(x1 - x2) == 2 && abs(y1 - y2) == 1) ||
        (abs(x1 - x2) == 1 && abs(y1 - y2) == 2)) {
        // ...
        return true;
    } 
    return false;
*/

    return 0;
}
