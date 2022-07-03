#pragma once

#include "sol.hpp"
#include <gtest/gtest.h>
#include <algorithm>

TEST(test, 1) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.nextGreaterElement(12), 21);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.nextGreaterElement(21), -1);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.nextGreaterElement(132569849), 132569894);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.nextGreaterElement(101), 110);
}

TEST(test, 5) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.nextGreaterElement(230241), 230412);
}

TEST(test, 6) {
    SOLUTION_CLASS sol;
    EXPECT_EQ(sol.nextGreaterElement(2147483486), -1);
}
