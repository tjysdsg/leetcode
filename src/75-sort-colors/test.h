#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{2, 0, 2, 1, 1, 0};
    vector<int> ans = v;
    std::sort(ans.begin(), ans.end());
    sol.sortColors(v);
    EXPECT_EQ(v, ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{2, 0, 1};
    vector<int> ans = v;
    std::sort(ans.begin(), ans.end());
    sol.sortColors(v);
    EXPECT_EQ(v, ans);
}
