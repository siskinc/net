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
#include <thread>
#include <mutex>
#include <boost/lexical_cast.hpp>

namespace http {

namespace {
const int BUFFER_LEN = 1024;
}

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

    void Application();

    void Handler(HTTPContext context, int fd);

protected:
    std::queue<int> fds;
    size_t maxWait;
    std::mutex fds_mutex;
public:
    size_t GetMaxWait() const;

    void SetMaxWait(size_t maxWait);

};

}


#endif //NET_HTTPSERVER_HPP
