//
// Created by siskinc on 18-4-9.
//

#ifndef NET_HTTPREQUEST_HPP
#define NET_HTTPREQUEST_HPP

#include "HTTPParser.hpp"

namespace http {

class HTTPRequest
{
public:
    HTTPRequest();

    HTTPRequest(std::string data);

protected:
    std::map<std::string, std::void_t> Session;
    std::map<std::string, std::void_t> POST;
    std::map<std::string, std::void_t> GET;
    std::map<std::string, std::void_t> Cookie;
};

}


#endif //NET_HTTPREQUEST_HPP
