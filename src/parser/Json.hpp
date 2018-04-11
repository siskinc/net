//
// Created by siskinc on 18-4-11.
//

#ifndef NET_JSON_HPP
#define NET_JSON_HPP

#include <string>
#include <vector>
#include <map>
#include <memory>
#include <initializer_list>
#include <cmath>

#include "Serialize.hpp"

namespace parser {

// This file is come from https://github.com/dropbox/json11/blob/master/json11.hpp
// Almost consistent

enum JsonParse
{
    STANDARD, COMMENTS
};

class JsonValue;

class Json final : public Serialize
{
public:
    enum Type
    {
        NUL,
        INTEGER,
        DOUBLE,
        BOOL,
        STRING,
        ARRAY,
        OBJECT
    };

    // Array and object typedefs
    typedef std::vector<Json> array;
    typedef std::map<std::string, Json> object;

    // Constructors for the various types of JSON value.
    Json() noexcept;                // NUL
    Json(std::nullptr_t) noexcept;  // NUL
    Json(double value);             // INTEGER
    Json(int value);                // DOUBLE
    Json(bool value);               // BOOL
    Json(const std::string &value); // STRING
    Json(std::string &&value);      // STRING
    Json(const char *value);       // STRING
    Json(const array &values);      // ARRAY
    Json(array &&values);           // ARRAY
    Json(const object &values);     // OBJECT
    Json(object &&values);          // OBJECT

    // Implicit constructor: anything with a ToJson() function.
    template<class T, class = decltype(&T::ToJson)>
    explicit Json(const T &t) : Json(t.ToJson()) {}

    // Implicit constructor: map-like objects (std::map, std::unordered_map, etc)
    template<class M, typename std::enable_if<
            std::is_constructible<std::string, decltype(std::declval<M>().begin()->first)>::value
            && std::is_constructible<Json, decltype(std::declval<M>().begin().second)>::value, int>::type = 0>
    Json(const M &m) : Json(object(m.begin(), m.end())) {}

    // Implicit constructor: vector-like objects (std::list, std::vector, std::set, etc)
    template<class V, typename std::enable_if<
            std::is_constructible<Json, decltype(*std::declval<V>().begin())>::value,
            int>::type = 0>
    Json(const V &v) : Json(array(v.begin(), v.end())) {}

    Json(void *) = delete;

    // Accessors
    Type type() const;

    bool IsNull() const;

    bool IsInteger() const;

    bool IsDouble() const;

    bool IsBool() const;

    bool IsString() const;

    bool IsArray() const;

    bool IsObject() const;

    double GetDoubleValue() const;

    int GetIntegerValue() const;

    bool GetBoolValue() const;

    const std::string &GetStringValue() const;

    const array &GetArrayItems() const;

    const object &GetObjectItems() const;

    // Return a reference to arr[i] if this is an array, Json() otherwise.
    const Json &operator[](size_t i) const;

    // Return a reference to obj[key] if this is an object, Json() otherwise.
    const Json &operator[](const std::string &key) const;

    // Serialize
    void dump(std::string &out) const;

    inline std::string dump() const override
    {
        std::string out;
        dump(out);
        return out;
    }

    // Parse. If parse fails, throw an exception.

    static inline Json Parse(const std::string &in,
                             JsonParse strategy = JsonParse::STANDARD);

    static inline Json Parse(const char *in,
                             JsonParse strategy = JsonParse::STANDARD);

    // Parse multiple objects, concatenated or separated by whitespace
    static std::vector<Json> ParseMulti(
            const std::string &in,
            std::string::size_type &parser_stop_pos,
            JsonParse strategy = JsonParse::STANDARD);

    static inline std::vector<Json> parse_multi(
            const std::string &in,
            std::string &err,
            JsonParse strategy = JsonParse::STANDARD)
    {
        std::string::size_type parser_stop_pos;
        return ParseMulti(in, parser_stop_pos, strategy);
    }

    bool operator==(const Json &rhs) const;

    bool operator<(const Json &rhs) const;

    bool operator!=(const Json &rhs) const { return !(*this == rhs); }

    bool operator<=(const Json &rhs) const { return !(rhs < *this); }

    bool operator>(const Json &rhs) const { return (rhs < *this); }

    bool operator>=(const Json &rhs) const { return !(*this < rhs); }

    /* HasShape(types)
     *
     * Return true if this is a JSON object and, for each item in types, has a field of
     * the given type. If not, return false and set err to a descriptive message.
     */
    typedef std::initializer_list<std::pair<std::string, Type>> shape;

    bool HasShape(const shape &types) const;

private:
    std::shared_ptr<JsonValue> m_ptr;

};

// Internal class hierarchy - JsonValue objects are not exposed to users of this API.
class JsonValue
{
protected:
    friend class Json;

    friend class JsonInt;

    friend class JsonDouble;

    virtual Json::Type type() const = 0;

    virtual bool equals(const JsonValue *other) const = 0;

    virtual bool less(const JsonValue *other) const = 0;

    virtual void dump(std::string &out) const = 0;

    virtual double DoubleValue() const;

    virtual int IntegerValue() const;

    virtual bool BoolValue() const;

    virtual const std::string &StringValue() const;

    virtual const Json::array &ArrayItems() const;

    virtual const Json &operator[](size_t i) const;

    virtual const Json::object &ObjectItems() const;

    virtual const Json &operator[](const std::string &key) const;

    virtual ~JsonValue() {}
};


}

#endif //NET_JSON_HPP
