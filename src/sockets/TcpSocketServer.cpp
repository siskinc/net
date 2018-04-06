//
// Created by siskinc on 18-3-28.
//


#include "TcpSocketServer.hpp"

void TcpSocketServer::onBind()
{
    int ret;
    ret = bind(fd, (sockaddr *) &address, sizeof(address));
    if (ret == -1)
    {
        throw SocketException(errno);
    }
}

void TcpSocketServer::onSetNonBlocking()
{
    Util::SetNonBlocking(this->fd);
}

void TcpSocketServer::onListen(int backlog)
{
    int ret;
    ret = listen(fd, backlog);
    if (ret == -1)
    {
        throw SocketException(errno);
    }
}

void TcpSocketServer::onAccept()
{
    int ret;
    socklen_t len;
    len = static_cast<socklen_t >(sizeof(client_fd_));
    ret = accept(fd, (sockaddr *) &clientaddr_, &len);
    if (ret == -1)
    {
        throw SocketException(errno);
    }
}

void TcpSocketServer::Run(std::function<void(int)> callback, int num_of_events)
{
    this->epoll_fd = epoll_create1(0);
    if (this->epoll_fd == -1)
    {
        throw SocketException(errno);
    }

    // push server file description in array of epoll event
    event.data.fd = this->fd;
    event.events = EPOLLIN | EPOLLOUT;
    int ret;
    ret = epoll_ctl(this->epoll_fd, EPOLL_CTL_ADD, this->fd, &event);
    if (ret == -1)
    {
        throw SocketException(errno);
    }

    // Buffer where events are returned
    events = static_cast<epoll_event *>(calloc(num_of_events, sizeof(epoll_event)));
    int num, i;
    while (1)
    {
        num = epoll_wait(this->epoll_fd, events, num_of_events, -1);
        for (i = 0; i < num; ++i)
        {
            if ((events[i].events & EPOLLERR) ||
                (events[i].events & EPOLLHUP) ||
                (!(events[i].events & EPOLLIN)))
            {

                // if the file description of error is server file description
                if (events[i].data.fd == this->fd)
                {
                    throw SocketException(errno);
                }
                // print error information
                close(events[i].data.fd);
                continue;
            } else if (this->fd == events[i].data.fd)
            {
                while (1)
                {
                    try
                    {
                        this->onAccept();
                    }
                    catch (SocketException &e)
                    {
                        std::cout << e.what() << std::endl;
                        break;
                    }
                    Util::SetNonBlocking(this->client_fd_);
                    event.data.fd = this->client_fd_;
                    event.events = EPOLLIN | EPOLLET;
                    ret = epoll_ctl(this->epoll_fd, EPOLL_CTL_ADD, this->client_fd_, &event);
                    if (ret == -1)
                    {
                        throw SocketException(errno);
                    }
                }
            } else
            {
                callback(events[i].data.fd);
            }
        }
    }
}
