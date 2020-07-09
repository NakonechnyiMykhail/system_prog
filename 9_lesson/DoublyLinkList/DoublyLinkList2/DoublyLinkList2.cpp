// DoublyLinkList2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node {
    Node* next{ nullptr };
    Node* prev{ nullptr };
    int data{ 0 };
};

struct List {
    Node* head{ nullptr };  // 4
    Node* tail{ nullptr };  // 4
    int size{ 0 };          // 4
};


void AddNote(int data, List* list) {
    Node* node = new Node;

    if (!list->head) {
        list->head = node;
    }
    else {
        list->tail->next = node;
        node->prev = list->tail;
    }
    list->tail = node;
    list->size += 1;
    node->data = data;

    //delete node; !!!! DON'T DO THIS (only for delete function)
    // "delete" can delete only elements from HEAP not from STACK
    // STACK is for LOCAL vars
    // HEAP is for DYNAMIC vars
}

void ShowList(const List* list) {
    for (const Node* curNode = list->head; curNode != nullptr; curNode = curNode->next) {
        std::cout << "node data = " << curNode->data << std::endl;
    }
}

void DeleteNode(const Node* node, List* list) {
    // N1 <=> N2 <=> N3
    // if N2:
    // N1     <=>    N3
    for (const Node* curNode = list->head; curNode != nullptr; curNode = curNode->next) {
        if (curNode == node) {
            // realize at home for FIRST and LAST node element and for ONLY ONE element
            //if (!curNode->prev) {
            //    curNode->prev->next = curNode->next;
            //}
            //else if (!curNode->next) {
            //    curNode->next->prev = curNode->prev;

            //}
            //else {
                curNode->prev->next = curNode->next;
                curNode->next->prev = curNode->prev;
            //}

            delete curNode;
            break;
        }
        list->size -= 1;
    }
}
// macroses
// https://tproger.ru/translations/c-macro/
#define INT int

#define SQRT(x) (x*x)

int main() {

    INT i = 0;
    std::cout << __LINE__ << " " << __LINE__ << std::endl;
    std::cout << SQRT(5) << std::endl;
    //List* list = new List; // sizeof(list) malloc(12)
    //AddNote(1, list);
    //AddNote(2, list);
    //AddNote(3, list);
    //ShowList(list);
    //DeleteNode(list->head->next, list);
    //delete list; // delete 12 byte of list but not delete NODES
    //// leak of memory heap

    List list;


    AddNote(1, &list);
    AddNote(2, &list);
    AddNote(3, &list);

    ShowList(&list);
    DeleteNode(list.head->next, &list);
    std::cout << "After delete:\n";
    ShowList(&list);

    //for (const Node* curNode = list.head; curNode != nullptr; curNode = curNode->next) {
    //    std::cout << "node data = " << curNode->data << std::endl;
    //}
    //was error memory 0xDDDDDDDD - we try to see at deleted memory

    return 0;
}
