#ifndef PRINT_IP_PRINT_IP_H
#define PRINT_IP_PRINT_IP_H

#include <iostream>
#include <type_traits>

#include "is_stl_container.h"

template<typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type>
void print_ip(T ip) {
    unsigned int size = sizeof(T) - 1;
    auto char_pointer = reinterpret_cast<unsigned char const*>(&ip);

    uint16_t x = 0x0001;
    if(*((uint8_t *) &x) != 0) {
        // little-endian
        for(int i = size; i >= 0; --i) {
            std::cout << (int)*(char_pointer + i);
            if(i>0)
                std::cout << ".";
        }
    }
    else {
        // big-endian
        for(int i = 0; i <= size; ++i) {
            std::cout << (int)*(char_pointer + i);
            if(i<size)
                std::cout << ".";
        }
    }

}

template <typename T>
void print_ip(T ip, typename std::enable_if<is_stl_container<T>::value, T>::type* = nullptr) {
    for(auto item = std::begin(ip); item != std::end(ip); ++item) {
        std::cout << *item;
        if(item != std::prev(std::end(ip))) {
            std::cout << ".";
        }
        else {
//            std::cout << std::endl;
        }
    }
}

void print_ip(std::string ip) {
    std::cout << ip;
//    << std::endl;
}


#endif //PRINT_IP_PRINT_IP_H
