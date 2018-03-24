//
// Created by siskinc on 18-3-24.
//

#include "TcpSocket.hpp"


TcpSocket::TcpSocket(bool inited,
                     int file_description_num,
                     std::string file_description_is_too_much_error)
        : inited(inited),
          file_description_num(file_description_num),
          file_description_is_too_much_error(file_description_is_too_much_error) {}

TcpSocket::TcpSocket(Address &&address)
        :TcpSocket()
{
    address_ = address;
}

TcpSocket::TcpSocket(const std::string &address)
        :TcpSocket()
{
    address_ = address;
}

TcpSocket::TcpSocket(std::string &&address)
        :TcpSocket()
{
    address_ = address;
}

void TcpSocket::Write(file_description fd, std::string &data)
{
    const char *cdata = data.data();
    auto size = data.size();
    int begin = 0;
    while (begin < size)
    {
        ssize_t n = write(fd, cdata + begin, size - begin);
        if (n == -1)
        {
            std::cerr << "Write error : " << strerror(errno) << std::endl;
            exit(EXIT_FAILURE);
        }
        begin += n;
    }
}

void TcpSocket::Write(file_description fd, std::string &&data)
{
    const char *cdata = data.data();
    auto size = data.size();
    int begin = 0;
    while (begin < size)
    {
        ssize_t n = write(fd, cdata + begin, size - begin);
        if (n == -1)
        {
            std::cerr << "Write error : " << strerror(errno) << std::endl;
            exit(EXIT_FAILURE);
        }
        begin += n;
    }
}

std::string &&TcpSocket::Read(file_description fd)
{
    std::string data;
    char buffer[1024];
    while (true)
    {
        bzero(buffer, sizeof(buffer));
        ssize_t n = read(fd, buffer, sizeof(buffer));
        if (n == -1)
        {
            std::cerr << "Read error : " << strerror(errno) << std::endl;
            exit(EXIT_FAILURE);
        }
        if (n == 0)
            break;
        data += buffer;
    }
    return std::move(data);
}

void TcpSocket::Close(file_description fd)
{
    close(fd);
}