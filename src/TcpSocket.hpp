//
// Created by siskinc on 18-3-24.
//

#ifndef NET_TCPSOCKET_HPP
#define NET_TCPSOCKET_HPP

#include "Socket.hpp"

class TcpSocket
        : public Socket
{
public:
    TcpSocket(bool inited = false,
              int file_description_num = 0,
              std::string file_description_is_too_much_error = FILE_DESCRIPTION_IS_TOO_MUCH_ERROR);

    TcpSocket(Address &&address);

    TcpSocket(const std::string &address);

    TcpSocket(std::string &&address);

    virtual void Run(const std::string &&address, int backlog = BACK_LOG){};

    virtual void Run(int backlog = BACK_LOG){};

private:
    virtual void init(){};

    virtual void Bind(){};

    virtual void Listen(int backlog = BACK_LOG){};

    virtual file_description Accept(){};

protected:
    inline static void Write(file_description fd, std::string &&data);

    inline static void Write(file_description fd, std::string &data);

    inline static std::string &&Read(file_description fd);

    inline static void Close(file_description fd);

    file_description listen_fd;
    socklen_t client_len;
    sockaddr_in serveraddr;
    sockaddr_in clientaddr;
    bool inited;
    Address address_;
    std::string file_description_is_too_much_error;
    unsigned int file_description_num;
};


#endif //NET_TCPSOCKET_HPP
