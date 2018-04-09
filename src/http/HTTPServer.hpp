//
// Created by siskinc on 18-4-9.
//

#ifndef NET_HTTPSERVER_HPP
#define NET_HTTPSERVER_HPP

#include "../sockets/TcpSocketServer.hpp"
#include "../sockets/AddressListenException.hpp"
#include <queue>
#include <boost/lexical_cast.hpp>

namespace http {

class HTTPServer : TcpSocketServer
{
public:
    HTTPServer();

    HTTPServer(std::string address, int port);

    explicit HTTPServer(std::string address_and_port);

    void Run();

    void onListen(int backlog = 128);

    void onBind();

    void onSetNonBlocking();

    void onAccept();

    void AddQueue(int fd);

protected:
    std::queue<int> fds;

};

}


#endif //NET_HTTPSERVER_HPP
