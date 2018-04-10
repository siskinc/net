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
    void AddHandler(boost::function<void(HTTPContext)> handler)
    {

    }
private:
    boost::container::vector<HTTPHandler> handlers;
};

}


#endif //NET_HTTPHANDLERS_HPP
