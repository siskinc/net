#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/container/vector.hpp>
#include <boost/function.hpp>
#include "src/http/HTTPServer.hpp"

int main(int argc,char** argv)
{
    http::HTTPServer server;
    server.onBind();
    server.onListen();
    server.Run();
    return 0;
}