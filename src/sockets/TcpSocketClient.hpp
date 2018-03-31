//
// Created by siskinc on 18-3-28.
//

#ifndef NET_TCPSOCKETCLIENT_HPP
#define NET_TCPSOCKETCLIENT_HPP

#include "TcpSocket.hpp"

class TcpSocketClient : public TcpSocket
{
public:
    void onConnect();
};


#endif //NET_TCPSOCKETCLIENT_HPP
