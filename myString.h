#include <iostream>

#ifndef MYSTRING_H
#define MYSTRING_H

class myString {
private:
    char* src;
    int len;

public:
    // 构造函数
    myString();
    myString(const char*);
    // 析构函数
    ~myString();
    // 复制构造函数
    myString(const myString&);
    // 赋值运算符
    myString& operator=(const myString&);
    // 转换函数
    operator char*() const;
    operator std::string() const;
    // 重载 +
    myString operator+(const myString&) const;
    // 重载 []
    char& operator[](int) const;
    // 重载 <<
    friend std::ostream& operator<<(std::ostream&, const myString&);

    // 核心实现
    virtual int length() const { return len; }
};

#endif