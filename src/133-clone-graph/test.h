#pragma once

#include "sol.hpp"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <algorithm>

using namespace ::testing;

TEST(test, 1) {
    SOLUTION_CLASS sol;
    auto *n1 = new Node(1);
    auto *n2 = new Node(2);
    auto *n3 = new Node(3);
    auto *n4 = new Node(4);

    n1->neighbors.push_back(n2);
    n1->neighbors.push_back(n4);

    n2->neighbors.push_back(n1);
    n2->neighbors.push_back(n3);

    n3->neighbors.push_back(n2);
    n3->neighbors.push_back(n4);

    n4->neighbors.push_back(n1);
    n4->neighbors.push_back(n3);

    Node *res = sol.cloneGraph(n1);
    EXPECT_NE(res, n1);
    EXPECT_EQ(res->val, n1->val);

    // lazy...
}
