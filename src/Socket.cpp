//
// Created by siskinc on 18-3-22.
//

#include "Socket.hpp"

void EpollSocket::Bind()
{
    if(bind(listen_fd, (sockaddr*)&serveraddr, sizeof(serveraddr)) == -1)
    {
        std::cerr << "Bind error: " << strerror(errno) << std::endl;
        exit(EXIT_FAILURE);
    }
}

EpollSocket::EpollSocket(std::string addrandport)
{

}
