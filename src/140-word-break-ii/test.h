#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<string> dict{"cat", "cats", "and", "sand", "dog"};
    vector<string> ans{"cats and dog", "cat sand dog"};
    EXPECT_THAT(sol.wordBreak("catsanddog", dict), UnorderedElementsAreArray(ans));
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<string> dict{"apple", "pen", "applepen", "pine", "pineapple"};
    vector<string> ans{"pine apple pen apple", "pineapple pen apple", "pine applepen apple"};
    EXPECT_THAT(sol.wordBreak("pineapplepenapple", dict), UnorderedElementsAreArray(ans));
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<string> dict{"cats", "dog", "sand", "and", "cat"};
    vector<string> ans{};
    EXPECT_EQ(sol.wordBreak("catsandog", dict), ans);
}
