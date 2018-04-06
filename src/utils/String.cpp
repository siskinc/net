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

bool String::isDigits(const std::string &str)
{
    for(auto &item : str)
    {
        if(!isdigit(item))
        {
            return false;
        }
    }
    return true;
}

bool String::isHexDigit(const char &c)
{
    return (c >= '0' && c <= '9') ||
           (c >= 'A' && c <= 'F') ||
           (c >= 'a' && c <= 'f');
}

bool String::isHexDigits(const std::string &str)
{
    bool begin_zerox = str.substr(0,2) == "0x";
    auto begin = str.begin() + (begin_zerox ? 2 : 0), end = str.end();
    for(auto item = begin; item != end; ++item)
    {
        if(!isHexDigit(*item))
            return false;
    }
    return true;
}

bool String::isDigit(const char &c)
{
    return isdigit(c);
}

bool String::isOctDigit(const char &c)
{
    return c >= '0' && c <= '7';
}

bool String::isOctDigit(const std::string &str)
{

    bool begin_zero = str.substr(0,2) == "0x";
    auto begin = str.begin() + (begin_zero ? 1 : 0), end = str.end();
    for(auto item = begin; item != end; ++item)
    {
        if(!isOctDigit(*item))
            return false;
    }
    return true;
}
