//
// Created by siskinc on 18-4-10.
//

#include "HTTPHandler.hpp"

http::HTTPHandler::HTTPHandler(const boost::function<void(http::HTTPContext)> &handle, const std::string &relativePath)
        : handle(handle), relativePath(relativePath) {}

const boost::function<void(http::HTTPContext)> &http::HTTPHandler::GetHandle() const
{
    return handle;
}

void http::HTTPHandler::SetHandle(const boost::function<void(http::HTTPContext)> &handle)
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
    auto res = std::mismatch(url.begin(), url.end(), relativePath.begin());
    return res.first == url.end();
}
