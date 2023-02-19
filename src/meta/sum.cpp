#include <iostream>

template <int N>
struct sum {
    static int const value = N + sum<N - 1>::value;
};

template <>
struct sum<1> {
    static int const value = 1;
};

int main(void)
{
    std::cout << sum<10>::value;
}