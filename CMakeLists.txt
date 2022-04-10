cmake_minimum_required(VERSION 3.21)
project(leetcode)

set(CMAKE_CXX_STANDARD 11)

# testing
add_subdirectory(${PROJECT_SOURCE_DIR}/dep/googletest)
add_subdirectory(test)

add_subdirectory(13-roman-to-integer)
