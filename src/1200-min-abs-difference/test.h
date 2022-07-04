#pragma once

#include "sol.hpp"
#include <gtest/gtest.h>
#include <algorithm>

TEST(test, 1) {
    SOLUTION_CLASS sol;
    vector<int> v{4, 2, 1, 3};
    auto res = sol.minimumAbsDifference(v);
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    vector<int> v{1, 3, 6, 10, 15};
    auto res = sol.minimumAbsDifference(v);
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    vector<int> v{3, 8, -10, 23, 19, -4, -14, 27};
    auto res = sol.minimumAbsDifference(v);
}
