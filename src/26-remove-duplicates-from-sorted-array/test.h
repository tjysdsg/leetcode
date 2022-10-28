#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

void check_ans(int size, vector<int> res, vector<int> ans) {
    EXPECT_EQ(size, ans.size());
    for (int i = 0; i < ans.size(); i++) {
        EXPECT_EQ(res[i], ans[i]);
    }
}

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 1, 2};
    vector<int> ans{1, 2};
    check_ans(sol.removeDuplicates(v), v, ans);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    vector<int> ans{0, 1, 2, 3, 4};
    check_ans(sol.removeDuplicates(v), v, ans);
}
