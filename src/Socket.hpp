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

class TcpSocket
        : public Socket
{
public:
    TcpSocket(bool inited = false,
              int file_description_num = 0,
              std::string file_description_is_too_much_error = FILE_DESCRIPTION_IS_TOO_MUCH_ERROR);

    TcpSocket(Address &&address);

    TcpSocket(const std::string &address);

    TcpSocket(std::string &&address);

    virtual void Run(const std::string &&address, int backlog = BACK_LOG){};

    virtual void Run(int backlog = BACK_LOG){};

private:
    virtual void init(){};

    virtual void Bind(){};

    virtual void Listen(int backlog = BACK_LOG){};

    virtual file_description Accept(){};

protected:
    inline static void Write(file_description fd, std::string &&data);

    inline static void Write(file_description fd, std::string &data);

    inline static std::string &&Read(file_description fd);

    inline static void Close(file_description fd);

    file_description listen_fd;
    socklen_t client_len;
    sockaddr_in serveraddr;
    sockaddr_in clientaddr;
    bool inited;
    Address address_;
    std::string file_description_is_too_much_error;
    unsigned int file_description_num;
};

class EpollSocket
        : public TcpSocket
{
public:
    EpollSocket(const std::string &address);

    EpollSocket(Address &&address);

    EpollSocket(const unsigned int epoll_num = EPOLL_NUM);

    ~EpollSocket();

    void address(Address &&address);

    void address(const std::string address);

    Address address();

    const Address address() const;

    void epoll_num(const unsigned int &&epoll_num);

    int epoll_num();

    const int epoll_num() const;

    void call_back(std::function<void(int)> &&call_back);

    void Run(const std::string &&address, int backlog) override;

    void Run(int backlog) override;

    void FileDescriptionIsTooMuchError(std::string &&error);


private:
    void init() override;

    void Bind() override;

    void Listen(int backlog = BACK_LOG) override;

    file_description Accept() override;


    void EpollRun();

    file_description epoll_fd;
    epoll_event ev;
    epoll_event *events;
    unsigned int epoll_num_;
    std::function<void(file_description)> call_back_;
};

#endif //NET_SOCKET_HPP
