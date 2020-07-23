// Operators.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <cassert>      // для assert()
//#include <cstdlib>     /* srand, rand */
#include <random>
#include <ctime>       /* time */

class ByteArray 
{ // sizeof(ByteArray) = 8
public:
    ByteArray(){}
    ByteArray(int size) :
        m_buff(new uint8_t[size]),
        m_size(size)
    {
        //m_buff = new uint8_t[size];
        Random();
    }

    // copy construct by default 
    ByteArray(const ByteArray& arr)
        //m_buff(arr.m_buff), // address in new obj will be to old obj, and if we clear memory for 1obj-> crash system
    {
        Clone(arr);
    }
    
    ByteArray& operator=(const ByteArray& arr)
    {
        //delete[] m_buff;
        Clear();
        Clone(arr);
        return *this;
    }
    bool operator!()
    {
        return !m_size;
    }

    // concat
    ByteArray& operator+(const ByteArray& arr)
    {
        uint8_t* tmpBuff = m_buff;
        m_buff = new uint8_t[m_size + arr.m_size];
        for (size_t i = 0; i < m_size; ++i)
        {
            m_buff[i] = tmpBuff[i];
        }

        for (size_t i = 0; i < arr.m_size; ++i)
        {
            m_buff[m_size + i] = arr.m_buff[i];
        }

        //for (size_t i = m_size, j = 0; i < m_size + arr.m_size; ++i, ++j)
        //{
        //    m_buff[i] = arr.m_buff[j];
        //}

        delete[] tmpBuff;
        m_size += arr.m_size;
        return *this;
    }

    bool operator==(const ByteArray& arr)
    {
        return std::equal(m_buff, m_buff + m_size, arr.m_buff, arr.m_buff + arr.m_size);
    }
    bool IsEqual(const ByteArray& arr)
    {
        return std::equal(m_buff, m_buff + m_size, arr.m_buff, arr.m_buff + arr.m_size);
    }

    uint8_t& operator[](int index)
    {
        assert(index >= 0 && index <= m_size);
        return m_buff[index];
    }


    ~ByteArray()
    {
        Clear();
        //delete[] m_buff;
        //m_buff = nullptr;
        //m_size = 0; // not m_size{ 0 }; -> its inialize and not
    }
private:
    void Random()
    {
        srand(time(0));
        for (size_t i = 0; i < m_size; i++)
        {
            m_buff[i] = rand() % 26 + 65;
        }
    }
    
    void Clone(const ByteArray& arr)
    {
        m_buff = new uint8_t[arr.m_size];
        m_size = arr.m_size;
        for (size_t i = 0; i < arr.m_size; ++i)
        {
            m_buff[i] = arr.m_buff[i];
        }
    }
    void Clear()
    {
        if (m_buff)
        {
            delete[] m_buff;
            m_buff = nullptr;
            m_size = 0;
        }
    }

    bool Equal(const uint8_t* it1Begin, const uint8_t* it1End, const uint8_t* it2Begin, const uint8_t* it2End)
    {
        //
        const uint8_t* ptr1 = it1Begin;
        const uint8_t* ptr2 = it2Begin;
        for (; ptr1 != it1End && ptr2 != it2End; ++ptr1, ++ptr2)
        {
            if (*ptr1 != *ptr2)
            {
                return false;
            }
        }
        if (ptr1 != it1End || ptr2 != it2End)
        {
            return false;
        }
        return true;
    }
private:
    uint8_t* m_buff{ nullptr };
    int m_size{ 0 };
};


int main()
{
    uint8_t arr[100];

    ByteArray array;
    ByteArray array1(100);
    ByteArray array2(array1);

    ByteArray array0 = array1; // constuctor of copy (by default)

    array0 = array1; // operator = (by default)

    // NOT
    int i = 0;
    //if (!i) // i != 0
    //{
    //    i = 2;
    //}
    bool b = !i; // true
    b = i != 0;  // false
    b = i == 0;  // true


    if (array == array2)
    {
        std::cout << "array1 is equal array2" << std::endl;
    }    

    if (!array)
    {
        std::cout << "array is empty" << std::endl;
        array = array1;
    }
    //if (array == array2)
    if (array.IsEqual(array2))
    {
        std::cout << "array is equal array2" << std::endl;
    }


    std::string s1 = "hello";
    std::string s2 = "hello";

    if (s1 == s2)
    {
        std::cout << "s1 is equal s2" << std::endl;
    }


    // example operator []
    std::cout << array0[2] << std::endl;
    std::cout << array0[28] << std::endl;
    std::cout << array0[55] << std::endl;
    std::cout << array0[15] << std::endl;


    return 0;
}
