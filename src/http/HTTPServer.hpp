//
// Created by siskinc on 18-4-9.
//

#ifndef NET_HTTPSERVER_HPP
#define NET_HTTPSERVER_HPP

#include "../sockets/TcpSocketServer.hpp"

namespace http {

class HTTPServer : TcpSocketServer
{
public:
    HTTPServer();

    HTTPServer(std::string address, int port);

    HTTPServer(std::string address);

};

}


#endif //NET_HTTPSERVER_HPP
