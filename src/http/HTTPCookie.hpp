//
// Created by siskinc on 18-4-9.
//

#ifndef NET_COOKIE_HPP
#define NET_COOKIE_HPP

#include <ostream>
#include "HTTPSession.hpp"

namespace http {

class HTTPCookie
{
public:

    HTTPCookie() = default;

    HTTPCookie(std::string name, std::string value);

public:

protected:
    std::string name;
    std::string value;
    std::string domain;
    int maxAge;
    std::string path;
    bool secure;
    int version;
    bool httpOnly;
    std::string purpose;
public:
    const std::string &GetPurpose() const;

    void SetPurpose(const std::string &purpose);

public:
    bool IsHttpOnly() const;

    void SetHttpOnly(bool httpOnly);

public:
    const std::string &GetName() const;

    void SetName(const std::string &name);

    const std::string &GetValue() const;

    void SetValue(const std::string &value);

    const std::string &GetDomain() const;

    void SetDomain(const std::string &domain);

    int GetMaxAge() const;

    void SetMaxAge(int maxAge);

    const std::string &GetPath() const;

    void SetPath(const std::string &path);

    bool IsSecure() const;

    void SetSecure(bool secure);

    int GetVersion() const;

    void SetVersion(int version);
};

}

#endif //NET_COOKIE_HPP
