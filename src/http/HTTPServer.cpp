//
// Created by siskinc on 18-4-9.
//

#include "HTTPServer.hpp"

http::HTTPServer::HTTPServer(std::string address, int port) : TcpSocketServer(address, port) {}

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

http::HTTPServer::HTTPServer() : HTTPServer("127.0.0.1", 8000) {}

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
    boost::function<void(int)> add_queue = boost::bind(&HTTPServer::AddQueue, this, boost::placeholders::_1);
    auto application = boost::bind(&HTTPServer::Application, this);
    auto run = boost::bind(&TcpSocketServer::Run, this, boost::placeholders::_1, boost::placeholders::_2);
    boost::thread runner(run, add_queue, DEFAULT_EVENTS);
    boost::thread applicationer(application);
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
    boost::function<void(HTTPContext &&, int)> handler_fun = boost::bind(&HTTPServer::Handle, this,
                                                                         boost::placeholders::_1,
                                                                         boost::placeholders::_2);
    while (true)
    {
        queue_mut.lock();
        if (!fds.empty())
        {
            std::string data;
            int fd = fds.front();
            fds.pop();
            onRead(fd, data);
            HTTPContext context(data);
            boost::thread handler(handler_fun, std::move(context), fd);
            handler.join();
        }
        queue_mut.unlock();
    }
}

void http::HTTPServer::Handle(http::HTTPContext &&context, int fd)
{
    const std::string &url = context.GetUrl();

}

void http::HTTPServer::InitHandlers()
{
    isInitHandlers = true;
}

bool http::HTTPServer::IsInitHandlers() const
{
    return isInitHandlers;
}
