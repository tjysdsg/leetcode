macro(add_leetcode_target target solution_class)
    add_executable(${target} ${TEST_CPP_FILE}) # see test/CMakeLists.txt
    target_link_libraries(${target} PRIVATE leetcode_test)

    target_include_directories(${target} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
    target_compile_definitions(${target} PRIVATE -DSOLUTION_CLASS=${solution_class})
endmacro()

add_leetcode_target(1-two-sum-unoptimized Unoptimized)
add_leetcode_target(1-two-sum-optimized Optimized)

