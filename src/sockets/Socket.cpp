//
// Created by siskinc on 18-4-1.
//

#include "Socket.hpp"

Socket::Socket() : Socket(8000, "127.0.0.1") {}

Socket::Socket(const int port, const std::string &address)
{
    bzero(&this->address, sizeof(this->address));
    this->address.sin_addr.s_addr = inet_addr(address.data());
    this->address.sin_port = htons(static_cast<uint16_t >(port));
    this->address.sin_family = AF_INET;
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd == -1)
    {
        throw SocketException(errno);
    }
}
