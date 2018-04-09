//
// Created by siskinc on 18-4-9.
//

#include "HTTPHeaders.hpp"

http::HTTPHeaders::HTTPHeaders(std::map<std::string, std::string> &&headers)
{
    this->headers = headers;
}

std::vector<std::string> http::HTTPHeaders::GetHeaderNames()
{
    std::vector<std::string> names;
    if (!this->headers.empty())
    {
        auto end = this->headers.cend();
        for (auto item = this->headers.cbegin(); item != end; ++item)
        {
            names.emplace_back(item->first);
        }
    }
    return std::move(names);
}

std::string http::HTTPHeaders::GetHeader(std::string name)
{
    std::string value = "";
    auto item = this->headers.find(name);
    if (item != this->headers.end())
    {
        value = item->second;
    }
    return std::move(value);
}

std::string http::HTTPHeaders::get(std::string name, std::string defualt)
{
    auto item = this->headers.find(name);
    if (item != this->headers.end())
    {
        defualt = item->second;
    }
    return std::move(defualt);
}

std::string http::HTTPHeaders::operator[](std::string name)
{
    return GetHeader(std::move(name));
}

void http::HTTPHeaders::AddHeader(std::string name, std::string value)
{
    auto item = this->headers.find(name);
    if (item != this->headers.end())
    {
        this->headers[name] = value;
    } else
    {
        this->headers.insert(std::make_pair(name, value));
    }
}

void http::HTTPHeaders::SetHeader(std::string name, std::string value)
{
    AddHeader(std::move(name), std::move(value));
}

void http::HTTPHeaders::AddHeader(std::pair<std::string, std::string> &&header)
{
    auto item = this->headers.find(header.first);
    if (item != this->headers.end())
    {
        this->headers[header.first] = header.second;
    } else
    {
        this->headers.insert(std::move(header));
    }
}

void http::HTTPHeaders::operator=(std::map<std::string, std::string> &&headers)
{
    this->headers = headers;
}

void http::HTTPHeaders::operator=(const std::map<std::string, std::string> &&headers)
{
    this->headers = headers;
}

http::HTTPHeaders::HTTPHeaders(const std::map<std::string, std::string> &&headers)
{
    this->headers = headers;
}

http::HTTPHeaders::HTTPHeaders(const std::map<std::string, std::string> map)
{
    this->headers = headers;
}


