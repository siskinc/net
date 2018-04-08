//
// Created by siskinc on 18-4-3.
//

#include "String.hpp"

std::string String::Upper(std::string str)
{
    auto end = str.end();
    for (auto it = str.begin(); it != end; ++it)
    {
        if (('a' <= *it) && (*it <= 'z'))
        {
            *it = static_cast<char>(*it - 0x20);
        }
    }
    return std::move(str);
}

std::string String::Lower(std::string str)
{
    auto end = str.end();
    for (auto it = str.begin(); it != end; ++it)
    {
        if (('A' <= *it) && (*it <= 'Z'))
        {
            *it = static_cast<char>(*it + 0x20);
        }
    }
    return std::move(str);
}

bool String::isDigits(const std::string &str)
{
    for (auto &item : str)
    {
        if (!isdigit(item))
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
    bool begin_zerox = str.substr(0, 2) == "0x";
    auto begin = str.begin() + (begin_zerox ? 2 : 0), end = str.end();
    for (auto item = begin; item != end; ++item)
    {
        if (!isHexDigit(*item))
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

    bool begin_zero = str.substr(0, 2) == "0x";
    auto begin = str.begin() + (begin_zero ? 1 : 0), end = str.end();
    for (auto item = begin; item != end; ++item)
    {
        if (!isOctDigit(*item))
            return false;
    }
    return true;
}

void String::SplitWhitespace(std::vector<std::string> &result, const std::string &str)
{
    std::string::size_type i, j, len = str.size();
    for (i = j = 0; i < len;)
    {

        while (i < len && ::isspace(str[i]))
            i++;
        j = i;


        while (i < len && !::isspace(str[i]))
            i++;
        if (j < i)
        {
            result.push_back(str.substr(j, i - j));
            while (i < len && ::isspace(str[i]))
                i++;
            j = i;
        }
    }
    if (j < len)
    {
        result.push_back(str.substr(j, len - j));
    }
}

void String::Split(std::vector<std::string> &result, const std::string &str, const std::string &delimiter)
{
    result.clear();
    //split函数默认为空格为分隔符
    if (0 == delimiter.size())
    {
        //调用函数进行空格切割
        SplitWhitespace(result, str);
        return;
    }
    std::string::size_type i, j, len = str.size(), n = delimiter.size();
    i = j = 0;
    while (i + n <= len)
    {
        if (str[i] == delimiter[0] && str.substr(i, n) == delimiter)
        {
            result.push_back(str.substr(j, i - j));
            i = j = i + n;
        } else
            i++;
    }

    //剩下部分
    result.push_back(str.substr(j, len - j));
}

std::string String::RTrim(std::string str)
{
    const auto pos = str.find_last_not_of(" \t\f\v\n\r");
    str.erase(pos + 1);
    return std::move(str);
}

std::string String::LTrim(std::string str)
{
    const auto pos = str.find_first_not_of(" \t\f\v\n\r");
    str.erase(0, pos);
    return std::move(str);
}

std::string String::Trim(std::string str)
{
    return LTrim(RTrim(std::move(str)));
}
