#include <iostream>
#include <test/test.hpp>
#include <fmt/core.h>

int main(void)
{
    using std::cout;

    cout << "Hello CMake" << std::endl;

    // invoke
    cout << "invoke: " << test::invoke() << "\n";

    fmt::print("hello {}", "fmt");
}