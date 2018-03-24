//
// Created by siskinc on 18-3-24.
//

#ifndef NET_EPOLLSOCKET_HPP
#define NET_EPOLLSOCKET_HPP

#include "TcpSocket.hpp"



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


#endif //NET_EPOLLSOCKET_HPP
