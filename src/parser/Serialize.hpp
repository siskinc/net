//
// Created by siskinc on 18-4-11.
//

#ifndef NET_SERIALIZE_HPP
#define NET_SERIALIZE_HPP

namespace parser{

#include <string>

class Serialize
{
    virtual std::string dump() const = 0;
};

}

#endif //NET_SERIALIZE_HPP
