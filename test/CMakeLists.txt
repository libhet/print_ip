#if(BUILD_TESTING)

find_package(Boost COMPONENTS unit_test_framework REQUIRED)

add_executable(
            test_print_ip
            test_print_ip.cpp
)

set_target_properties(test_print_ip PROPERTIES
            CXX_STANDARD 14
            CXX_STANDARD_REQUIRED ON
            COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
            INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIRS}
)

target_link_libraries(test_print_ip ${Boost_LIBRARIES})

add_test(TEST_PRINT_IP test_print_ip --list_content)
#endif()
