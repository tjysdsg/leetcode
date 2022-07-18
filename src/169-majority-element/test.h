#pragma once

#include "sol.hpp"
#include <gtest/gtest.h>
#include <algorithm>

SOLUTION_CLASS sol;

TEST(majority_element, 1) {
    vector<int> v{3, 2, 3};
    int d = sol.majorityElement(v);
    EXPECT_EQ(d, 3);
}

TEST(majority_element, 2) {
    vector<int> v{2, 2, 1, 1, 1, 2, 2};
    int d = sol.majorityElement(v);
    EXPECT_EQ(d, 2);
}

TEST(majority_element, 3) {
    vector<int> v{2, 2, 1, 1, 3, 2, 1, 2, 2};
    int d = sol.majorityElement(v);
    EXPECT_EQ(d, 2);
}
