macro(add_leetcode_target target solution_class)
    add_executable(${target} ${TEST_CPP_FILE}) # see test/CMakeLists.txt
    target_link_libraries(${target} PRIVATE leetcode_test)

    target_include_directories(${target} PRIVATE ${CMAKE_CURRENT_LIST_DIR})
    target_compile_definitions(${target} PRIVATE -DSOLUTION_CLASS=${solution_class})
endmacro()

add_subdirectory(1-two-sum)
add_subdirectory(4-median-of-two-sorted-arrays)
add_subdirectory(10-regular-expression-matching)
add_subdirectory(13-roman-to-integer)
add_subdirectory(72-edit-distance)
