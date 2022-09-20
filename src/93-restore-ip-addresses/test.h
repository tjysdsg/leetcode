#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    auto res = sol.restoreIpAddresses("25525511135");
    vector<string> ans = {
            "255.255.11.135", "255.255.111.35"
    };
    EXPECT_THAT(res, UnorderedElementsAreArray(ans));
}

TEST(test, 2) {
    SOLUTION_CLASS sol;
    auto res = sol.restoreIpAddresses("0000");
    vector<string> ans = {
            "0.0.0.0"
    };
    EXPECT_THAT(res, UnorderedElementsAreArray(ans));
}

TEST(test, 3) {
    SOLUTION_CLASS sol;
    auto res = sol.restoreIpAddresses("101023");
    vector<string> ans = {
            "1.0.10.23", "1.0.102.3", "10.1.0.23", "10.10.2.3", "101.0.2.3"
    };
    EXPECT_THAT(res, UnorderedElementsAreArray(ans));
}
