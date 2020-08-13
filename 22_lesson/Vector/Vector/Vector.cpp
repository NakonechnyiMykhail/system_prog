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

/ 11.08.2020 /
добавить итератор к вашему вектору, если он готов. Если не готов, закончить вектор
*/

#include <iostream>
#include <iterator>
#include <vector>
#include <typeinfo>

template <typename DataType>
class Iterator 
{
public:
    Iterator(DataType* data) :
        m_data(data) 
    {
        m_size = sizeof(m_data) / sizeof(DataType);
    }

    Iterator& operator++() 
    {
        ++m_data;
        return *this;
    }

    DataType& operator*() 
    {
        return *m_data;
    }
    bool operator!=(const Iterator& it) 
    {
        return *(m_data) != *(it.m_data);
    }

private:
    int m_index{ 0 };
    int m_size{ 0 };
    DataType* m_data{ nullptr };
};

template <typename DataType>
class Vector
{
public:
    typedef Iterator<DataType> iterator;

    Vector() {}
    Vector(int length) :
        m_length(length), m_arr(new DataType [length])
    {
        try
        {
            if (
                typeid(DataType) == typeid(long double) or
                typeid(DataType) == typeid(double) or
                typeid(DataType) == typeid(float) or
                typeid(DataType) == typeid(long long) or
                typeid(DataType) == typeid(long) or
                typeid(DataType) == typeid(int) or
                typeid(DataType) == typeid(short)
                        )
            {
                /* Data types:
                    char	                1byte - 127 to 127 or 0 to 255
                    unsigned char	        1byte	0 to 255
                    signed char	            1byte - 127 to 127
                    int	                    4bytes - 2147483648 to 2147483647
                    unsigned int	        4bytes	0 to 4294967295
                    signed int	            4bytes - 2147483648 to 2147483647
                    short int	            2bytes - 32768 to 32767
                    unsigned short int	    2bytes	0 to 65, 535
                    signed short int	    2bytes - 32768 to 32767
                    long int	            8bytes - 2, 147, 483, 648 to 2, 147, 483, 647
                    signed long int     	8bytes	same as long int
                    unsigned long int	    8bytes	0 to 4, 294, 967, 295
                    long long int	        8bytes - (2 ^ 63) to(2 ^ 63) - 1
                    unsigned long long int	8bytes	0 to 18, 446, 744, 073, 709, 551, 615
                    float	                4bytes
                    double	                8bytes
                    long double
                 */
                for (size_t i = 0; i < m_length ; ++i)
                {
                    m_arr[i] = static_cast<DataType>(0);
                }
            }
            else if (typeid(DataType) == typeid(std::string)) // may delete this condition
            {
                //for (size_t i = 0; i < m_length; ++i)
                //{
                //    m_arr[i] = "";
                //}
            }

        }
        catch (const std::exception&)
        {
            // ...
        }
        catch (...)
        {
            std::cerr << "Smth went wrong with initialize of data!..." << std::endl;
        }
    }
    Vector(int length, DataType data) :
        m_length(length), m_arr(new DataType[length])
    {
        for (size_t i = 0; i < m_length; ++i)
        {
            m_arr[i] = data;
        }
    }

    void PushBack(const DataType& data)
    {
        try
        {
            if (m_length and m_arr)
            {
                DataType* tmp = new DataType[m_length + 1];

                for (size_t i = 0; i < m_length; i++)
                {
                    tmp[i] = m_arr[i];
                }
                tmp[m_length] = data;
                CleanVector();
                m_arr = tmp;
                ++m_length;
            }
            else
            {
                ++m_length;
                m_arr = new DataType[m_length];
                m_arr[0] = data;
            }
        }
        catch (const std::exception&)
        {
            // ...
        }
        catch (...)
        {
            std::cerr << "Smth went wrong with func:" << __func__ << "and added data: " << data << std::endl;
        }
    }

    int Length() const
    {
        return m_length;
    }

    iterator Begin() const 
    {
        return iterator(m_arr);
    }

    // !!!!!!!!!!!
    iterator End() const 
    {
        return iterator(&(*(m_arr + m_length))); // &(*(m_arr + m_length)) // &m_arr[m_length]
    }

    DataType& operator[](int index)
    {
        return *(m_arr + index);
    }

    ~Vector() 
    {
        //for (node* it = m_head; it; ) {
        //    node* nodeToDelete = it;
        //    it = it->next;
        //    delete nodeToDelete;
        //}
        delete[] m_arr;
    }
private:
    void CleanVector()
    {
        delete[] m_arr;
        m_arr = nullptr;
    }

private:

    int m_length{ 0 };
    DataType* m_arr{ nullptr };
};




int main()
{
    Vector<double> vec;
    Vector<int> vec2(10);
    Vector<double> vec3(20, 3.2);
    int length = 5;
    for (size_t i = 0; i < length; i++)
    {
        double val = powf(i * 1.5, 2);
        vec.PushBack(val);
    }

    std::cout << "Vector length: " << vec.Length() << std::endl;


    ////Vector<double>::display(vec.GetHead());

    for (size_t i = 0; i < vec.Length(); i++)
    {
        std::cout << "vec[" << i << "] = " << vec[i] << std::endl;
    }

    for (Vector<double>::iterator it = vec3.Begin(); it != vec3.End(); ++it) 
    //for (auto it = vec3.Begin(); it != vec3.End(); ++it) 
    {
        std::cout << *it << std::endl;
    }

    return 0;
}

