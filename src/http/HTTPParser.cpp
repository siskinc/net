//
// Created by siskinc on 18-4-3.
//

#include "HTTPParser.hpp"

HTTPCode HTTPParser::GetCode() const
{
    return code;
}

void HTTPParser::SetCode(HTTPCode code)
{
    HTTPParser::code = code;
}

const std::string &HTTPParser::GetMethod() const
{
    return method;
}

void HTTPParser::SetMethod(const std::string &method)
{
    HTTPParser::method = method;
}

const std::string &HTTPParser::GetUrl() const
{
    return url;
}

void HTTPParser::SetUrl(const std::string &url)
{
    HTTPParser::url = url;
}

HTTPVersion HTTPParser::GetHTTPVersion() const
{
    return HTTPVersion_;
}

void HTTPParser::SetHTTPVersion(HTTPVersion HTTPVersion)
{
    HTTPParser::HTTPVersion_ = HTTPVersion;
}

const std::map<std::string, std::string> &HTTPParser::GetHeaders() const
{
    return headers;
}

void HTTPParser::SetHeaders(const std::map<std::string, std::string> &headers)
{
    HTTPParser::headers = headers;
}

const std::string &HTTPParser::GetBody() const
{
    return body;
}

void HTTPParser::SetBody(const std::string &body)
{
    HTTPParser::body = body;
}

void HTTPParser::InitData(const std::string &data)
{
    std::stringstream ss(data);
    std::string http_version;
    ss >> this->method
       >> this->url
       >> http_version;
    if(http_version == "HTTP/1.1")
        this->HTTPVersion_ = HTTP1_1;
    else if(http_version == "HTTP/1.0")
        this->HTTPVersion_ = HTTP1_0;
    else{
        //TODO

    }
}
