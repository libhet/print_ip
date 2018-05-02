#define BOOST_TEST_MODULE TEST_PRINT_IP
#include <boost/test/unit_test.hpp>
#include <boost/test/output_test_stream.hpp>

#include "../src/print_ip.h"
#include "../src/is_stl_container.h"

struct cout_redirect {
    cout_redirect( std::streambuf * new_buffer )
            : old( std::cout.rdbuf( new_buffer ) )
    { }

    ~cout_redirect( ) {
        std::cout.rdbuf( old );
    }

private:
    std::streambuf * old;
};

BOOST_AUTO_TEST_SUITE(is_stl_container_test)

    BOOST_AUTO_TEST_CASE(vector) {
        BOOST_CHECK(is_stl_container<std::vector<int>>::value == true);
        BOOST_CHECK(is_stl_container<std::vector<char>>::value == true);
        BOOST_CHECK(is_stl_container<std::vector<float>>::value == true);
        BOOST_CHECK(is_stl_container<std::vector<std::string>>::value == true);
    }
    BOOST_AUTO_TEST_CASE(list) {
        BOOST_CHECK(is_stl_container<std::list<int>>::value == true);
        BOOST_CHECK(is_stl_container<std::list<char>>::value == true);
        BOOST_CHECK(is_stl_container<std::list<float>>::value == true);
        BOOST_CHECK(is_stl_container<std::list<std::string>>::value == true);
    }
    BOOST_AUTO_TEST_CASE(forward_list) {
        BOOST_CHECK(is_stl_container<std::forward_list<int>>::value == true);
        BOOST_CHECK(is_stl_container<std::forward_list<char>>::value == true);
        BOOST_CHECK(is_stl_container<std::forward_list<float>>::value == true);
        BOOST_CHECK(is_stl_container<std::forward_list<std::string>>::value == true);
    }
    BOOST_AUTO_TEST_CASE(deque) {
        BOOST_CHECK(is_stl_container<std::deque<int>>::value == true);
        BOOST_CHECK(is_stl_container<std::deque<char>>::value == true);
        BOOST_CHECK(is_stl_container<std::deque<float>>::value == true);
        BOOST_CHECK(is_stl_container<std::deque<std::string>>::value == true);
    }
    BOOST_AUTO_TEST_CASE(set) {
        BOOST_CHECK(is_stl_container<std::set<int>>::value == true);
        BOOST_CHECK(is_stl_container<std::set<char>>::value == true);
        BOOST_CHECK(is_stl_container<std::set<float>>::value == true);
        BOOST_CHECK(is_stl_container<std::set<std::string>>::value == true);
    }
    BOOST_AUTO_TEST_CASE(unordered_set) {
        BOOST_CHECK(is_stl_container<std::unordered_set<int>>::value == true);
        BOOST_CHECK(is_stl_container<std::unordered_set<char>>::value == true);
        BOOST_CHECK(is_stl_container<std::unordered_set<float>>::value == true);
        BOOST_CHECK(is_stl_container<std::unordered_set<std::string>>::value == true);
    }

    BOOST_AUTO_TEST_CASE(not_container) {
        BOOST_CHECK(is_stl_container<int>::value == false);
        BOOST_CHECK(is_stl_container<float>::value == false);
        BOOST_CHECK(is_stl_container<char>::value == false);
        BOOST_CHECK(is_stl_container<std::string>::value == false);
    }

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(PrintIP_Test)

    BOOST_AUTO_TEST_CASE(PrintIP_OutputCheck) {

        boost::test_tools::output_test_stream output;
        {
            cout_redirect guard(output.rdbuf());

            print_ip(char(-1));
            print_ip(short(0));
            print_ip(2130706433);
            print_ip(static_cast<long>(8875824491850138409));

            BOOST_CHECK(output.is_equal("255\n"
                                                "0.0\n"
                                                "127.0.0.1\n"
                                                "123.45.67.89.101.112.131.41"));
        }
    }

    BOOST_AUTO_TEST_CASE(PrintIP_List) {
        boost::test_tools::output_test_stream output;
        {
            cout_redirect guard(output.rdbuf());
            std::list<int> ip = {156,210,13,49};
            print_ip(ip);

            BOOST_CHECK(output.is_equal("156.210.13.49\n"));
        }
    }

    BOOST_AUTO_TEST_CASE(PrintIP_vector) {
        boost::test_tools::output_test_stream output;
        {
            cout_redirect guard(output.rdbuf());
            std::vector<int> ip = {234,123,23,17};
            print_ip(ip);

            BOOST_CHECK(output.is_equal("234.123.23.17\n"));
        }
    }

BOOST_AUTO_TEST_SUITE_END()
