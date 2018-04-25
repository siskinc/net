//
// Created by siskinc on 18-4-9.
//

#ifndef NET_HTTPSERVER_HPP
#define NET_HTTPSERVER_HPP

#include "../sockets/TcpSocketServer.hpp"
#include "../sockets/AddressListenException.hpp"
#include "HTTPHandlers.hpp"
#include "HTTPContext.hpp"
#include "HTTPMethods.hpp"
#include <queue>
#include <functional>
#include <boost/lexical_cast.hpp>
#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <glog/logging.h>
#include <utility>

namespace http {

namespace {
const int BUFFER_LEN = 1024;

void NotFound404(std::string filename, HTTPContext *context)
{
    context->NotFound404(std::move(filename));
}

}

class HTTPServer : public TcpSocketServer
{
public:
    HTTPServer();

    HTTPServer(std::string address, int port);

    explicit HTTPServer(std::string address_and_port);

    void Run();

    void onListen(int backlog = 128) override;

    void onBind() override;

    void onSetNonBlocking() override;

    void onAccept() override;

    void onWrite(file_description fd, const HTTPContext &context);

    void AddQueue(int fd);

    void Application();

    void Handle(HTTPContext &context, int fd);

    size_t GetMaxWait() const;

    void SetMaxWait(size_t maxWait);

    void SetNotFoundTemplateFilename(std::string filename);

    template<HTTPMethods ... args>
    inline void SetHandler(boost::function<void(HTTPContext *)> handler, std::string relativePath)
    {
        handlers.SetHandler<args...>(handler, relativePath);
    }

    inline void GET(boost::function<void(HTTPContext *)> handler, std::string relativePath)
    {
        handlers.SetHandler<HTTPMethods::GET>(std::move(handler), std::move(relativePath));
    }

    inline void POST(boost::function<void(HTTPContext *)> handler, std::string relativePath)
    {
        handlers.SetHandler<HTTPMethods::POST>(std::move(handler), std::move(relativePath));
    }

    inline void HEAD(boost::function<void(HTTPContext *)> handler, std::string relativePath)
    {
        handlers.SetHandler<HTTPMethods::HEAD>(std::move(handler), std::move(relativePath));
    }

    inline void OPTIONS(boost::function<void(HTTPContext *)> handler, std::string relativePath)
    {
        handlers.SetHandler<HTTPMethods::OPTIONS>(std::move(handler), std::move(relativePath));
    }

    inline void PUT(boost::function<void(HTTPContext *)> handler, std::string relativePath)
    {
        handlers.SetHandler<HTTPMethods::PUT>(std::move(handler), std::move(relativePath));
    }

    inline void DELETE(boost::function<void(HTTPContext *)> handler, std::string relativePath)
    {
        handlers.SetHandler<HTTPMethods::DELETE>(std::move(handler), std::move(relativePath));
    }

    inline void TRACE(boost::function<void(HTTPContext *)> handler, std::string relativePath)
    {
        handlers.SetHandler<HTTPMethods::TRACE>(std::move(handler), std::move(relativePath));
    }

    inline void CONNECT(boost::function<void(HTTPContext *)> handler, std::string relativePath)
    {
        handlers.SetHandler<HTTPMethods::CONNECT>(std::move(handler), std::move(relativePath));
    }

private:
    std::queue<int> fds;
    size_t maxWait;
    boost::mutex queue_mut;
    HTTPHandlers handlers{};
    std::string NotFoundTemplateFilename;
};

}


#endif //NET_HTTPSERVER_HPP
