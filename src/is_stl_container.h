#ifndef PRINT_IP_IS_STL_CONTAINER_H
#define PRINT_IP_IS_STL_CONTAINER_H

#include <type_traits>

#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

template <typename T, typename ...Args>
struct is_one_of;

template <typename T>
struct is_one_of<T> : std::false_type {};

template <typename T, typename ...Args>
struct is_one_of<T, T, Args...> : std::true_type {};

template <typename T, typename U, typename ...Args>
struct is_one_of<T, U, Args...> : is_one_of<T, Args...> {};


template<typename T>
struct is_stl_container {
static constexpr bool value = false;
};

template<template<typename...> class U, typename T, typename... Args>
struct is_stl_container<U<T,Args...>> {
    static constexpr bool value =
            is_one_of<
            U<T>,
            std::vector<T>,
            std::deque<T>,
            std::forward_list<T>,
            std::list<T>,
            std::set<T>,
            std::unordered_set<T>
    >::value;
};

template <typename T, size_t size>
struct is_stl_container<std::array<T,size>> {
    static constexpr bool value = true;
};

template <typename T, typename U>
struct is_stl_container<std::unordered_map<T,U>> {
    static constexpr bool value = true;
};

template <typename T, typename U>
struct is_stl_container<std::map<T,U>> {
    static constexpr bool value = true;
};

//            std::map<Args...>,
#endif //PRINT_IP_IS_STL_CONTAINER_H
