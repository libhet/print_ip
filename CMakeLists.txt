cmake_minimum_required(VERSION 3.9)
project(print_ip)

IF($ENV{TRAVIS_BUILD_NUMBER})
    project(print_ip VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
ELSE()
    project(print_ip VERSION 0.0.1)
ENDIF()

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_PATH "${PROJECT_SOURCE_DIR}/src")

add_executable(print_ip
        src/main.cpp
        src/print_ip.h
        src/is_stl_container.h
        )

set_target_properties(print_ip PROPERTIES
        CXX_STANDARD 14
        CXX_STANDARD_REQUIRED ON
        COMPILE_OPTIONS -Wpedantic -Wall -Wextra
        )

install(TARGETS print_ip RUNTIME DESTINATION bin)

set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT shadow.balz@mail.ru)

include(CPack)
enable_testing()
add_subdirectory(test)