#ifndef PRINT_IP_IS_STL_CONTAINER_H
#define PRINT_IP_IS_STL_CONTAINER_H

#include <type_traits>

#include <array>
#include <vector>
#include <deque>
#include <forward_list>
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

//template<typename T>
//struct is_stl_container;

template<typename T, typename U = int, typename V = int, size_t size = 0, typename ...Args>
struct is_stl_container {
    static constexpr bool value = is_one_of<T,
                            std::array<U,size>,
                            std::vector<U>,
                            std::deque<U>,
                            std::forward_list<U>,
                            std::set<U>,
                            std::map<U,V>,
                            std::unordered_set<U>,
                            std::unordered_map<U,V>>::value;
};


#endif //PRINT_IP_IS_STL_CONTAINER_H
