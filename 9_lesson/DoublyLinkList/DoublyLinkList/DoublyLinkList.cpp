// DoublyLinkList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

struct Node {
    Node* next{ nullptr };
    Node* prev{ nullptr };
    int data{ 0 };
};

struct List {
    Node* head{ nullptr };
    Node* tail{ nullptr };
    int size{ 0 };
};

List g_list;

void AddNote(int data) {
    Node* node = new Node;

    if (!g_list.head) {
        g_list.head = node;
    }
    else {
        g_list.tail->next = node;
        node->prev = g_list.tail;
    }
    g_list.tail = node;
    g_list.size += 1;
    node->data = data;
}


int main() {
    AddNote(1);
    AddNote(2);
    AddNote(3);

    for (const Node* curNode = g_list.head; curNode != nullptr; curNode = curNode->next) {
        std::cout << "node data = " << curNode->data << std::endl;
    }

    return 0;
}
