//
// Created by siskinc on 18-3-28.
//

#ifndef NET_TCPSOCKETSERVER_HPP
#define NET_TCPSOCKETSERVER_HPP

#include "TcpSocket.hpp"
#include "Comment.hpp"
#include "Util.hpp"
#include <functional>
#include <iostream>
#include <sys/epoll.h>
#include <unistd.h>
#include <fcntl.h>

#include <boost/function.hpp>

class TcpSocketServer : public TcpSocket
{
public:
    TcpSocketServer();

    TcpSocketServer(std::string address, const int port);

    void onListen(int backlog = 128);

    void onBind();

    void onSetNonBlocking();

    void onAccept();

    void Run(boost::function<void(int)> callback, const int num_of_events = DEFAULT_EVENTS);

private:
    sockaddr_in clientaddr_;
    epoll_event event;
    epoll_event *events;
    file_description epoll_fd;
    file_description client_fd_;
};


#endif //NET_TCPSOCKETSERVER_HPP
