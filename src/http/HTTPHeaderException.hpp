//
// Created by siskinc on 18-4-6.
//

#ifndef NET_HTTPHEADEREXCEPTION_HPP
#define NET_HTTPHEADEREXCEPTION_HPP

#include <exception>
#include <string>

class HTTPHeaderException : std::exception
{
public:
    explicit HTTPHeaderException(std::string &error_str)
    {
        this->error_str = error_str;
    }

    const char *what() const noexcept override
    {
        auto w = "information of headers error " + error_str;
        return w.data();
    }

private:
    std::string error_str;
public:
    const std::string &GetError_str() const
    {
        return error_str;
    }

    void SetError_str(const std::string &error_str)
    {
        HTTPHeaderException::error_str = error_str;
    }
};


#endif //NET_HTTPHEADEREXCEPTION_HPP
