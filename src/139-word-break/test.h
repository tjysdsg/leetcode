#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<string> dict{"leet", "code"};
    EXPECT_EQ(sol.wordBreak("leetcode", dict), true);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<string> dict{"apple", "pen"};
    EXPECT_EQ(sol.wordBreak("applepenapple", dict), true);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<string> dict{"cats", "dog", "sand", "and", "cat"};
    EXPECT_EQ(sol.wordBreak("catsandog", dict), false);
    EXPECT_EQ(sol.wordBreak("catsanddog", dict), true);
}
