//
// Created by siskinc on 18-3-22.
//

#ifndef NET_SOCKET_HPP
#define NET_SOCKET_HPP

#include <cstring>
#include <cerrno>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <iostream>
#include <string>
#include <functional>

#include <boost/algorithm/string.hpp>
#include "Address.hpp"
#include "Common.hpp"

class Socket
{
public:
    Socket() {};
};

#endif //NET_SOCKET_HPP
