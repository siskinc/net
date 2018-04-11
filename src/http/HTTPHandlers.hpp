//
// Created by siskinc on 18-4-10.
//

#ifndef NET_HTTPHANDLERS_HPP
#define NET_HTTPHANDLERS_HPP

#include "HTTPHandler.hpp"
#include <boost/container/vector.hpp>

namespace http {

class HTTPHandlers {
public:
    HTTPHandlers() = default;
    template <HTTPMethods ... args>
    void SetHandler(boost::function<void(HTTPContext &)> handler, std::string relativePath)
    {
        boost::container::vector<HTTPMethods > methods{args...};
        handlers.emplace_back(handler, std::move(methods), std::move(relativePath));
    }

    boost::function<void(HTTPContext &)> GetHandle(const std::string url);

    boost::function<void(HTTPContext &)> GetHandle(const HTTPContext &context);
private:
    boost::container::vector<HTTPHandler> handlers;
};

}


#endif //NET_HTTPHANDLERS_HPP
