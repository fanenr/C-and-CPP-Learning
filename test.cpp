#include <iostream>
#include <memory>

using std::cout;

auto func(std::unique_ptr<int>& p)
{
    cout << "p: " << p << "\n";
    cout << "v: " << *p << "\n";
}

template <typename... Args>
auto func(Args... args)
{
}

int main()
{
    func(1, 2, 3, 4);

    // auto pa = std::make_unique<int>(10);
    // auto& pb = pa;

    // *pb = 100;
    // func(pa);

    // cout << "pa: " << pa << "\n";
    // cout << "pv: " << *pa;
}
