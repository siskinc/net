//
// Created by siskinc on 18-3-28.
//

#ifndef NET_TCPSOCKETSERVER_HPP
#define NET_TCPSOCKETSERVER_HPP

#include "TcpSocket.hpp"
#include <functional>

class TcpSocketServer : public TcpSocket
{
public:
    void onListen();
    void onBind();
    void onAccept();
    void Run(std::function<void (int)> callback);

private:
    sockaddr_in clientaddr_;
    std::vector<file_description> client_fds_;
};


#endif //NET_TCPSOCKETSERVER_HPP
