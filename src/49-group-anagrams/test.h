#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<string> v{"eat", "tea", "tan", "ate", "nat", "bat"};
    auto res = sol.groupAnagrams(v);
    vector<vector<string>> ans = {{"bat"},
                                  {"nat", "tan"},
                                  {"ate", "eat", "tea"}};
    // FIXME: arbitrary order
    // EXPECT_THAT(res, UnorderedElementsAreArray(ans));
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<string> v{""};
    auto res = sol.groupAnagrams(v);
    vector<vector<string>> ans = {{""}};
    EXPECT_THAT(res, UnorderedElementsAreArray(ans));
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<string> v{"a"};
    auto res = sol.groupAnagrams(v);
    vector<vector<string>> ans = {{"a"}};
    EXPECT_THAT(res, UnorderedElementsAreArray(ans));
}
