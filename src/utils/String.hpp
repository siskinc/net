//
// Created by siskinc on 18-4-3.
//

#ifndef NET_STRING_HPP
#define NET_STRING_HPP

#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <lexical_cast.hpp>

class String
{
public:
    static inline std::string Upper(std::string str);

    static inline std::string Lower(std::string str);

    static inline bool isDigit(const char &c);

    static inline bool isDigits(const std::string &str);

    static inline bool isHexDigit(const char &c);

    static inline bool isHexDigits(const std::string &str);

    static inline bool isOctDigit(const char &c);

    static inline bool isOctDigit(const std::string &str);

    static inline void SplitWhitespace(std::vector<std::string> &result, const std::string &str);

    static inline void
    Split(std::vector<std::string> &result, const std::string &str, const std::string &delimiter = "");

    static inline std::string RTrim(std::string str);

    static inline std::string LTrim(std::string str);

    static inline std::string Trim(std::string str);


    // 以下来自于lhmouse的poseidon
    // https://github.com/lhmouse/poseidon/blob/master/src/string.hpp
    template<typename T>
    static inline std::vector<T> explode(char separator, const std::string &str, std::size_t limit = 0)
    {
        std::vector<T> ret;
        if (!str.empty())
        {
            std::size_t begin = 0, end;
            std::string temp;
            for (;;)
            {
                if (ret.size() == limit - 1)
                {
                    end = std::string::npos;
                } else
                {
                    end = str.find(separator, begin);
                }
                if (end == std::string::npos)
                {
                    temp.assign(str, begin, std::string::npos);
                    ret.push_back(boost::lexical_cast<T>(temp));
                    break;
                }
                temp.assign(str, begin, end - begin);
                ret.push_back(boost::lexical_cast<T>(temp));
                begin = end + 1;
            }
        }
        return ret;
    }


};

template<>
inline std::vector<std::string> String::explode(char separator, const std::string &str, std::size_t limit)
{
    std::vector<std::string> ret;
    if (!str.empty())
    {
        std::size_t begin = 0, end;
        std::string temp;
        for (;;)
        {
            if (ret.size() == limit - 1)
            {
                end = std::string::npos;
            } else
            {
                end = str.find(separator, begin);
            }
            if (end == std::string::npos)
            {
                temp.assign(str, begin, std::string::npos);
                ret.push_back(std::move(temp));
                break;
            }
            temp.assign(str, begin, end - begin);
            ret.push_back(std::move(temp));
            begin = end + 1;
        }
    }
    return ret;
}


#endif //NET_STRING_HPP
