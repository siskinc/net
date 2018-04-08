#include <iostream>
#include "src/http/HTTPParser.hpp"
#include <boost/algorithm/string.hpp>
#include <container/vector.hpp>
#include "src/utils/String.hpp"



int main()
{
    auto ret = String::explode<std::string>('b', std::string("   aaabaa aaa "), 10);
    for (auto item = ret.begin(); item != ret.end(); item++)
    {
        std::cout << *item << std::endl;
    }

    return 0;
}