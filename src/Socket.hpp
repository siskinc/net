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
#include <iostream>
#include <string>
#include <boost/algorithm/string.hpp>

class Socket
{
public:
    Socket(){};
};

class TcpSocket
    : public Socket
{
public:
    TcpSocket(){};
    virtual void Run(std::string) = 0;

private:
    virtual void Bind() = 0;
    virtual void Listen() = 0;
    virtual void Accept() = 0;

protected:
    int listen_fd;
    sockaddr_in serveraddr;
    sockaddr_in clientaddr;
};

class EpollSocket
        : public TcpSocket
{
public:
    EpollSocket(std::string addrandport);
private:
    void Bind() override;
};

#endif //NET_SOCKET_HPP
