//
// Created by siskinc on 18-3-27.
//

#ifndef NET_SOCKET_HPP
#define NET_SOCKET_HPP

#include <sys/socket.h>
#include <netinet/in.h>
#include <string>
#include <arpa/inet.h>
#include <cstring>

class Socket
{
public:
    typedef int file_description;
    Socket() : Socket(8000, "127.0.0.1"){};
    Socket(const int port, const std::string &address)
    {
        bzero(&this->address, sizeof(this->address));
        this->address.sin_addr.s_addr = inet_addr(address.data());
        this->address.sin_port = htons(static_cast<uint16_t >(port));
        this->address.sin_family = AF_INET;
    }

private:
    sockaddr_in address;
    file_description fd;
};

#endif //NET_SOCKET_HPP
