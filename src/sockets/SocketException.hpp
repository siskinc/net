//
// Created by siskinc on 18-3-28.
//

#ifndef NET_SOCKETEXCEPTION_HPP
#define NET_SOCKETEXCEPTION_HPP

#include <exception>
#include <string>
#include <cstring>
#include <cerrno>

class SocketException : public std::exception
{
public:
    SocketException(int error)
            : exception()
    {
        error_str_ = strerror(errno);
    }

    const char *what() const noexcept override
    {
        return error_str_.c_str();
    }

private:
    std::string error_str_;
};

#endif //NET_SOCKETEXCEPTION_HPP
