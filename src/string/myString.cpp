#include "myString.h"
#include <cstring>

myString::myString()
{
    len = 0;
    src = new char[1];
}

myString::myString(const char* str)
{
    len = strlen(str);
    src = new char[len + 1];
    std::strcpy(src, str);
}

myString::~myString()
{
    delete[] src;
}

myString::myString(const myString& from)
{
    len = from.len;
    src = new char[len + 1];
    std::strcpy(src, from.src);
}

myString& myString::operator=(const myString& from)
{
    delete[] src;
    len = from.len;
    src = new char[len + 1];
    std::strcpy(src, from.src);
}

myString::operator char*() const
{
    char* temp = new char[len + 1];
    std::strcpy(temp, src);
    return temp;
}

myString::operator std::string() const
{
    std::string temp = src;
    return temp;
}

myString myString::operator+(const myString& from) const
{
    myString temp;
    temp.len = len + from.len;
    temp.src = new char[temp.len + 1];
    std::strcpy(temp.src, src);
    std::strcat(temp.src, from.src);
    return temp;
}

char& myString::operator[](int i) const
{
    return src[i];
}

std::ostream& operator<<(std::ostream& os, const myString& from)
{
    os << from.src;
    return os;
}