//
// Created by siskinc on 18-4-3.
//

#include "String.hpp"

void String::Upper(std::string &str)
{
    auto end = str.end();
    for(auto it = str.begin(); it != end; ++it)
    {
        if(isalpha(*it) && islower(*it))
        {
            *it -= 32;
        }
    }
}

void String::Lower(std::string &str)
{
    auto end = str.end();
    for(auto it = str.begin(); it != end; ++it)
    {
        if(isalpha(*it) && isupper(*it))
        {
            *it += 32;
        }
    }
}
