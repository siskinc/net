//
// Created by siskinc on 18-4-9.
//

#ifndef NET_HTTPSESSION_HPP
#define NET_HTTPSESSION_HPP

#include <map>
#include <string>
#include <vector>

namespace http {

class HTTPSession
{
public:
    HTTPSession();

protected:
    std::map<std::string, void *> attributes;

public:
    void *GetAttribute(std::string name);

    std::vector<std::string> GetAttributeNames();

    void *operator[](std::string name) noexcept;

    void RemoveAttribute(std::string);

protected:

};

}


#endif //NET_HTTPSESSION_HPP
