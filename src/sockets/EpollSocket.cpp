//
// Created by siskinc on 18-3-24.
//

#include "EpollSocket.hpp"



void EpollSocket::Bind()
{
    if (bind(listen_fd, (sockaddr *) &serveraddr, sizeof(serveraddr)) == -1)
    {
        std::cerr << "Bind error: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
}

EpollSocket::EpollSocket(const std::string &address)
        : TcpSocket(address)
{
}

EpollSocket::EpollSocket(Address &&address)
        : TcpSocket(std::move(address))
{
}

void EpollSocket::address(Address &&address)
{
    address_ = address;
    inited = true;
}

void EpollSocket::address(const std::string address)
{
    address_ = Address(address);
    inited = true;
}

Address EpollSocket::address()
{
    return address_;
}

const Address EpollSocket::address() const
{
    return address_;
}

void EpollSocket::Listen(int backlog)
{
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_fd == -1)
    {
        std::cerr << "Listen error: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    if (listen(listen_fd, backlog) == -1)
    {
        std::cerr << "Listen error: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

    if (!util::SetSocketNonBlocking(listen_fd))
    {
        std::cerr << "Set Listen Socket be non-blocking error: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }

}

file_description EpollSocket::Accept()
{
    file_description fd = accept(listen_fd, (sockaddr *) &clientaddr, &client_len);
    if (fd == -1)
    {
        std::cerr << "Accept error: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
    return fd;
}

void EpollSocket::Run(const std::string &&address, int backlog)
{
    address_ = Address(address);
    inited = true;
    Run(backlog);
}

void EpollSocket::Run(int backlog)
{
    if (!inited)
    {
        std::cerr << "Epoll Socket have not inited, you have to init property of Epoll Socket, address." << std::endl;
        exit(EXIT_FAILURE);
    }

    Bind();
    Listen();
    EpollRun();
}

void EpollSocket::epoll_num(const unsigned int &&epoll_num)
{
    epoll_num_ = epoll_num;
}

int EpollSocket::epoll_num()
{
    return epoll_num_;
}

const int EpollSocket::epoll_num() const
{
    return epoll_num_;
}

void EpollSocket::EpollRun()
{
    epoll_fd = epoll_create(epoll_num_);
    if (epoll_fd == -1)
    {
        std::cerr << "epoll create error : " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
    events = new epoll_event[epoll_num_];
    ev.data.fd = listen_fd;
    ev.events = EPOLLET | EPOLLIN;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, ev.data.fd, events);
    while (true)
    {
        int n = epoll_wait(epoll_fd, events, epoll_num_, 0);
        for (int i = 0; i < n; ++i)
        {
            if ((events[i].events & EPOLLERR) ||
                (events[i].events & EPOLLHUP) ||
                !(events[i].events & EPOLLIN))
            {
                if (listen_fd == events[i].data.fd)
                {
                    std::cerr << "epoll error , listen file description is error : " << strerror(errno) << std::endl;
                    exit(EXIT_FAILURE);
                }
                std::cout << "epoll error: " << strerror(errno) << std::endl;
                close(events[i].data.fd);
                --file_description_num;
                continue;
            } else if (listen_fd == events[i].data.fd)
            {
                file_description fd = accept(listen_fd, (sockaddr *) &clientaddr, &client_len);

                if (fd == -1)
                {
                    std::cerr << "accept error : " << strerror(errno) << std::endl;
                    exit(EXIT_FAILURE);
                }

                if (file_description_num >= epoll_num_)
                {
                    Write(fd, file_description_is_too_much_error);
                    Close(fd);
                }
                ev.data.fd = fd;
                ev.events = EPOLLIN | EPOLLET;
                int ret = epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, events);
                if (ret == -1)
                {
                    std::cerr << "epoll add file description error : " << strerror(errno) << std::endl;
                    exit(EXIT_FAILURE);
                }
            } else
            {
                call_back_(events->data.fd);
            }
        }
    }
}

EpollSocket::~EpollSocket()
{
    delete[] events;
}

void EpollSocket::call_back(std::function<void(file_description)> &&call_back)
{
    call_back_ = call_back;
}


void EpollSocket::FileDescriptionIsTooMuchError(std::string &&error)
{
    file_description_is_too_much_error = error;
}

EpollSocket::EpollSocket(const unsigned int epoll_num)
        :epoll_num_(epoll_num), TcpSocket(0)
{

}

void EpollSocket::init()
{
    serveraddr.sin_port = htons(address_.port());
    serveraddr.sin_family = AF_INET;
    inet_pton(AF_INET, address_.address().data(), &serveraddr.sin_addr);
    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(listen_fd == -1)
    {
        std::cerr << "socket error : " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
}
