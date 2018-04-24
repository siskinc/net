//
// Created by siskinc on 18-4-10.
//

#include "HTTPHandler.hpp"
#include <utility>

http::HTTPHandler::HTTPHandler(boost::function<void(http::HTTPContext *)> handle,
                               boost::container::vector<http::HTTPMethods> methods,
                               std::string relativePath) : handle(std::move(handle)), methods(std::move(methods)),
                                                           relativePath(std::move(relativePath)) {}

const boost::function<void(http::HTTPContext *)> &http::HTTPHandler::GetHandle() const
{
    return handle;
}

void http::HTTPHandler::SetHandle(const boost::function<void(http::HTTPContext *)> &handle)
{
    HTTPHandler::handle = handle;
}

const std::string &http::HTTPHandler::GetRelativePath() const
{
    return relativePath;
}

void http::HTTPHandler::SetRelativePath(const std::string &relativePath)
{
    HTTPHandler::relativePath = relativePath;
}

bool http::HTTPHandler::Match(std::string url)
{
    auto res = std::mismatch(relativePath.begin(), relativePath.end(), url.begin());
    return res.first == relativePath.end();
}


