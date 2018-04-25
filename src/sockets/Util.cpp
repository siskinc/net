//
// Created by siskinc on 18-4-1.
//

#include <iostream>
#include "Util.hpp"

void Util::SetNonBlocking(int fd)
{
    int ret;
    int flags;
    flags = fcntl(fd, F_GETFL, 0);
    if (flags == -1)
    {
        std::cerr << "fd:" << fd << std::endl;
        throw SocketException(errno);
    }
    flags |= O_NONBLOCK;
    ret = fcntl(fd, F_SETFL, flags);
    if (ret == -1)
    {
        throw SocketException(errno);
    }
}
