//
// Created by siskinc on 18-4-10.
//

#include "HTTPHandlers.hpp"
namespace http {
    std::string http::HTTPHandlers::filename404("");
    void NotFound404(http::HTTPContext *context)
    {
        context->NotFound404(http::HTTPHandlers::GetFilename404());
    }
    boost::function<void(http::HTTPContext *context)> not_found_handler = boost::bind(NotFound404, boost::placeholders::_1);
}
boost::function<void(http::HTTPContext *)> http::HTTPHandlers::GetHandle(const http::HTTPContext &context)
{
    return GetHandle(context.GetUrl());
}

boost::function<void(http::HTTPContext *)> http::HTTPHandlers::GetHandle(const std::string url)
{
    for (auto &item : handlers)
    {
        if (item.Match(url))
        {
            LOG(INFO) << "找到了";
            return item.GetHandle();
        }
    }

    return not_found_handler;
}

const std::string &http::HTTPHandlers::GetFilename404()
{
    return filename404;
}

void http::HTTPHandlers::SetFilename404(const std::string &filename404)
{
    HTTPHandlers::filename404 = filename404;
}
