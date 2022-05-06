// https://leetcode-cn.com/problems/edit-distance/

#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using std::string;
using std::cout;
using std::vector;

class Solution {
 public:
  int majorityElement(vector<int> &nums) {
    int count = 0, ret = 0;
    for (int num: nums) {
      if (count == 0) {
        ret = num;
        count++;
      } else if (ret == num)
        count++;
      else
        count--;
    }
    return ret;
  }
};
