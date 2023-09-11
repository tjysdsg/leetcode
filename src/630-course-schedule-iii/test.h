#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{100,  200},
                          {200,  1300},
                          {1000, 1250},
                          {2000, 3200}};
    EXPECT_EQ(sol.scheduleCourse(v), 3);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 2}};
    EXPECT_EQ(sol.scheduleCourse(v), 1);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{3, 2},
                          {4, 3}};
    EXPECT_EQ(sol.scheduleCourse(v), 0);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{10, 1},
                          {1,  1}};
    EXPECT_EQ(sol.scheduleCourse(v), 1);
}
