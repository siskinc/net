//
// Created by siskinc on 18-4-9.
//

#ifndef NET_ADDRESSLISTENEXCEPTION_HPP
#define NET_ADDRESSLISTENEXCEPTION_HPP

#include <exception>

class AddressListenException : std::exception
{
public:
    AddressListenException() = default;

    const char *what() const override
    {
        return "Please input valid address(egg: :8000 127.0.0.1:8000)";
    }
};

#endif //NET_ADDRESSLISTENEXCEPTION_HPP
