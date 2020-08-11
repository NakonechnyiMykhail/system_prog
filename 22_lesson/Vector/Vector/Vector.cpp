// Vector.cpp : Vector template.
// author:      Nakonechnyi Mikhail
// date:        11.08.20
// version:     1.0
// description of homework task:
/*
Реализовать шаблонный класс Vector, задача минимум:
реализовать функцию PushBack и оператор квадратные скобки.
PushBack - добавляет элемент в конец вектора, а квадратные скобки возвращают ссылку на элемент указанный в параметре.

Vector внутри хранит непрерывный массив элементов.
*/

#include <iostream>

template <typename DataType>
class Vector
{
public:
    Vector() {}
    ~Vector()
    {
        delete m_head;
        delete m_tail;
    }

    struct Node
    {
        Node* next{ nullptr };
        DataType data;
        int count{ 0 };
    };

    void PushBack(const DataType& data)
    {
        Node* newNode = new Node;

        newNode->data = data;
        newNode->count = m_count;
        newNode->next = nullptr;

        //std::cout << "data = " << data << std::endl;

        if (m_head == nullptr) {
            m_head = newNode;
            m_tail = m_head;
            ++m_count;
            return;
        }
        else
        {
            m_tail->next = newNode;
            m_tail = m_tail->next;
        }

        ++m_count;
        return;
    }

    int Length() const
    {
        return m_count;
    }

    const DataType& operator[](int count)
    {
        for (Node* currNode = m_head; currNode; currNode = currNode->next)
        {
            //std::cout << "count:" << currNode->count << "\tdata: " << currNode->data << std::endl;
            if (currNode->count == count)
            {
                return currNode->data;
            }
        }
    }

    Node* GetHead() const
    {
        return m_head;
    }

    static void display(Node* head)
    {
        if (head == NULL)
        {
            std::cout << "NULL" << std::endl;
        }
        else
        {
            std::cout << head->data << std::endl;
            display(head->next);
        }
    }
private:
    int m_count{ 0 };
    Node* m_head{ nullptr };
    Node* m_tail{ nullptr };
};


int main()
{
    Vector<double> vec;
    int length = 5;
    for (size_t i = 0; i < length; i++)
    {
        vec.PushBack(powf(i * 1.5, 2));
    }

    std::cout << "Vector length: " << vec.Length() << std::endl;


    //Vector<double>::display(vec.GetHead());

    for (size_t i = 0; i < vec.Length(); i++)
    {
        std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
    }

    return 0;
}

