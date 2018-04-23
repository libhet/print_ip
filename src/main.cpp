#include <iostream>

#include "is_stl_container.h"
#include "print_ip.h"


#include <cmath>

int main() {
//    const int a = 2130706433;
//    int const * int_pointer = &a;
//    auto char_pointer = reinterpret_cast<unsigned char const*>(int_pointer);
//
////    unsigned char byte[4] = reinterpret_cast<unsigned char*>(static_cast<unsigned char>(a));
//    for(int i = sizeof(decltype(a))-1; i >= 0; --i) {
//        std::cout << (int)*(char_pointer + i) << std::endl;
//    }
//    print_ip((uint32_t)pow(2,16)-1);
//

//    std::cout << is_stl_container<std::set<int>>::value << std::endl;
    print_ip(-1);
    print_ip(std::set<int> {4,2,3,1});
    print_ip("465");

    return 0;
}