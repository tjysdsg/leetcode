#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    vector<int> v1{1, 2};
    vector<int> v2{3, 4, 5, 6};
    vector<int> ans{1, 3, 2, 4, 5, 6};

    SOLUTION_CLASS sol(v1, v2);
    vector<int> res{};
    while (sol.hasNext())
        res.push_back(sol.next());

    EXPECT_EQ(res, ans);
}

TEST(test, 2) {
    vector<int> v1{1};
    vector<int> v2{};
    vector<int> ans{1};

    SOLUTION_CLASS sol(v1, v2);
    vector<int> res{};
    while (sol.hasNext())
        res.push_back(sol.next());

    EXPECT_EQ(res, ans);
}

TEST(test, 3) {
    vector<int> v1{};
    vector<int> v2{1};
    vector<int> ans{1};

    SOLUTION_CLASS sol(v1, v2);
    vector<int> res{};
    while (sol.hasNext())
        res.push_back(sol.next());

    EXPECT_EQ(res, ans);
}

TEST(test, 4) {
    vector<int> v1{1, 2, 3};
    vector<int> v2{4, 5, 6, 7};
    vector<int> v3{8, 9};
    vector<int> ans{1, 4, 8, 2, 5, 9, 3, 6, 7};

    SOLUTION_CLASS sol(v1, v2, v3);
    vector<int> res{};
    while (sol.hasNext())
        res.push_back(sol.next());

    EXPECT_EQ(res, ans);
}
