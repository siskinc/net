//
// Created by siskinc on 18-4-9.
//

#ifndef NET_HTTPREQUEST_HPP
#define NET_HTTPREQUEST_HPP

#include "HTTPParser.hpp"
#include "HTTPCookie.hpp"
#include "HTTPCookies.hpp"
#include "HTTPHeaders.hpp"
#include <memory>

namespace http {

class HTTPContext
{
public:
    HTTPContext();

    explicit HTTPContext(std::string data);

    void InitData(std::string data);


protected:
    HTTPCode code;
    std::string method;
    std::string url;
    HTTPVersion HTTPVersion_;
    HTTPCookies cookies;
    HTTPSession sessons;
    std::map<std::string, std::string> headers;
    bool inited;
public:
    HTTPCode GetCode() const;

    const std::string &GetMethod() const;

    const std::string &GetUrl() const;

    HTTPVersion GetHTTPVersion_() const;

    bool IsInited() const;
};

}


#endif //NET_HTTPREQUEST_HPP
