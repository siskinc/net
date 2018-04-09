//
// Created by siskinc on 18-4-9.
//

#include "HTTPCookies.hpp"
#include <utility>

http::HTTPCookies::HTTPCookies()
        : HTTPCookies("")
{

}

http::HTTPCookies::HTTPCookies(std::string data)
{
    this->cookies = std::make_shared<std::map<std::string, HTTPCookie>>();
    InitData(std::move(data));
}

void http::HTTPCookies::InitData(std::string data)
{
    auto lines = String::explode<std::string>(' ', data, data.length());
    size_t equal_sign_index;
    for (auto &line:lines)
    {
        equal_sign_index = line.find_first_of('=');
        this->AddCookie(HTTPCookie(line.substr(0, equal_sign_index), line.substr(equal_sign_index + 1)));
    }
}

void http::HTTPCookies::AddCookie(std::string name, http::HTTPCookie httpCookie)
{
    this->cookies->insert(std::make_pair(std::move(name), std::move(httpCookie)));
}

void http::HTTPCookies::AddCookie(http::HTTPCookie httpCookie)
{
    std::string name = httpCookie.GetName();
    AddCookie(name, std::move(httpCookie));
}

void http::HTTPCookies::RemoveCookie(std::string name)
{
    this->cookies->erase(name);
}

http::HTTPCookie http::HTTPCookies::GetCookie(std::string name)
{
    auto it = this->cookies->find(name);
    if (it == this->cookies->end())
        return HTTPCookie();
    return this->cookies->at(name);
}

http::HTTPCookie http::HTTPCookies::get(std::string name)
{
    return GetCookie(std::move(name));
}

http::HTTPCookie http::HTTPCookies::operator[](std::string name)
{
    return GetCookie(std::move(name));
}
