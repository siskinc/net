//
// Created by siskinc on 18-4-9.
//

#ifndef NET_HTTPSESSION_HPP
#define NET_HTTPSESSION_HPP

#include <map>
#include <string>
#include <vector>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>

namespace http {

class HTTPSession
{
public:
    HTTPSession();

protected:
    std::map<std::string, void *> attributes;

    boost::uuids::uuid id;

public:
    const boost::uuids::uuid &GetId() const;

    void SetId(const boost::uuids::uuid &id);

public:

    /**
     * get point of the attribute,
     * if the attribute is not exist,
     * so the function will return a null point
     * @return
     */
    void *get(std::string name);

    void *GetAttribute(std::string name);

    void *operator[](std::string name) noexcept;

    /**
     * get the names of all attributes
     * @return
     */
    std::vector<std::string> GetAttributeNames();

    /**
     * remove the attribute,
     * whatever it is exist or not exist
     */
    void RemoveAttribute(std::string name);

    bool operator==(HTTPSession const &rhs) const
    {
        return id == rhs.id;
    }
};

}


#endif //NET_HTTPSESSION_HPP
