//
// Created by siskinc on 18-4-9.
//

#ifndef NET_HTTPREQUEST_HPP
#define NET_HTTPREQUEST_HPP

#include "HTTPParser.hpp"
#include "HTTPCookie.hpp"
#include "HTTPCookies.hpp"
#include "HTTPHeaders.hpp"
#include "HTTPVersion.hpp"
#include "../parser/json11/json11.hpp"
#include <memory>
#include <fstream>

namespace http {

class HTTPContext
{
public:
    HTTPContext();

    explicit HTTPContext(std::string data);

    void InitData(std::string data);

    void JSON(json11::Json &json, HTTPCode code = OK);

    void render(std::string html, HTTPCode code = OK);

    void String(std::string ret, HTTPCode code = OK);

    const std::string ToString() const;


protected:
    HTTPCode code;
    std::string method;
    std::string url;
    HTTPVersion HTTPVersion_;
    HTTPCookies cookies;
    HTTPSession sessons;
    HTTPHeaders headers;
    std::string body;
    std::string response_body;
    bool inited;

public:
    HTTPCode GetCode() const;

    const std::string &GetMethod() const;

    const std::string &GetUrl() const;

    HTTPVersion GetHTTPVersion() const;

    bool IsInited() const;

    const HTTPCookies &GetCookies() const;

    const HTTPSession &GetSessons() const;

    const HTTPHeaders &GetHeaders() const;

    const std::string &GetBody() const;

    const std::string &GetResponse_body() const;

    std::string GetHeadersString() const;
};

}


#endif //NET_HTTPREQUEST_HPP
