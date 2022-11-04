#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 0) {
    SOLUTION_CLASS sol;
    vector<vector<Interval>> v{{{7, 24}, {29, 33}, {45, 57}, {66, 69}, {94, 99}},
                               {{6, 24}, {43, 49}, {56, 59}, {61, 75}, {80, 81}},
                               {{5, 16}, {18, 26}, {33, 36}, {39, 57}, {65, 74}},
                               {{9, 16}, {27, 35}, {40, 55}, {68, 71}, {78, 81}},
                               {{0, 25}, {29, 31}, {40, 47}, {57, 87}, {91, 94}}};
    auto res = sol.employeeFreeTime(v);
    EXPECT_EQ(res.size(), 3);
    EXPECT_EQ(res[0].start, 26);
    EXPECT_EQ(res[0].end, 27);
    EXPECT_EQ(res[1].start, 36);
    EXPECT_EQ(res[1].end, 39);
    EXPECT_EQ(res[2].start, 87);
    EXPECT_EQ(res[2].end, 91);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<Interval>> v{{{1, 2}, {5, 6}},
                               {{1, 3}},
                               {{4, 10}}};
    auto res = sol.employeeFreeTime(v);
    EXPECT_EQ(res.size(), 1);
    EXPECT_EQ(res[0].start, 3);
    EXPECT_EQ(res[0].end, 4);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<Interval>> v{{{1, 3}, {6, 7}},
                               {{2, 4}},
                               {{2, 5}, {9, 12}}};
    auto res = sol.employeeFreeTime(v);
    EXPECT_EQ(res.size(), 2);
    EXPECT_EQ(res[0].start, 5);
    EXPECT_EQ(res[0].end, 6);
    EXPECT_EQ(res[1].start, 7);
    EXPECT_EQ(res[1].end, 9);
}
