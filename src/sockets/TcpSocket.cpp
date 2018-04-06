//
// Created by siskinc on 18-3-28.
//


#include "TcpSocket.hpp"

TcpSocket::TcpSocket()
{
    this->buffer_size = 1024;
}


void TcpSocket::onRead(Socket::file_description fd, std::string &buffer)
{
    auto chBuf = static_cast<char *>(malloc(buffer_size));
    int ret = 0;
    while((ret = read(fd, chBuf, buffer_size) != 0))
    {
        if(ret == -1)
        {
            throw SocketException(errno);
        }
        buffer += chBuf;
    }
}

void TcpSocket::onRead(Socket::file_description fd, std::vector<char> &buffer)
{
    auto chBuf = static_cast<char *>(malloc(buffer_size));
    int ret = 0;
    while((ret = read(fd, chBuf, buffer_size) != 0))
    {
        if(ret == -1)
        {
            throw SocketException(errno);
        }
        ssize_t len = strlen(chBuf);
        for(int i = 0; i < len; ++i)
        {
            buffer.emplace_back(chBuf[i]);
        }
    }
}

int TcpSocket::GetBuffer_size()
{
    return buffer_size;
}

void TcpSocket::SetBuffer_size(int buffer_size)
{
    TcpSocket::buffer_size = buffer_size;
}

template<int N>
void TcpSocket::onRead(Socket::file_description fd, std::array<char, N> &buffer)
{
    int ret = 0;
    int size = N-1;
    int nread = 0;
    while(size > 0 && (ret = read(fd, buffer.data()+nread, size) != 0))
    {
        if(ret == -1)
        {
            throw SocketException(errno);
        }
        nread += ret;
        size -= ret;
    }
}

ssize_t TcpSocket::onWrite(Socket::file_description fd, std::string &buffer)
{
    size_t len = buffer.length();
    size_t nwrite = 0;
    size_t leave_len = len;
    ssize_t ret = 0;
    while(nwrite < len && (ret = write(fd, buffer.data()+nwrite, leave_len)))
    {
        if(ret == -1)
        {
            throw SocketException(errno);
        }
        nwrite += ret;
        leave_len -= ret;
    }
    return nwrite;
}

ssize_t TcpSocket::onWrite(Socket::file_description fd, std::vector<char> &buffer)
{
    size_t len = buffer.size();
    size_t nwrite = 0;
    size_t leave_len = len;
    ssize_t ret = 0;
    while(nwrite < len && (ret = write(fd, buffer.data()+nwrite, leave_len)))
    {
        if(ret == -1)
        {
            throw SocketException(errno);
        }
        nwrite += ret;
        leave_len -= ret;
    }
    return nwrite;
}

template<int N>
ssize_t TcpSocket::onWrite(Socket::file_description fd, std::array<char, N> &buffer)
{
    size_t len = N;
    size_t nwrite = 0;
    size_t leave_len = len;
    ssize_t ret = 0;
    while(nwrite < len && (ret = write(fd, buffer.data()+nwrite, leave_len)))
    {
        if(ret == -1)
        {
            throw SocketException(errno);
        }
        nwrite += ret;
        leave_len -= ret;
    }
    return nwrite;
}



