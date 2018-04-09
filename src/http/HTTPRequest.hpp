//
// Created by siskinc on 18-4-9.
//

#ifndef NET_HTTPREQUEST_HPP
#define NET_HTTPREQUEST_HPP

#include "HTTPParser.hpp"
#include "HTTPCookie.hpp"
#include <memory>

namespace http {

class HTTPRequest
{
public:
    HTTPRequest();

    HTTPRequest(std::string data);

protected:
    HTTPCode code;
    std::string method;
    std::string url;
    HTTPVersion HTTPVersion_;
};

}


#endif //NET_HTTPREQUEST_HPP
