#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 0) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1,  4},
                          {9,  12},
                          {19, 22}};
    vector<int> new_interval{7, 13};
    vector<vector<int>> ans{{1,  4},
                            {7,  13},
                            {19, 22}};
    EXPECT_EQ(sol.insert(v, new_interval), ans);
}


TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 3},
                          {6, 9}};
    vector<int> new_interval{2, 5};
    vector<vector<int>> ans{{1, 5},
                            {6, 9}};
    EXPECT_EQ(sol.insert(v, new_interval), ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1,  2},
                          {3,  5},
                          {6,  7},
                          {8,  10},
                          {12, 16}};
    vector<int> new_interval{4, 8};
    vector<vector<int>> ans{{1,  2},
                            {3,  10},
                            {12, 16}};
    EXPECT_EQ(sol.insert(v, new_interval), ans);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{};
    vector<int> new_interval{5, 7};
    vector<vector<int>> ans{{5, 7}};
    EXPECT_EQ(sol.insert(v, new_interval), ans);
}

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 5}};
    vector<int> new_interval{6, 8};
    vector<vector<int>> ans{{1, 5},
                            {6, 8}};
    EXPECT_EQ(sol.insert(v, new_interval), ans);
}

TEST(test, 5) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1, 5}};
    vector<int> new_interval{0, 0};
    vector<vector<int>> ans{{0, 0},
                            {1, 5}};
    EXPECT_EQ(sol.insert(v, new_interval), ans);
}

TEST(test, 6) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{0, 1},
                          {2, 6},
                          {9, 11}};
    vector<int> new_interval{5, 10};
    vector<vector<int>> ans{{0, 1},
                            {2, 11}};
    EXPECT_EQ(sol.insert(v, new_interval), ans);
}

