#include <cstring>
#include <iostream>

class myString {
private:
    static int count;
    char* src;
    int len;

public:
    // constructor
    myString();
    myString(const char*);
    myString(const myString&);
    // deconstructor
    ~myString();

    operator char*();
    myString operator=(const myString&);
    myString operator+(const myString&);
    friend std::ostream& operator<<(std::ostream&, const myString&);
};

int myString::count = 0;

myString::myString()
{
    count++;
    src = new char[1];
    std::strcpy(src, "\0");
    len = 0;
}

myString::operator char*()
{
    return src;
}

myString::myString(const myString& from)
{
    len = from.len;
    src = new char[len + 1];
    std::strcpy(src, from.src);
    std::cout << "created: " << from << " count: " << ++count << std::endl;
}

myString::myString(const char* from)
{
    len = std::strlen(from);
    src = new char[len + 1];
    std::strcpy(src, from);
    std::cout << "created: " << from << " count: " << ++count << std::endl;
}

myString::~myString()
{
    std::cout << "destoryed: " << src << " count: " << --count << std::endl;
    delete[] src;
}

myString myString::operator=(const myString& from)
{
    if (&from == this)
        return *this;
    myString temp;
    temp.len = from.len;
    temp.src = new char[temp.len + 1];
    std::strcpy(temp.src, from.src);
    return temp;
}

myString myString::operator+(const myString& from)
{
    myString temp;
    temp.len = len + from.len;
    temp.src = new char[temp.len + 1];
    std::strcpy(temp.src, src);
    std::strcat(temp.src, from.src);
    return temp;
}

std::ostream& operator<<(std::ostream& os, const myString& from)
{
    os << from.src;
    return os;
}

using std::cout;

void func(const myString& str)
{
    cout << "func: " << str << std::endl;
}

void func2(myString str)
{
    cout << "func2: " << str << std::endl;
}

void func3(const char* str)
{
    cout << "func3: " << str << std::endl;
}

int main(void)
{
    myString str1("wu");
    myString str2 = "fan";
    myString str3 = str2;

    func(str1);
    func2(str3);
    func3(str1);

    return 0;
}