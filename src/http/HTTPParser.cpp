//
// Created by siskinc on 18-4-3.
//

#include "HTTPParser.hpp"

http::HTTPCode http::HTTPParser::GetCode() const
{
    return code;
}

void http::HTTPParser::SetCode(http::HTTPCode code)
{
    http::HTTPParser::code = code;
}

const std::string &http::HTTPParser::GetMethod() const
{
    return method;
}

void http::HTTPParser::SetMethod(const std::string &method)
{
    HTTPParser::method = method;
}

const std::string &http::HTTPParser::GetUrl() const
{
    return url;
}

void http::HTTPParser::SetUrl(const std::string &url)
{
    HTTPParser::url = url;
}

http::HTTPVersion http::HTTPParser::GetHTTPVersion() const
{
    return HTTPVersion_;
}

void http::HTTPParser::SetHTTPVersion(HTTPVersion HTTPVersion)
{
    HTTPParser::HTTPVersion_ = HTTPVersion;
}

const std::map<std::string, std::string> &http::HTTPParser::GetHeaders() const
{
    return headers;
}

void http::HTTPParser::SetHeaders(const std::map<std::string, std::string> &headers)
{
    HTTPParser::headers = headers;
}

const std::string &http::HTTPParser::GetBody() const
{
    return body;
}

void http::HTTPParser::SetBody(const std::string &body)
{
    HTTPParser::body = body;
}

void http::HTTPParser::InitData(const std::string &data)
{
    size_t start = 0;
    size_t front = start;
    size_t colon = 0;
    std::string line;

    // handle the first line
    start = data.find("\r\n", start);
    line = data.substr(0, start);
    ++start;
    std::vector<std::string> vec;
    boost::algorithm::split(vec, line, boost::is_any_of(" "));
    this->method = vec[0];
    this->url = vec[1];
    this->HTTPVersion_ = http_version::GetHTTPVersion(vec[2]);
    while ((start = data.find("\r\n", start)))
    {
        LOG(INFO) << "循环" << "\nstart : " << start << " npos : " << std::string::npos << " " << (start == std::string::npos);
        if (start == front + 2)
            break;
        if (start == std::string::npos)
        {
            LOG(INFO) << "退出循环";
            break;
        }
        line = data.substr(front + 2, start - (front + 2));
        colon = line.find(':');
        headers[line.substr(0, colon)] = line.substr(colon + 2);
        front = start;
        start += 2;
    }
    this->body = data.substr(front + 4);

}

http::HTTPParser::HTTPParser(const std::string &data)
{
    try
    {
        InitData(data);
    } catch (HTTPHeaderException &e)
    {
        LOG(FATAL) << e.what();
    }
}