#pragma once

#include <iostream>
#include <algorithm>
#include <cstring>
#include <cassert>      // для assert()

class String
{
public:
	String() {}
	String(const char* str)
    {
        m_length = strlen(str) + 1;
        m_buff = new char[m_length]; 
        for (size_t i = 0; i < m_length; ++i)
        {
            if ((i + 1) == m_length)
            {
                m_buff[i] = '\0';
            }
            else
            {
                m_buff[i] = str[i];
            }
        }
	}
    String(const String& str)
    {
        Clone(str);
    }
    String& operator=(const String& str)
    {
        Clear();
        Clone(str);
        return *this;
    }
    bool operator!()
    {
        return !m_length;
    }
    friend bool operator==(const String& str1, const String& str2)
    {
        return std::equal(str1.m_buff, str1.m_buff + str1.m_length, str2.m_buff, str2.m_buff + str2.m_length);
    }
    friend bool operator!=(const String& str1, const String& str2)
    {
        return !(str1 == str2);
    }

    String& operator+(const String& str)
    {
        char* tmpBuff = m_buff;
        int fullLength = strlen(m_buff) + strlen(str.m_buff) + 1; //  NULL terminator as end of string
        m_buff = new char[fullLength];
        for (size_t i = 0, j = 0; i < fullLength; ++i)
        {
            if (i < m_length && tmpBuff[i] != '\0')
            {
                m_buff[i] = tmpBuff[i];
            }
            else if ((i + 1) == fullLength)
            {
                m_buff[i] = '\0';
            }
            else
            {
                m_buff[i] = str.m_buff[j++];
            }
        }
        delete[] tmpBuff;
        m_length = fullLength;
        std::cout << m_length << std::endl;
        return *this;
    }

    char& operator[](int index)
    {
        assert(index >= 0 && index <= m_length);
        return m_buff[index];
    }
    friend std::ostream& operator<<(std::ostream& out, const String& str)
    {
        assert(str.m_length >= 0);
        out << str.m_buff;
        return out;
    }
    void Print() const
    {
        std::cout << m_buff << std::endl;
    }
	~String() 
    {
        Clear();
    }
private:
    void Clone(const String& str)
    {
        m_length = strlen(str.m_buff) + 1;
        m_buff = new char[m_length + 1];
        for (size_t i = 0; i < m_length; ++i)
        {
            if ((i + 1) == m_length)
            {
                m_buff[i] = '\0';
            }
            else
            {
                m_buff[i] = str.m_buff[i];
            }
        }
    }
    void Clear()
    {
        if (m_buff)
        {
            delete[] m_buff;
            m_buff = nullptr;
            m_length = 0;
        }
    }
private:
	char* m_buff{ nullptr };
	int m_length{ 0 };
};

