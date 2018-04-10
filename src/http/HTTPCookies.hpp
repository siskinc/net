//
// Created by siskinc on 18-4-9.
//

#ifndef NET_HTTPCOOKIES_HPP
#define NET_HTTPCOOKIES_HPP

#include "HTTPCookie.hpp"
#include "../utils/String.hpp"

namespace http {

class HTTPCookies
{
public:
    HTTPCookies();

    explicit HTTPCookies(std::string data);

    void InitData(std::string data);


protected:
    std::shared_ptr<std::map<std::string, HTTPCookie>> cookies;

public:
    void AddCookie(std::string name, HTTPCookie httpCookie);

    void AddCookie(HTTPCookie httpCookie);

    void RemoveCookie(std::string name);

    HTTPCookie GetCookie(std::string name);

    HTTPCookie get(std::string name);

    HTTPCookie operator[](std::string name);
};

}

#endif //NET_HTTPCOOKIES_HPP
