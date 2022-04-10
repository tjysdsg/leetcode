add_library(leetcode_test empty.cpp)
target_link_libraries(leetcode_test PUBLIC gtest)
target_compile_options(leetcode_test PUBLIC -O1)

set(TEST_CPP_FILE ${CMAKE_CURRENT_LIST_DIR}/test.cpp CACHE PATH "Path to the main test file" FORCE)
