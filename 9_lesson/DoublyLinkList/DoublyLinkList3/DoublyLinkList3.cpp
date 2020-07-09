// DoublyLinkList3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "ListImpl.h"

int main() {

    List* list = new List; // sizeof(list) malloc(12)
    AddNote(1, list);
    AddNote(2, list);
    AddNote(3, list);
    ShowList(list);
    DeleteNode(list->head->next, list);
    std::cout << "After delete:\n";
    ShowList(list);


    return 0;
}

// compile DoublyLinkList3.cpp                  -> DoublyLinkList3.obj (UNIX .o)
// compile ListImpl.cpp                         -> ListImpl.obj 
// compile DoublyLinkList3.obj ListImpl.obj     -> DoublyLinkList3.exe (UNIX a.out )