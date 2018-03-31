//
// Created by siskinc on 18-3-28.
//

#ifndef NET_TCPSOCKET_HPP
#define NET_TCPSOCKET_HPP

#include "Socket.hpp"
#include <vector>

class TcpSocket : public Socket
{
public:
    virtual inline static void onRead(file_description fd, std::string& buffer);
    virtual inline static void onRead(file_description fd, std::vector<char>& buffer);
    virtual inline static void onWrite(file_description fd, std::string& buffer);
    virtual inline static void onWrite(file_description fd, std::vector<char>& buffer);
};


#endif //NET_TCPSOCKET_HPP
