//
// Created by siskinc on 18-3-28.
//

#ifndef NET_TCPSOCKET_HPP
#define NET_TCPSOCKET_HPP

#include "Socket.hpp"
#include <vector>
#include <array>
#include <unistd.h>
#include <cstring>

class TcpSocket : public Socket
{
public:
    TcpSocket();

    virtual inline void onRead(file_description fd, std::string &buffer);

    virtual inline void onRead(file_description fd, std::vector<char> &buffer);

    template<int N>
    inline static void onRead(file_description fd, std::array<char, N> &buffer);

    virtual inline ssize_t onWrite(file_description fd, std::string &buffer);

    virtual inline ssize_t onWrite(file_description fd, std::vector<char> &buffer);

    template<int N>
    inline static ssize_t onWrite(file_description fd, std::array<char, N> &buffer);

public:
    size_t buffer_size;
public:
    int GetBuffer_size();

    void SetBuffer_size(int buffer_size);
};


#endif //NET_TCPSOCKET_HPP
