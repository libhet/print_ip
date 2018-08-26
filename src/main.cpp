#include <iostream>

#include "is_stl_container.h"
#include "print_ip.h"

#include <stdio.h>

#include <cmath>

int main() {
    try
    {
        print_ip(char(-1));
        std::cout << std::endl;
        print_ip(short(0));
        std::cout << std::endl;
        print_ip(2130706433);
        std::cout << std::endl;
        print_ip((long long)(8875824491850138409));
        std::cout << std::endl;
        print_ip("156.18.123.11");
        std::cout << std::endl;
        print_ip(std::list<int>{17, 81, 65, 42});
        std::cout << std::endl;
        print_ip(std::vector<int>{117, 161, 24, 42});
        std::cout << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}