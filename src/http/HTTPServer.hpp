//
// Created by siskinc on 18-4-9.
//

#ifndef NET_HTTPSERVER_HPP
#define NET_HTTPSERVER_HPP

#include "../sockets/TcpSocketServer.hpp"
#include "../sockets/AddressListenException.hpp"
#include "HTTPContext.hpp"
#include <queue>
#include <functional>
#include <boost/lexical_cast.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>

namespace http {

namespace {
const int BUFFER_LEN = 1024;
}

class HTTPServer : public TcpSocketServer
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

    void Application();

    void Handle(HTTPContext &&context, int fd);

protected:
    typedef std::map<std::string, std::function<void(HTTPContext)>> HandleFuns;
    typedef std::map<std::string, HandleFuns> Handlers;
    std::queue<int> fds;
    size_t maxWait;
    Handlers handlers;
    bool isInitHandlers = false;
    boost::mutex queue_mut;
protected:
    void InitHandlers();

public:
    const Handlers &GetHandlers() const;

    bool IsInitHandlers() const;

    size_t GetMaxWait() const;

    void SetMaxWait(size_t maxWait);
};

}


#endif //NET_HTTPSERVER_HPP
