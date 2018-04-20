#ifndef PRINT_IP_PRINT_IP_H
#define PRINT_IP_PRINT_IP_H

#include <iostream>
#include <type_traits>

template<typename T, typename = typename std::enable_if<std::is_integral<T>::value, T>::type>
void print_ip(T ip) {
    unsigned int size = sizeof(T) - 1;
    auto char_pointer = reinterpret_cast<unsigned char const*>(&ip);

    for(int i = size; i >= 0; --i) {
        std::cout << (int)*(char_pointer + i);
        (i>0)?std::cout << ".":std::cout << std::endl;
    }
}




//template<typename T>
//void print_ip(T ip) {
//
//}


#endif //PRINT_IP_PRINT_IP_H
