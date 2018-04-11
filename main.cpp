#include <iostream>
#include <boost/thread/thread.hpp>
#include <boost/container/vector.hpp>
#include <boost/function.hpp>

static void dump(const std::string &value, std::string &out)
{
    out += '"';
    auto len = value.length();
    for (std::size_t i = 0; i < len; ++i)
    {
        const char ch = value[i];
        if (ch == '\\')
        {
            out += "\\\\";
        } else if (ch == '"')
        {
            out += "\\\"";
        } else if (ch == '\b')
        {
            out += "\\b";
        } else if (ch == '\f')
        {
            out += "\\f";
        } else if (ch == '\n')
        {
            out += "\\n";
        } else if (ch == '\r')
        {
            out += "\\r";
        } else if (ch == '\t')
        {
            out += "\\t";
        } else if (static_cast<uint8_t>(ch) <= 0x1f)
        {
            char buf[8];
            snprintf(buf, sizeof buf, "\\u%04x", ch);
            out += buf;
        } else if (static_cast<uint8_t>(ch) == 0xe2 && static_cast<uint8_t>(value[i + 1]) == 0x80
                   && static_cast<uint8_t>(value[i + 2]) == 0xa8)
        {
            out += "\\u2028";
            i += 2;
        } else if (static_cast<uint8_t>(ch) == 0xe2 && static_cast<uint8_t>(value[i + 1]) == 0x80
                   && static_cast<uint8_t>(value[i + 2]) == 0xa9)
        {
            out += "\\u2029";
            i += 2;
        } else
        {
            out += ch;
        }
    }
    out += '"';
}

int main(int argc,char** argv)
{
    std::string a = "123\b456\"";
    std::string b;
    dump(a, b);
    std::cout << b << std::endl;
    return 0;
}