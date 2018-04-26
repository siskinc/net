//
// Created by siskinc on 18-4-9.
//

#include "HTTPServer.hpp"


http::HTTPServer::HTTPServer(std::string address, int port) : TcpSocketServer(address, port)
{
    LOG(INFO) << "Run Server http://" << address << ":" << port;
}

http::HTTPServer::HTTPServer(std::string address_and_port)
{
    auto colon = address_and_port.find(':');
    std::string address = "127.0.0.1";
    int port;
    if (std::string::npos == colon)
    {
        LOG(ERROR) << "HTTPServer(std::string address_and_port): parameter address_and_port is error,\n"
                   << "and you should write like 127.0.0.1:8000 or :8000";
        throw AddressListenException();
    }
    if (address_and_port.at(0) != ':')
    {
        address = address_and_port.substr(0, colon);
    }

    port = boost::lexical_cast<int>(address_and_port.substr(colon + 1));
    LOG(INFO) << "Run Server http://" << address << ":" << port;
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
    queue_mut.lock();
    if (fds.size() <= maxWait)
    {
        fds.emplace(fd);
        LOG(INFO) << "add fd " << fd << " in queue";
        LOG(INFO) << "fds size : " << fds.size();
    } else
    {
        close(fd);
    }
    queue_mut.unlock();
}

void http::HTTPServer::Run()
{
    boost::function<void(int)> add_queue = boost::bind(&HTTPServer::AddQueue, this, boost::placeholders::_1);
    auto run = boost::bind(&TcpSocketServer::Run, this, boost::placeholders::_1, boost::placeholders::_2);
    auto application = boost::bind(&HTTPServer::Application, this);
    boost::thread applicationer(application);
    applicationer.detach();
    run(add_queue, DEFAULT_EVENTS);

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
    LOG(INFO) << "Running in Application function";
    boost::function<void(HTTPContext &, int)> handler_fun = boost::bind(&HTTPServer::Handle, this,
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
            TcpSocketServer::onRead(fd, data);
            LOG(INFO) << "\ndata:\n" << data;
            HTTPContext context(data);
            handler_fun(context, fd);
        }
        queue_mut.unlock();
    }
}

void http::HTTPServer::Handle(HTTPContext &context, int fd)
{
    LOG(INFO) << "Handler 开始";
    {
        //TODO middle wares handle
    }
    boost::function<void(HTTPContext *)> handle;
    handle = handlers.GetHandle(context);
    try
    {
        LOG(INFO) << "执行handler";
        handle(&context);
        LOG(INFO) << "执行handler完毕";
    }
    catch (std::exception &e)
    {
        // TODO 500 handle
    }
    LOG(INFO) << "开始onWrite()";
    onWrite(fd, context);
    LOG(INFO) << "结束onWrite()";
    close(fd);
}

void http::HTTPServer::onWrite(file_description fd, const http::HTTPContext &context)
{
    std::string data(context.ToString());
    LOG(INFO) << "开始TcpSocketServer::onWrite()";
    TcpSocketServer::onWrite(fd, data);
    LOG(INFO) << "结束TcpSocketServer::onWrite()";
}

void http::HTTPServer::SetNotFoundTemplateFilename(std::string filename)
{
    this->NotFoundTemplateFilename = std::move(filename);
}
