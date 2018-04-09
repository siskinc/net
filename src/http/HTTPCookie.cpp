//
// Created by siskinc on 18-4-9.
//

#include "HTTPCookie.hpp"
#include <utility>

http::HTTPCookie::HTTPCookie(std::string name, std::string value)
{
    this->name = std::move(name);
    this->value = std::move(value);
    this->domain = "/";
    this->maxAge = 30 * 60;
    this->version = 0;
    this->httpOnly = false;
    this->secure = false;
}

const std::string &http::HTTPCookie::GetName() const
{
    return name;
}

void http::HTTPCookie::SetName(const std::string &name)
{
    HTTPCookie::name = name;
}

const std::string &http::HTTPCookie::GetValue() const
{
    return value;
}

void http::HTTPCookie::SetValue(const std::string &value)
{
    HTTPCookie::value = value;
}

const std::string &http::HTTPCookie::GetDomain() const
{
    return domain;
}

void http::HTTPCookie::SetDomain(const std::string &domain)
{
    HTTPCookie::domain = domain;
}

int http::HTTPCookie::GetMaxAge() const
{
    return maxAge;
}

void http::HTTPCookie::SetMaxAge(int maxAge)
{
    HTTPCookie::maxAge = maxAge;
}

const std::string &http::HTTPCookie::GetPath() const
{
    return path;
}

void http::HTTPCookie::SetPath(const std::string &path)
{
    HTTPCookie::path = path;
}

bool http::HTTPCookie::IsSecure() const
{
    return secure;
}

void http::HTTPCookie::SetSecure(bool secure)
{
    HTTPCookie::secure = secure;
}

int http::HTTPCookie::GetVersion() const
{
    return version;
}

void http::HTTPCookie::SetVersion(int version)
{
    HTTPCookie::version = version;
}

bool http::HTTPCookie::IsHttpOnly() const
{
    return httpOnly;
}

void http::HTTPCookie::SetHttpOnly(bool httpOnly)
{
    HTTPCookie::httpOnly = httpOnly;
}

const std::string &http::HTTPCookie::GetPurpose() const
{
    return purpose;
}

void http::HTTPCookie::SetPurpose(const std::string &purpose)
{
    HTTPCookie::purpose = purpose;
}


