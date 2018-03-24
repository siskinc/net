//
// Created by siskinc on 18-3-22.
//

#ifndef NET_ADDRESS_HPP
#define NET_ADDRESS_HPP

#include <string>
#include <iostream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "util.hpp"

class Address
{
public:
    typedef std::vector<std::string> split_vector_string_type;
    Address(const std::string &address = ":8000");
    void port(int port);
    int port();
    const int port() const;
    void address(const std::string &address);
    std::string address();
    const std::string address() const;
private:
    void isNotAddress();
    int port_;
    std::string address_;
};


#endif //NET_ADDRESS_HPP
