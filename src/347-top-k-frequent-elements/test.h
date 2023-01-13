#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 1, 1, 2, 2, 3};
    vector<int> ans{1, 2};
    EXPECT_THAT(sol.topKFrequent(v, 2), UnorderedElementsAreArray(ans));
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{1};
    vector<int> ans{1};
    EXPECT_THAT(sol.topKFrequent(v, 1), UnorderedElementsAreArray(ans));
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 1, 1, 2, 3, 4, 5, 5, 5};
    vector<int> ans{1, 5};
    EXPECT_THAT(sol.topKFrequent(v, 2), UnorderedElementsAreArray(ans));
}
