//
// Created by siskinc on 18-4-11.
//

#include "Json.hpp"

namespace parser {

static const int max_depth = 200;

/* Helper for representing null - just a do-nothing struct, plus comparison
 * operators so the helpers in JsonValue work. We can't use nullptr_t because
 * it may not be orderable.
 */
struct NullStruct
{
    bool operator==(NullStruct) const { return true; }

    bool operator<(NullStruct) const { return false; }
};

/* * * * * * * * * * * * * * * * * * * *
* Serialization
*/

static void dump(NullStruct, std::string &out)
{
    out += "null";
}

static void dump(double value, std::string &out)
{
    if (std::isfinite(value))
    {
        out += std::to_string(value);
    } else
    {
        out += "null";
    }
}

static void dump(int value, std::string &out)
{
    out += std::to_string(value);
}

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

}