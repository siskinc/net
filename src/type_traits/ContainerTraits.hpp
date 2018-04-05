//
// Created by siskinc on 18-4-5.
//

#ifndef NET_CONTAINERTRAITS_HPP
#define NET_CONTAINERTRAITS_HPP

#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <unordered_set>
#include <unordered_map>
#include <type_traits>

template <typename T> struct container_traits {
    static bool const value = false;
};

template <typename... Args>
struct container_traits<std::vector<Args...>> {
static bool const value = true;
};

template <typename... Args>
struct container_traits<std::deque<Args...>> {
static bool const value = true;
};

template <typename... Args>
struct container_traits<std::list<Args...>> {
static bool const value = true;
};

template <typename... Args>
struct container_traits<std::set<Args...>> {
static bool const value = true;
};

template <typename... Args>
struct container_traits<std::map<Args...>> {
static bool const value = true;
};

template <typename... Args>
struct container_traits<std::unordered_set<Args...>> {
static bool const value = true;
};

template <typename... Args>
struct container_traits<std::unordered_map<Args...>> {
static bool const value = true;
};

template<typename T>
struct is_std {
    static constexpr bool const value = container_traits<T>::value;
};


#endif //NET_CONTAINERTRAITS_HPP
