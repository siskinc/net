//
// Created by siskinc on 18-4-1.
//

#include "Socket.hpp"

Socket::Socket() : Socket("127.0.0.1", 8000)
{

}

Socket::Socket(std::string address, const int port)
{
    SetAddress(address, port);
}

void Socket::SetAddress(std::string address, const int port)
{
    bzero(&this->address, sizeof(this->address));
    this->address.sin_addr.s_addr = inet_addr(address.data());
    this->address.sin_port = htons(static_cast<uint16_t >(port));
    this->address.sin_family = AF_INET;
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if (fd == -1)
    {
        throw SocketException(errno);
    }
}
