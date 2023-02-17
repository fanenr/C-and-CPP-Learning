#ifndef E_C
#define E_C
#include <iostream>
#include <string>

class first {
private:
    std::string name;
    int age = 0;
    void hello()
    {
        std::cout << "hello";
    }

public:
    // constructer
    first();
    first(std::string name, int age);
    // deconstructer
    ~first();

    std::string getName();
    int getAge();
    void addAge(int n);
    void setName(std::string name);

    first operator+(const first& f) const;
    friend std::ostream& operator<<(std::ostream& os, const first& f);

    operator int();
};

#endif