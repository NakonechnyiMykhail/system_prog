// hw8.cpp :    Doubly Link list with functions.
// author:      Nakonechnyi Mikhail
// date:        04.07.20
// version:     1.0
//// description of homework task:
//Реализовать двухсвязный список
//struct Node {
//    Node* next;
//    Node* prev;
//    int data;
//}
//struct List {
//    Node* head;
//    int size;
//}
//И функции :
//void AddNode(int data) - добавляет в конец списка элемент в конец
//void DeleteNode(const Node * node) - удаляет элемент списка
//void ShowList() - выводит все элементы в списке через запятую
//Задания со звездочкой :
//const Node * FindNode(int data)
//void AddNodeAfter(const Node * node, int data)

#include <iostream>

struct Node {
    Node* next{ nullptr };
    Node* prev{ nullptr };
    int data{ 0 };
};
struct List {
    Node* head{ nullptr };
    int size{ 0 };
};

int UpdateCountOfNodes(List* l) {
    return ++(l->size);
}

void ShowList(const List* l) {
    const Node* node = l->head;
    std::cout << "\n\nSize of list: " << l->size << std::endl;
    while (node != NULL)
    {
        std::cout << "Data = " << node->data << std::endl;
        node = node->next;
    }
    //for (Node* curItem = l->head; curItem; curItem = curItem->next) {
    //    std::cout << "Size: " << l->size << "\t data = " << curItem->data << std::endl;
    //}
}

const Node* Search(Node* head, int value) {
    Node* ptr = head;
    while (ptr != NULL) {
        if (ptr->data == value) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return nullptr;
}

void AddNodeToStart(List* l, Node** head_ref, int new_data) {
    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = (*head_ref);
    new_node->prev = nullptr;

    if ((*head_ref) != nullptr) {
        (*head_ref)->prev = new_node;
    }

    (*head_ref) = new_node;
    l->size = UpdateCountOfNodes(l);

}

// add at the end
void AddNode(List* l, Node** head_ref, int new_data) {
    Node* new_node = new Node();
    Node* last = *head_ref; 

    new_node->data = new_data;
    new_node->next = nullptr;

    if (*head_ref == nullptr) {
        new_node->prev = nullptr;
        *head_ref = new_node;
        l->size = UpdateCountOfNodes(l);
        return;
    }

    while (last->next != nullptr) {
        last = last->next;
    }
    last->next = new_node;

    new_node->prev = last;
    l->size = UpdateCountOfNodes(l);
    return;
}

void InsertAfter(List* l, Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        std::cout << "the given previous node cannot be NULL\n";
        return;
    }

    Node* new_node = new Node();

    new_node->data = new_data;

    new_node->next = prev_node->next;

    prev_node->next = new_node;

    new_node->prev = prev_node;

    if (new_node->next != nullptr) {
        new_node->next->prev = new_node;
    }
    l->size = UpdateCountOfNodes(l);
}

void DeleteNode(List* l, Node** head_ref, Node* del) {
    if (*head_ref == nullptr || del == nullptr) {
        return;
    }
    if (*head_ref == del) {
        *head_ref = del->next;
    }
    if (del->next != nullptr) {
        del->next->prev = del->prev;
    }
    if (del->prev != nullptr) {
        del->prev->next = del->next;
    }
    //l->size = UpdateCountOfNodes(l);
    --(l->size);

    delete(del);
    return;
}

int main() {

    List* d_list = new List( { nullptr, 0 });
    int length{ 5 };
    AddNodeToStart(d_list, &(d_list->head), length);

    AddNode(d_list, &(d_list->head), 0); 
    AddNode(d_list, &(d_list->head), 4); 
    AddNode(d_list, &(d_list->head), 3); 
    AddNode(d_list, &(d_list->head), 2); 
    InsertAfter(d_list, (d_list->head->next), 3); // after 5 -> 0 -> 3 -> 4
    ShowList(d_list);

    DeleteNode(d_list, &(d_list->head), (d_list->head->next)); // make delete by data

    ShowList(d_list);
    int search_index = 7; // 0, 2, 4 ...
    std::cout << "Address of node with data = " << search_index << ":\t" << Search((d_list->head), search_index) << std::endl;

    delete d_list;

    return 0;
}
