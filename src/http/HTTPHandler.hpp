//
// Created by siskinc on 18-4-10.
//

#ifndef NET_HTTPHANDLER_HPP
#define NET_HTTPHANDLER_HPP


#include "HTTPContext.hpp"
#include "HTTPMethods.hpp"
#include <boost/function.hpp>
#include <boost/container/vector.hpp>

namespace http {

class HTTPHandler
{
public:
    HTTPHandler(boost::function<void(HTTPContext *)> handle, boost::container::vector<HTTPMethods> methods,
                std::string relativePath);

private:
    boost::function<void(HTTPContext *)> handle;
    boost::container::vector<HTTPMethods> methods;
    std::string relativePath;
public:
    const boost::function<void(HTTPContext *)> &GetHandle() const;

    void SetHandle(const boost::function<void(HTTPContext *)> &handle);

    const std::string &GetRelativePath() const;

    void SetRelativePath(const std::string &relativePath);

    bool Match(std::string url);
};

}

#endif //NET_HTTPHANDLER_HPP
