//
// Created by siskinc on 18-4-9.
//

#include "HTTPSession.hpp"

http::HTTPSession::HTTPSession()
{

}

const boost::uuids::uuid &http::HTTPSession::GetId() const
{
    return id;
}

void http::HTTPSession::SetId(const boost::uuids::uuid &id)
{
    HTTPSession::id = id;
}

void *http::HTTPSession::get(std::string name)
{
    auto it = this->attributes.find(name);
    if (it != this->attributes.end())
    {
        return it->second;
    }
    return nullptr;
}

void *http::HTTPSession::GetAttribute(std::string name)
{
    return this->get(name);
}

void *http::HTTPSession::operator[](std::string name) noexcept
{
    return this->get(name);
}

std::vector<std::string> http::HTTPSession::GetAttributeNames()
{
    std::vector<std::string> names;
    auto end = this->attributes.cend();
    for (auto it = this->attributes.cbegin(); it != end; ++it)
    {
        names.emplace_back(it->first);
    }
    return std::move(names);
}

void http::HTTPSession::RemoveAttribute(std::string name)
{
    this->attributes.erase(name);
}
