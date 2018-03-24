//
// Created by siskinc on 18-3-22.
//

#include "Address.hpp"

Address::Address(const std::string &address)
{
    // parse like such as ":8000"
    if(address[0] == ':')
    {
        try
        {
            port_ = boost::lexical_cast<int>(address.substr(1));
        } catch (std::exception &e) {
            isNotAddress();
        }
        return;
    }

    // parse such as "127.0.0.1:8000"

    // check the address string have only one ":"

    int colon_count = 0;
    for(auto &i : address)
    {
        if(i == ':')
        {
            ++colon_count;
        }
    }

    // if the number of colon less than 1 or more than 2
    // we think it is a invalid address string
    if(colon_count < 1)
    {
        isNotAddress();
    }
    else if(colon_count > 1)
    {
        isNotAddress();
    }

    auto colon = address.find(':');
    if(colon == std::string::npos)
    {
        isNotAddress();
    }
    if(!util::IsIpv4(address.substr(0, colon)))
    {
        isNotAddress();
    }
    // save the split string function's result
    split_vector_string_type split_strings;

    boost::algorithm::split(split_strings, address, boost::is_any_of(":"), boost::algorithm::token_compress_on);

    auto size = split_strings.size();

    // if the size not equal 2
    // so the address must invalid
    // although above up had check the number of colon

    if(size != 2)
    {
        isNotAddress();
    }

    // judge the front of colon string is a valid ipv4 string
    if(!util::IsIpv4(split_strings[0]))
    {
        isNotAddress();
    }

    // judge the string that behand the colon is a number
    if(!util::IsNum(split_strings[1]))
    {
        isNotAddress();
    }
    address_ = split_strings[0];
    port_ = boost::lexical_cast<int>(split_strings[1]);
}

void Address::isNotAddress()
{
    std::cerr << "Please input valid address(example   \":8000\" )" << std::endl;
    exit(EXIT_FAILURE);
}

void Address::port(int port)
{
    port_ = port;
}

int Address::port()
{
    return port_;
}

void Address::address(const std::string &address)
{
    // judge the address string is a valid ipv4 string
    if(!util::IsIpv4(address))
    {
        isNotAddress();
    }
    address_ = address;
}

std::string Address::address()
{
    return address_;
}

const std::string Address::address() const
{
    return address_;
}

const int Address::port() const
{
    return port_;
}
