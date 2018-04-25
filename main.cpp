#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/container/vector.hpp>
#include <boost/function.hpp>
#include "src/http/HTTPServer.hpp"

int main(int argc,char** argv)
{
    http::HTTPServer server;
    server.GET([](http::HTTPContext *context){
        context->String("Hello World!", static_cast<http::HTTPCode>(200));
        }, "/");
    server.onBind();
    server.onListen();
    server.Run();
    return 0;
}