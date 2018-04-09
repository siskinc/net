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
    maxWait = static_cast<size_t>(backlog);
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
    if (fds.size() <= maxWait)
        fds.emplace(fd);
    else
        close(fd);
}

void http::HTTPServer::Run()
{
    std::function<void(int)> add_queue = std::bind(&HTTPServer::AddQueue, *this);
    auto run = std::bind(&TcpSocketServer::Run, *this, add_queue);
    auto application = std::bind(&HTTPServer::Application, *this);
    std::thread runner(run);
    std::thread applicationer(application);
    runner.join();
    applicationer.join();

}

size_t http::HTTPServer::GetMaxWait() const
{
    return maxWait;
}

void http::HTTPServer::SetMaxWait(size_t maxWait)
{
    HTTPServer::maxWait = maxWait;
}

void http::HTTPServer::Application()
{
    auto handler_fun = std::bind(&HTTPServer::Handler, *this);
    while (true)
    {
        fds_mutex.lock();
        if (!fds.empty())
        {
            std::string data;
            int fd = fds.front();
            fds.pop();
            onRead(fd, data);
            HTTPContext context(data);
            std::thread handler(handler_fun, context, fd);
            handler.join();
        }
        fds_mutex.unlock();
    }
}

void http::HTTPServer::Handler(http::HTTPContext context, int fd)
{

}

