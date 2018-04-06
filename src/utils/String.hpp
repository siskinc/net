//
// Created by siskinc on 18-4-3.
//

#ifndef NET_STRING_HPP
#define NET_STRING_HPP

#include <string>

class String
{
public:
    static void Upper(std::string& str);
    static void Lower(std::string& str);
    static bool isDigit(const char &c);
    static bool isDigits(const std::string& str);
    static bool isHexDigit(const char& c);
    static bool isHexDigits(const std::string& str);
    static bool isOctDigit(const char& c);
    static bool isOctDigit(const std::string& str);
};


#endif //NET_STRING_HPP
