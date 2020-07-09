#include "ListImpl.h"
#include <iostream>

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
}

void ShowList(const List* list) {
    for (const Node* curNode = list->head; curNode != nullptr; curNode = curNode->next) {
        std::cout << "node data = " << curNode->data << std::endl;
    }
}

void DeleteNode(const Node* node, List* list) {
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