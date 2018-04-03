//
// Created by siskinc on 18-4-3.
//

#ifndef NET_HTTPPARSER_HPP
#define NET_HTTPPARSER_HPP

#include <sstream>
#include <string>
#include <map>

#include "HTTPCode.hpp"
#include "HTTPVersion.hpp"

#include <fmt>

class HTTPParser
{
public:
    HTTPParser();

    HTTPParser(const std::string &data);

    HTTPParser(const std::stringstream &data);

private:
    HTTPCode code;
    std::string method;
    std::string url;
    HTTPVersion HTTPVersion_;
    std::map<std::string, std::string> headers;
    std::string body;
public:
    void InitData(const std::string &data);

    void InitData(const std::stringstream &data);

    HTTPCode GetCode() const;

    void SetCode(HTTPCode code);

    const std::string &GetMethod() const;

    void SetMethod(const std::string &method);

    const std::string &GetUrl() const;

    void SetUrl(const std::string &url);

    HTTPVersion GetHTTPVersion() const;

    void SetHTTPVersion(HTTPVersion HTTPVersion);

    const std::map<std::string, std::string> &GetHeaders() const;

    void SetHeaders(const std::map<std::string, std::string> &headers);

    const std::string &GetBody() const;

    void SetBody(const std::string &body);

};


#endif //NET_HTTPPARSER_HPP
