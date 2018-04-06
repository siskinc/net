//
// Created by siskinc on 18-4-3.
//

#ifndef NET_HTTPVERSIONEXCEPTION_HPP
#define NET_HTTPVERSIONEXCEPTION_HPP

#include <exception>
#include <iostream>

class HTTPVersionException : std::exception
{
public:
    HTTPVersionException() = default;

private:
    const char *what() const noexcept override
    {
        return "Http version is error, please input a valid http version(HTTP/1.1 or HTTP/1.0)";
    }
};


#endif //NET_HTTPVERSIONEXCEPTION_HPP
