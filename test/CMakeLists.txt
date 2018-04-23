#if (BUILD_TESTING)
    set(Boost_USE_STATIC_LIBS ON)
    find_package (Boost COMPONENTS unit_test_framework REQUIRED)


    add_executable(
            test_print_ip
            test_print_ip.cpp
    )

#    add_executable(
#            test_is_stl_container
#            test_is_stl_container.cpp
#    )
INCLUDE_DIRECTORIES(${Boost_INCLUDE_DIR})

    set_target_properties(test_print_ip PROPERTIES
            CXX_STANDARD 14
            CXX_STANDARD_REQUIRED ON
            COMPILE_DEFINITIONS BOOST_TEST_DYN_LINK
#            INCLUDE_DIRECTORIES ${Boost_INCLUDE_DIRS}
#            INCLUDE_DIRECTORIES ${SOURCE_PATH}
#            LINK_LIBRARIES ${Boost_LIBRARIES}
    )

    target_link_libraries(test_print_ip ${Boost_LIBRARIES})

    add_test(BOOST_TEST_Print_ip test_print_ip)
#endif()

#COMPONENTS unit_test_framework REQUIRED
