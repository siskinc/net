#include <iostream>
#include <memory>
#include "src/Address.hpp"
#include "src/util.hpp"

int main()
{
    if(util::IsIpv4("12.a.143.112"))
    {
        std::cout << "是" << std::endl;
    }
    return 0;
}