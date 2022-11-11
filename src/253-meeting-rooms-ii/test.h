#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 0) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{13, 15},
                          {1,  13}};
    EXPECT_EQ(sol.minMeetingRooms(v), 1);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{0,  30},
                          {5,  10},
                          {15, 20}};
    EXPECT_EQ(sol.minMeetingRooms(v), 2);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{7, 10},
                          {2, 4}};
    EXPECT_EQ(sol.minMeetingRooms(v), 1);
}
