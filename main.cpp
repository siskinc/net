#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/container/vector.hpp>
#include <boost/function.hpp>
#include "src/http/HTTPServer.hpp"

int main(int argc,char** argv)
{
    http::HTTPServer server("127.0.0.1:8001");
    server.GET([](http::HTTPContext *context){
        context->String("Hello World!", static_cast<http::HTTPCode>(200));
        }, "/1");
    server.onSetNonBlocking();
    server.onBind();
    server.onListen();
    server.Run();
    http::GetHTTPCodeDescription(static_cast<http::HTTPCode>(200));
    return 0;
}