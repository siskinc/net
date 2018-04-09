//
// Created by siskinc on 18-4-9.
//

#include "HTTPServer.hpp"

http::HTTPServer::HTTPServer(std::string address, int port) : Socket(address, port)
{

}

http::HTTPServer::HTTPServer(std::string address_and_port)
{
    auto colon = address_and_port.find(':');
    std::string address = "127.0.0.1";
    int port;
    if (std::string::npos == colon)
    {
        throw AddressListenException();
    }
    if (address_and_port.at(0) != ':')
    {
        address = address_and_port.substr(0, colon);
    }

    port = boost::lexical_cast<int>(address_and_port.substr(colon + 1));

    Socket::SetAddress(address, port);

}

http::HTTPServer::HTTPServer() : HTTPServer("127.0.0.1", 8000)
{

}

void http::HTTPServer::onListen(int backlog)
{
    TcpSocketServer::onListen(backlog);
}

void http::HTTPServer::onBind()
{
    TcpSocketServer::onBind();
}

void http::HTTPServer::onSetNonBlocking()
{
    TcpSocketServer::onSetNonBlocking();
}

void http::HTTPServer::onAccept()
{
    TcpSocketServer::onAccept();
}

void http::HTTPServer::AddQueue(int fd)
{
    fds.emplace(fd);
}

void http::HTTPServer::Run()
{

}
