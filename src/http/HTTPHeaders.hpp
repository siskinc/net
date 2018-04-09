//
// Created by siskinc on 18-4-9.
//

#ifndef NET_HTTPHEADERS_HPP
#define NET_HTTPHEADERS_HPP

#include <string>
#include <map>
#include <vector>

namespace http {

class HTTPHeaders
{
public:
    HTTPHeaders() = default;

    explicit HTTPHeaders(std::map<std::string, std::string> &&headers);

    HTTPHeaders(const std::map<std::string, std::string> &&headers);

    HTTPHeaders(const std::map<std::string, std::string> map);

    void operator=(std::map<std::string, std::string> &&headers);

    void operator=(const std::map<std::string, std::string> &&headers);

protected:
    std::map<std::string, std::string> headers;

public:
    std::vector<std::string> GetHeaderNames();

    std::string GetHeader(std::string name);

    std::string get(std::string name, std::string defualt = "");

    std::string operator[](std::string name);

    void AddHeader(std::string name, std::string value);

    void SetHeader(std::string name, std::string value);

    void AddHeader(std::pair<std::string, std::string> &&header);

};

}


#endif //NET_HTTPHEADERS_HPP
