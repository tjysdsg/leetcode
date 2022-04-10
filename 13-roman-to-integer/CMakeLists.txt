set(target_name 13-roman-to-integer)
add_executable(${target_name} ${TEST_CPP_FILE})
target_link_libraries(${target_name} PRIVATE leetcode_test)

target_include_directories(${target_name} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
