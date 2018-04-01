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
#include "SocketException.hpp"

class Socket
{
public:
    typedef int file_description;
    Socket();
    Socket(const int port, const std::string &address);

protected:
    sockaddr_in address;
    file_description fd;
};

#endif //NET_SOCKET_HPP
