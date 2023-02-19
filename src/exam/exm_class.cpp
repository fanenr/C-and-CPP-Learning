#include "exm_class.h"
#include <iostream>
#include <string>

first::first()
{
    name = "Arthur";
    age = 18;
}

first::first(std::string n_name, int n_age)
{
    name = n_name;
    age = n_age;
}

first::~first()
{
    std::cout << "Good bye " << name;
}

std::string first::getName()
{
    return name;
}

int first::getAge()
{
    return age;
}

void first::addAge(int n)
{
    age += n;
}

void first::setName(std::string str)
{
    name = str;
}

first first::operator+(const first& f) const
{
    first fn;
    fn.age = age + f.age;
    return fn;
}

std::ostream& operator<<(std::ostream& os, const first& f)
{
    os << "name: " << f.name << std::endl;
    return os;
}

first::operator int()
{
    return age;
}