#pragma once

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

void AddNote(int data, List* list);
void ShowList(const List* list);
void DeleteNode(const Node* node, List* list);