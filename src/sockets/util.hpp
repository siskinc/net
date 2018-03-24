//
// Created by siskinc on 18-3-23.
//

#ifndef NET_UTIL_HPP
#define NET_UTIL_HPP

#include <cstring>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <exception>
#include <vector>
#include <iostream>

#include <boost/algorithm/string.hpp>
#include <boost/lexical_cast.hpp>
#include "Common.hpp"


class util
{
public:
    typedef std::vector<std::string> split_vector_string_type;


    // 将ipv4地址字符串按"."分割
    // 按照ipv4地址的要求，每一段都是数字，并且在0～255之间判定
    inline static bool IsIpv4(const std::string &address)
    {
        split_vector_string_type split_strings;
        boost::algorithm::split(split_strings, address, boost::algorithm::is_any_of("\\."),
                                boost::algorithm::token_compress_on);
        if (split_strings.size() != 4)
        {
            return false;
        }

        // 用来暂时保存每一段地址
        int t = 0;

        for (auto &i : split_strings)
        {
            // 如果不是数字
            if (!IsNum(i))
            {
                return false;
            }

            // 是数字，但不在0~255之间
            t = boost::lexical_cast<int>(i);
            if (t < 0 || t > 255)
            {
                return false;
            }
        }

        return true;
    }

    // judge the string is a number
    inline static bool IsNum(const std::string &num)
    {
        auto len = num.length();
        if (len == 0)
            return false;
        for (int i = 0; i < len; ++i)
        {
            if (std::isdigit(num[i]) == 0)
            {
                return false;
            }
        }
        return true;
    }

    // set socket file discreption be non-blocking
    inline static bool SetSocketNonBlocking(file_description fd)
    {
        if(fd < 0)
            return false;
        int flag = fcntl(fd, F_GETFL, 0);
        if (flag == -1)
            return false;
        flag = flag | O_NONBLOCK;
        return (fcntl(fd, F_SETFL, flag) == 0) ? true : false;
    }
};


#endif //NET_UTIL_HPP
