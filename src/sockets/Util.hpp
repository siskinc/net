//
// Created by siskinc on 18-4-1.
//

#ifndef NET_UTIL_HPP
#define NET_UTIL_HPP

#include "SocketException.hpp"
#include <fcntl.h>

class Util
{
public:
    static void SetNonBlocking(int fd);
};


#endif //NET_UTIL_HPP
