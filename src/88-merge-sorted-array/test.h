#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 4) {
    SOLUTION_CLASS sol;
    vector<int> v1{4, 5, 6, 0, 0, 0};
    vector<int> v2{1, 2, 3};
    sol.merge(v1, 3, v2, 3);

    vector<int> ans{1, 2, 3, 4, 5, 6};
    EXPECT_THAT(v1, ans);
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v1{1, 2, 3, 0, 0, 0};
    vector<int> v2{2, 5, 6};
    sol.merge(v1, 3, v2, 3);

    vector<int> ans{1, 2, 2, 3, 5, 6};
    EXPECT_THAT(v1, ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v1{1};
    vector<int> v2{};
    sol.merge(v1, 1, v2, 0);

    vector<int> ans{1};
    EXPECT_THAT(v1, ans);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v1{0};
    vector<int> v2{1};
    sol.merge(v1, 0, v2, 1);

    vector<int> ans{1};
    EXPECT_THAT(v1, ans);
}
