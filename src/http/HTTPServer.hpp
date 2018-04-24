//
// Created by siskinc on 18-4-9.
//

#ifndef NET_HTTPSERVER_HPP
#define NET_HTTPSERVER_HPP

#include "../sockets/TcpSocketServer.hpp"
#include "../sockets/AddressListenException.hpp"
#include "HTTPHandlers.hpp"
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

    void Handle(HTTPContext *context, int fd);

    size_t GetMaxWait() const;

    void SetMaxWait(size_t maxWait);

protected:
    void onRead(file_description fd, const HTTPContext &context);

    std::queue<int> fds;
    size_t maxWait;
    boost::mutex queue_mut;
    HTTPHandlers handlers{};
};

}


#endif //NET_HTTPSERVER_HPP
