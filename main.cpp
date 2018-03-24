#include <iostream>
#include <memory>
#include "src/Address.hpp"
#include "src/util.hpp"
#include <functional>

class A
{
public:
    A()
    {
        std::cout << "A()" << std::endl;
    }

    A(int) : A()
    {
        std::cout << "A(int)" << std::endl;
    }
};

int main()
{
    std::cout << std::equal_to<int>()(1,2) << std::endl;
    A a(1);
    return 0;
}