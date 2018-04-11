//
// Created by siskinc on 18-4-10.
//

#include "HTTPHandlers.hpp"

boost::function<void(http::HTTPContext &)> http::HTTPHandlers::GetHandle(const http::HTTPContext &context)
{
    return GetHandle(context.GetUrl());
}

boost::function<void(http::HTTPContext &)> http::HTTPHandlers::GetHandle(const std::string url)
{
    for(auto& item : handlers)
    {
        if(item.Match(url))
        {
            return item.GetHandle();
        }
    }

    // TODO return the 404 not found
    return boost::function<void(http::HTTPContext)>();
}
