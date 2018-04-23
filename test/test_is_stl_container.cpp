#include <array>
#include <vector>
#include <deque>
#include <forward_list>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>

#include <string>

#include "../src/is_stl_container.h"

static_assert(is_stl_container<std::vector<int>>::value     == true, "vector is not a container?");
static_assert(is_stl_container<std::vector<char>>::value     == true, "vector is not a container?");
static_assert(is_stl_container<std::vector<float>>::value     == true, "vector is not a container?");
static_assert(is_stl_container<std::vector<std::string>>::value     == true, "vector is not a container?");

static_assert(is_stl_container<std::list<int>>::value       == true, "list is not a container?");
static_assert(is_stl_container<std::list<char>>::value       == true, "list is not a container?");
static_assert(is_stl_container<std::list<float>>::value       == true, "list is not a container?");
static_assert(is_stl_container<std::list<std::string>>::value       == true, "list is not a container?");

static_assert(is_stl_container<std::forward_list<int>>::value           == true, "forward_list is not a container?");
static_assert(is_stl_container<std::forward_list<char>>::value          == true, "forward_list is not a container?");
static_assert(is_stl_container<std::forward_list<float>>::value         == true, "forward_list is not a container?");
static_assert(is_stl_container<std::forward_list<std::string>>::value   == true, "forward_list is not a container?");

static_assert(is_stl_container<std::deque<int>>::value          == true, "deque is not a container?");
static_assert(is_stl_container<std::deque<char>>::value         == true, "deque is not a container?");
static_assert(is_stl_container<std::deque<float>>::value        == true, "deque is not a container?");
static_assert(is_stl_container<std::deque<std::string>>::value  == true, "deque is not a container?");

static_assert(is_stl_container<std::set<int>>::value       == true, "set is not a container?");
static_assert(is_stl_container<std::set<char>>::value       == true, "set is not a container?");
static_assert(is_stl_container<std::set<float>>::value       == true, "set is not a container?");
static_assert(is_stl_container<std::set<std::string>>::value       == true, "set is not a container?");

static_assert(is_stl_container<std::unordered_set<int>>::value       == true, "unordered_set is not a container?");
static_assert(is_stl_container<std::unordered_set<char>>::value       == true, "unordered_set is not a container?");
static_assert(is_stl_container<std::unordered_set<float>>::value       == true, "unordered_set is not a container?");
static_assert(is_stl_container<std::unordered_set<std::string>>::value       == true, "unordered_set is not a container?");

static_assert(is_stl_container<std::map<int,int>>::value       == true, "map is not a container?");
static_assert(is_stl_container<std::map<char,char>>::value       == true, "map is not a container?");
static_assert(is_stl_container<std::map<float,float>>::value       == true, "map is not a container?");
static_assert(is_stl_container<std::map<std::string,std::string>>::value       == true, "map is not a container?");

static_assert(is_stl_container<std::unordered_map<int,int>>::value       == true, "unordered_map is not a container?");
static_assert(is_stl_container<std::unordered_map<char,char>>::value       == true, "unordered_map is not a container?");
static_assert(is_stl_container<std::unordered_map<float,float>>::value       == true, "unordered_map is not a container?");
static_assert(is_stl_container<std::unordered_map<std::string,std::string>>::value       == true, "unordered_map is not a container?");

static_assert(is_stl_container<std::array<int,1>>::value       == true, "array is not a container?");
static_assert(is_stl_container<std::array<char,2>>::value       == true, "array is not a container?");
static_assert(is_stl_container<std::array<float,3>>::value       == true, "array is not a container?");
static_assert(is_stl_container<std::array<std::string,4>>::value       == true, "array is not a container?");

static_assert(is_stl_container<int>::value       == false, "int is not a container");
static_assert(is_stl_container<float>::value       == false, "float is not a container");
static_assert(is_stl_container<char>::value       == false, "char is not a container");
static_assert(is_stl_container<std::string>::value       == false, "string is not a container");