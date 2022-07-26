#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{
            {10, 10},
            {10, 10},
            {10, 10},
            {10, 10},
            {10, 10},
            {10, 10},
    };
    auto res = sol.kClosest(v, 4);

    vector<vector<int>> ans{
            {10, 10},
            {10, 10},
            {10, 10},
            {10, 10},
    };
    EXPECT_THAT(res, UnorderedElementsAreArray(ans));
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{1,  3},
                          {-2, 2}};
    auto res = sol.kClosest(v, 1);

    vector<vector<int>> ans{{-2, 2}};
    EXPECT_THAT(res, UnorderedElementsAreArray(ans));
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{3,  3},
                          {5,  -1},
                          {-2, 4}};
    auto res = sol.kClosest(v, 2);

    vector<vector<int>> ans{{3,  3},
                            {-2, 4}};
    EXPECT_THAT(res, UnorderedElementsAreArray(ans));
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<vector<int>> v{{-2, 10},
                          {-4, -8},
                          {10, 7},
                          {-4, -7},
    };
    auto res = sol.kClosest(v, 3);

    vector<vector<int>> ans{{-4, -7},
                            {-4, -8},
                            {-2, 10}};
    EXPECT_THAT(res, UnorderedElementsAreArray(ans));
}
