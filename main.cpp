#include <iostream>
#include <memory>
#include "src/Address.hpp"
#include "src/util.hpp"
#include <functional>

int main()
{
    std::cout << std::equal_to<int>()(1,2) << std::endl;
    return 0;
}