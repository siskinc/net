//
// Created by siskinc on 18-4-9.
//

#include "HTTPContext.hpp"
#include <utility>

namespace http {
std::string GetFileContext(const std::string &filename)
{
    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error! Incorrect file."
                  << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string contents{std::istream_iterator<char>(file), std::istream_iterator<char>()};
    return contents;
}
}

http::HTTPContext::HTTPContext(std::string data)
{
    InitData(std::move(data));
}

void http::HTTPContext::InitData(std::string data)
{
    this->inited = true;
    LOG(INFO) << "Parse 开始";
    HTTPParser parser(data);
    LOG(INFO) << "Parse 完成";
    this->code = parser.GetCode();
    this->method = parser.GetMethod();
    this->url = parser.GetUrl();
    this->HTTPVersion_ = parser.GetHTTPVersion();
    this->headers = parser.GetHeaders();
    this->cookies = HTTPCookies(this->headers.get("Cookie"));
    this->body = parser.GetBody();
}

http::HTTPContext::HTTPContext()
{
    this->inited = false;
}

http::HTTPCode http::HTTPContext::GetCode() const
{
    return code;
}

const std::string &http::HTTPContext::GetMethod() const
{
    return method;
}

const std::string &http::HTTPContext::GetUrl() const
{
    return url;
}

http::HTTPVersion http::HTTPContext::GetHTTPVersion() const
{
    return HTTPVersion_;
}

bool http::HTTPContext::IsInited() const
{
    return inited;
}

const http::HTTPCookies &http::HTTPContext::GetCookies() const
{
    return cookies;
}

const http::HTTPHeaders &http::HTTPContext::GetHeaders() const
{
    return headers;
}

const http::HTTPSession &http::HTTPContext::GetSessions() const
{
    return sessions;
}

const std::string &http::HTTPContext::GetResponse_body() const
{
    return response_body;
}

const std::string &http::HTTPContext::GetBody() const
{
    return body;
}

std::string http::HTTPContext::GetHeadersString() const
{
    return std::__cxx11::string();
}

void http::HTTPContext::JSON(json11::Json &json, http::HTTPCode code)
{
    response_body.clear();
    this->code = code;
//    std::string http_version = http_version::HTTPVersion2Str(GetHTTPVersion());
//    const std::string &http_code_description = GetHTTPCodeDescription(code);
//    const std::string &headers_string = GetHeadersString();
    std::string json_str;
    json.dump(json_str);
    response_body = json_str;
}

void http::HTTPContext::String(std::string ret, http::HTTPCode code)
{
    response_body.clear();
    this->code = code;
    LOG(INFO) << this->code;
    response_body = std::move(ret);
}

void http::HTTPContext::render(http::HTTPCode code, const std::string &html)
{
    response_body.clear();
    this->code = code;
    response_body = GetFileContext(html);
}

const std::string http::HTTPContext::ToString() const
{
    LOG(INFO) << "开始ToString()";
    LOG(INFO)<<http_version::HTTPVersion2Str(this->GetHTTPVersion());
    LOG(INFO)<<std::to_string(this->code);
    LOG(INFO)<<GetHTTPCodeDescription(this->code);
    LOG(INFO)<<GetHeaders().ToString();
    std::string data = http_version::HTTPVersion2Str(this->GetHTTPVersion()) + " " + std::to_string(this->code) + " " +
                       GetHTTPCodeDescription(this->code) + "\r\n" + GetHeaders().ToString() + "\r\n" +
                       response_body;
    LOG(INFO) << "结束ToString()";
    return data;
}

void http::HTTPContext::NotFound404(std::string filename)
{
    response_body.clear();
    if (filename.empty())
    {
        return;
    }
    this->code = code;
    response_body = GetFileContext(filename);
}

void http::HTTPContext::HTTPInternalServerError500(std::string filename)
{
    response_body.clear();
    if (filename.empty())
    {
        return;
    }
    this->code = code;
    response_body = GetFileContext(filename);
}

